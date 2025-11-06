#include<bits/stdc++.h>
using namespace std;

// Same as book allocation problem.

int count(vector<int> &nums, int largestSum){
    int splitCount = 1, sum = 0;
    for(int i=0;i<nums.size();i++){
        if(sum + nums[i] <= largestSum) sum += nums[i];
        else{
            splitCount ++;
            sum = nums[i];
        }
    }
    return splitCount;
}

int splitArray(vector<int>& nums, int k) {
    int low = *max_element(nums.begin(),nums.end());
    int high = accumulate(nums.begin(),nums.end(),0);

    while(low <= high){
        int mid = (low + high) / 2;
        int countSplits = count(nums,mid);
        if(countSplits > k) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}