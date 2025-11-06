#include<bits/stdc++.h>
using namespace std;

// The rotated sorted array contains only unique elements.

// The number of times the sorted array is right-rotated will be equal to the index of the minimum element
// in the rotated sorted array. so we just have to find the minimum element. That's it.
// If the index is 0, then the array has not been rotated at all.

// If in question, it is asking number of times the array has been left-rotated, then it will be:
// size - index of minimum element. If the difference comes out to be 0, then the array has not been rotated at all.

int NumberOfRotations(vector<int> &nums){
    int low = 0, high = nums.size() - 1;
    int min = INT_MAX;
    int index = -1;

    while(low <= high){ 
        int mid = (low + high) / 2;

        if(nums[low] <= nums[high]){
            if(nums[low] < min){
                index = low;
                min = nums[low];
            }
            break;
        }
        if(nums[low] <= nums[mid]){ 
            if(nums[low] < min){
                index = low;
                min = nums[low];
            }
            low = mid + 1;
        } 
        else{
            if(nums[mid] < min){
                index = mid;
                min = nums[mid];
            }
            high = mid - 1;
        }
    }
    return index;
}

// Homework - Do this for duplicates. Obviously similar to searching minimum element in rotated sorted array
// with duplicates.