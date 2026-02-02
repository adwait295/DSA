#include<bits/stdc++.h>
using namespace std;

static bool comp(const pair<int, int> &a, const pair<int, int> &b){
    if(a.second < b.second) return true;
    else if(a.second > b.second) return false;
    else return a.first < b.first;
}

int maxMeetings(vector<int>& start, vector<int>& end){
    int count = 1, lastStart = 0;

    vector<pair<int, int>> meetings;
    for(int i=0;i<start.size();i++) meetings.push_back({start[i], end[i]});
    sort(meetings.begin(), meetings.end(), comp); // O(n log n)

    for(int i=1;i<meetings.size();i++){ // O(n)
        if(meetings[i].first > meetings[lastStart].second){
            count++;
            lastStart = i;
        }
    }

    return count;

    // T.C. = O(n log n + n)
    // S.C. = O(n)
}