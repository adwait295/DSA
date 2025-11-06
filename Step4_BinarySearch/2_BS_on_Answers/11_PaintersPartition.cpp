#include<bits/stdc++.h>
using namespace std;

/*
1. Each painter paints only "contiguous segments of boards".
2. No board can be split between painters.
3. The goal is to minimize the time to paint "all boards".
*/

// Each painter takes B units of time to paint 1 unit of board.

// Return the minimum time required to paint all boards modulo 10000003.

int count(vector<int> &arr, int maxTime){

    int painterCount = 1, time = 0;
    for(int i=0;i<arr.size();i++){
        if(time + arr[i] <= maxTime) time += arr[i];
        else{
            painterCount++;
            time = arr[i];
        }
    }
    return painterCount;
        
}

int paint(int A, int B, vector<int>& C){

    if(A >= C.size()) return *max_element(C.begin(),C.end())*B % 10000003;

    int low = *max_element(C.begin(),C.end());
    int high = accumulate(C.begin(),C.end(),0);

    while(low <= high){
        int mid = (low + high) / 2;
        int painterCount = count(C,mid);
        if(painterCount > A) low = mid + 1;
        else high = mid - 1;
    }

    return low*B % 10000003;
}