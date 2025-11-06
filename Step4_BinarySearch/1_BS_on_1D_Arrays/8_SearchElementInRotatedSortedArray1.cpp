#include<bits/stdc++.h>
using namespace std;

// The Rotated Sorted Array contains distinct (unique) elements.

// Brute force: Linear Search

// T.C. = O(n)

// But in the question, we can see two keywords: 'search' & 'sorted'.
// Whenever we these two words, we know we can do binary search :)

/*
In an interview, when we see these two words, we should not jump happily and say that this can be done by
using binary search. NO.

We will first tell that this can be done using linear search. It will have O(n) T.C.

But since the array is sorted and we have to search for an element, we can implement binary search which will
take a lesser time complexity as we eliminate portions of the array from search space at every step. 

Then we can move forward to implement our binary search algorithm.
*/

// As the array is unsorted, we cannot just do a simple binary search. 
// Whenever we find the mid index, at every step we should first check which half is sorted.
// Obviously either the left half will be sorted or the right half(you can check by taking e.g.)
// After we check which half is sorted, we either go right or left depending upon whether the target
// is in the sorted half or unsorted half.

/*
If we don't check which half is sorted, then we won't be able to check in which half the target might lie.
Whenever one half is sorted, then we check if the target lies there or not which can be done as that half is 
sorted, by doing: a<b<c comparisions which we wouldn't have been able to do if the part was unsorted. After
that, if the sorted half does not contain the target, we shrink the search space to the unsorted half.

But checking which half is sorted is crucial, otherwise we won't be able to use the a<b<c approach which is 
necessary to find a target in a sorted array because if one half is unsorted and a<c then how can we say that
all the b elements between a & c will also be <c right? That's the cache.
*/

int search(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(nums[mid] == target) return mid;
        else if (nums[low] <= nums[mid]){ // Left half is sorted
        // The <= operator does not cause any problem because the array does not have duplicates.
            if(nums[low] <= target && target <= nums[mid]){ // and target lies in the left sorted half
                high = mid - 1;
            }
            else{ // but target lies in the right unsorted half
                low = mid + 1;
            }
        }
        else{ // Right half is sorted
            if(nums[mid] <= target && target <= nums[high]){ //and target lies in the right sorted half
                low = mid + 1;
            }
            else{ // but the target lies in the left unsorted half
                high = mid - 1;
            }
        }
    }
    return -1; // if not found
}

// Elimination is the key in most of the problems. We have to identify which portion we are sure to 
// eliminate. 

// We just identify the portions to be eliminated and then we can write binary search for anything.