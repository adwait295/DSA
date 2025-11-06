#include<bits/stdc++.h>
using namespace std;

// Brute force solution:

int single(vector<int> &nums){
    int size = nums.size();

    if(size == 1) return nums[0];
    
    for(int i=0;i<size;i++){
        if(i == 0){
            if(nums[i] != nums[i+1]) return nums[i];
        }
        else if(i == size - 1){
            if(nums[i] != nums[i-1]) return nums[i];
        }
        else{
            if(nums[i] != nums[i-1] && nums[i] != nums[i+1]) return nums[i];
        }
    }
    return -1;

    // T.C. = O(n)
}

// So what do we do? Whenever 'sorted' is there, we can think of a binary search.
// And we know, in order to apply binary search, we have to think of elimination.

// So here we have to find out a property of the single element which helps us justify the elimination.

// Whenever we are writing a binary search like this where we have to check the previous and next element
// of every element, there can be a lot of edge cases - What if we are at 0 or at last index?

// So whenever we have a binary search problem where we are facing this left-right issue, we have to write 
// a lot of conditional cases. So try to eliminate those conditional cases by writing separate conditions
// for those cases. 

// Striver's solution:

// (even,odd) -> the single element is on the right half, so eliminate left.
// (odd,even) -> the single element is on the left half, so eliminate right.

// e.g. [1,1,2,2,3,4,4,5,5,6,6], 
/*
indexes of 1: (0,1)  (even,odd)
indexes of 2: (2,3)  (even,odd)
single element: 3
indexes of 4: (5,6)  (odd,even)
indexes of 5: (7,8)  (odd,even)
indexes of 6: (9,10) (odd,even)
*/

int singleNonDuplicate1(vector<int>& arr) {
    int n = arr.size();
    // Eliminating conditional cases first (edge cases):
    if(n == 1) return arr[0];
    if(arr[0] != arr[1]) return arr[0];
    if(arr[n-1] != arr[n-2]) return arr[n-1];

    // Now, we have trimmed down our search to : from 2nd element to second last element.

    int low = 1, high = n - 2;
    while(low <= high) {
        int mid = (low + high) / 2;

        if(arr[mid] != arr[mid+1] && arr[mid] != arr[mid-1]) { // main check for the single element.
            return arr[mid];
        }

        // (even,odd) -> if standing at odd, check for previous. If standing at even, check for next.
        if((mid % 2 == 1 && arr[mid] == arr[mid-1]) or (mid % 2 == 0 && arr[mid] == arr[mid+1])) {
            low = mid + 1; // single element is on right half, so eliminate the left half.
        }
        // (odd,even)
        else {
            high = mid - 1; // single element is on the left half, so eliminate the right half.
        }
    }
    return -1; // dummy condition. 
}

// T.C. = O(log n)

// Always remember - The main focus is elimination. Once we understand what is needed to be eliminated, 
// binary search is super easy. 


// My solution:

int singleNonDuplicate(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;

    while(low <= high){
        int mid = (low + high) / 2;

        if(mid == 0 || mid == nums.size() - 1) return nums[mid]; // edge case

        if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];

        if(mid % 2 != 0){ // jadi odd achi ta olta side ku jiba
            if(nums[mid] == nums[mid-1]) low = mid + 1; // left re same achi, right ku gale
            else high = mid - 1; // right re same achi, left ku gale
        }
        else{ // jadi even achi ta same side ku jiba
            if(nums[mid] == nums[mid-1]) high = mid - 1; // left re same achi, left ku gale
            else low = mid + 1; // right re same achi, right ku gale
        }
    }
    return -1; // a dummy statement. This statement won't work because our input will always contain a 
    // single element. But it has to be written because our functions returns an integer value.
}