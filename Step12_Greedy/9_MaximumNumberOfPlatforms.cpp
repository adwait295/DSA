#include<bits/stdc++.h>
using namespace std;

// Brute force solution: Counting number of overlapping trains for each arriving train. 

int findPlatform(vector<int>& Arrival, vector<int>& Departure){
    int ans = 1, size = Arrival.size();
    for(int i=0;i<size;i++){
        int count = 1;
        for(int j=0;j<size;j++){
            if(i != j) {
                if(Arrival[i] >= Arrival[j] && Arrival[i] <= Departure[j]) count++;
            }
        }
        ans = max(ans, count);
    }
    return ans;
}

// Alternative way to write the same thing:
int findPlatform(vector<int>& Arrival, vector<int>& Departure){
    int ans = 1, size = Arrival.size();
    for(int i=0;i<size;i++){
        int count = 0;
        for(int j=0;j<size;j++){
            if(Arrival[i] >= Arrival[j] && Arrival[i] <= Departure[j]) count++;
        }
        ans = max(ans, count);
    }
    return ans;

    // T.C. = O(n^2)
    // S.C. = O(1)
}

// Optimal solution:

int findPlatform1(vector<int>& Arrival, vector<int>& Departure){
    sort(Arrival.begin(), Arrival.end());
    sort(Departure.begin(), Departure.end());
    int size = Arrival.size();
    int arrived = 1, departed = 0, count = 1, ans = 1;
    while(arrived < size && departed < size){
        if (Arrival[arrived] <= Departure[departed]) {
            count++;
            arrived++;
        } else {
            count--;
            departed++;
        }
        ans = max(ans, count);
    }
    return ans;
    // T.C. = O(n log n)
    // S.C. = O(1)
}