#include<bits/stdc++.h>
using namespace std;

// Iterative code:

int search(vector<int>& nums, int target) {
    int low = 0, high = nums.size()-1;

    while(low <= high){
        int mid = (low + high) / 2;

        if(nums[mid] == target) return mid;
        else if (target > nums[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

// Recursive code:

int bs(vector<int> &nums,int low, int high, int target){
    if(low > high) return -1;

    int mid = (low + high) / 2;

    if(nums[mid] == target) return mid;
    else if(target > nums[mid]) return bs(nums,mid+1,high,target);

    return bs(nums,low,mid-1,target);
}

int search1(vector<int> &nums, int target){
    return bs(nums,0,nums.size()-1,target);
}