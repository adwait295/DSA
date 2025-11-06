#include<bits/stdc++.h>
using namespace std;

int search(vector<int> arr, int target, int size){
    int low = 0, high = size - 1;
    int answer = size;

    while(low <= high){
        int mid = (low + high) / 2;

        if(arr[mid] > target){ // maybe an answer
            answer = mid;
            high = mid - 1; // look for smaller index on the left
        }
        else low = mid + 1; // look for right
    }
    return answer;
}