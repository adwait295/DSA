#include<bits/stdc++.h>
using namespace std;

long long solve(vector<int>& bt) {
    sort(bt.begin(), bt.end());
    long long sum = 0, sum1 = 0;
    int size = bt.size();
    for(int i=1;i<size;i++){
      sum1 += bt[i-1];
      sum += sum1;
    } 
    return sum/size;

    // T.C. = O(n log n + n)
    // S.C. = O(1)
}