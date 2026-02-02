#include<bits/stdc++.h>
using namespace std;

static bool comp(const vector<int> &a , const vector<int> &b){
    if(a[1] < b[1]) return true;
    else if(a[1] > b[1]) return false;
    else return a[0] > b[0];

    // or just return a[1] < b[1];
}

int MaximumNonOverlappingIntervals(vector<vector<int>>& Intervals) {
    int size = Intervals.size();

    sort(Intervals.begin(), Intervals.end(), comp);  

    int count = 0, lastEnd = 0;
    for(int i=1;i<size;i++) {
        if(Intervals[i][0] < Intervals[lastEnd][1]) count++;
        else lastEnd = i;
    }

    return count;
}