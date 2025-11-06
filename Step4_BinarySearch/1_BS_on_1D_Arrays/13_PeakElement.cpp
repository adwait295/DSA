#include<bits/stdc++.h>
using namespace std;

// Brute force solution:

int peak1(vector<int> &a){
    int size = a.size();
    for(int i=0;i<size;i++){
        if((i == 0 || a[i-1] < a[i]) && (i == size-1 || a[i] > a[i+1])) return a[i]; // or return i
    }
    return -1;

    // T.C. = O(n)
    // S.C. = O(1)
}

// The interviewer will not be happy with O(n) and ask us to optimize it. So what is less than n? 
// We might try to do it in log n time. When we think of log n, only certain algorithms come to our mind.
// One of them is binary search. Why think of trying binary search? Because the problem statement states to
// 'find' an element or 'search' an element. And we can also see that for a peak element, either sides
// should be smaller. So it gives a VIBE OF 'sorted' more or less. So we might as well try binary search. 

/*
Remember: (Refer the graphs in notes)

0. An element can itself be at the peak.
1. There will always be a peak on the right side of an 'element on the increasing curve'.
2. There will always be a peak on the left side of an 'element on the decreasing curve'.
3. If an element is at a valley, then either sides of that element will have a peak.

*/

int findPeakElement(vector<int>& nums) {
    int size = nums.size();

    // Edge cases:
    if(size == 1) return 0;
    if(nums[0] > nums[1]) return 0;
    if(nums[size - 1] > nums[size - 2]) return size - 1;

    int low = 1, high = size - 2;
    while(low <= high){
        int mid = (low + high) / 2;
        // conditions that are same in case of 'single peak' & 'multiple peaks' situations:
        if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) return mid; // at the peak.
        else if (nums[mid] > nums[mid-1]){ // It is on the increasing curve.
            low = mid + 1;
        }
        else if (nums[mid] < nums[mid-1]){ // It is on the decreasing curve.
            high = mid - 1;
        }

        // Extra condition check for multiple peaks:
        else{ // It is at the valley.
            low = mid + 1; // or high = mid - 1 -> either will work.
        }
        // If we had not written this condition and if nums[mid] was at a valley, then it would have stuck
        // in an infinite loop.
    }

    // We can also avoid this 'else condition' and merge it with the 'else-if' condition above
    // by making it 'else' and doing high = mid + 1 altogether:

    /*
    while(low <= high){
        int mid = (low + high) / 2;
        if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) return mid;
        else if (nums[mid] > nums[mid-1]){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    */
    return -1;
}

// T.C. = O(log n)

// We started analysing the situation by taking an example into consideration which contained only one peak.
// We visualised its graph, wrote the pseudo code by analysing the pattern. Then we expanded our study
// to multiple peaks by visualising its graph and found out one extra condition that in latter case, an element
// might be at a valley, so we wrote an extra condition for that.