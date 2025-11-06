#include<bits/stdc++.h>
using namespace std;

// My solution:

/*
Two cases: left side sorted thiba(right sorted nathiba) OR left side sorted nathiba(right thiba)

1. jadi left side ta sorted achi, tahale se sorted half ra first element i.e. a[low] ta se half ra minimum thiba.

But auri kam kichi element right side re thaipare sethipain check kariki (a[low] < min) ,jadi darkar min = a[low] kariki
aame right ku jiba by doing low = mid + 1.

2. jadi left side hin sorted nahi tahale there is a chance ki left side re hin minimum thaipare which is less 
than a[mid] ta aame aage a[mid] ku min sahita compare kariba (because jadi left sorted nai, ta right achi; au
jadi sorted achi, tahale tara first element i.e. a[mid] is smallest in the sorted part) au store kariba 
a[mid] ku min re if required.

tapare high = mid - 1 kariki left side ku jiba au check kariba ahuri kam element achi ki nai.

ta jo bhi side ta sorted, taara minimum hela se side ra first element. au tapare aame opposite side ku jiba
and check kariba ki ahuri kam achi ki nai.

ta left sorted thile, a[low] ku min sahita compare kariki store kariba au right ku jiba to further check.
right sorted thile, a[mid] ku min sahita compare kariki store kariba au left ku jiba to further check.

jadi duita janka side by sorted achi, tahale bhi ama condition fulfil haba kainki na at least re amaku ko gote 
side sorted darkar, jadi duita janka achi ta no problem - aame ko bhi side ku further gale kichi problem nai
because jo bhi side ku further jiba, that means aame taa alga side ra minimum element ku already min sahita 
compare karisariche ta sie bhi checked.

either left is sorted, or right is sorted or both are sorted.
*/

/*
take examples and do dry runs wherever you get confused; if you did understand before, you will do it again
even if the above explanation wasn't there.

e.g.1   [4,5,6,7,0,1,2]
e.g.2   [7,8,1,2,3,4,5,6]
e.g.3   [4,5,1,2,3]
*/

int findMin(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    int min = INT_MAX;

    while(low <= high){ 
        int mid = (low + high) / 2;
        if(nums[low] <= nums[mid]){ // Why <= ? Because where low = mid, nums[low] will be equal to nums[mid]
            if(nums[low] < min) min = nums[low];
            low = mid + 1;
        } 
        else{
            if(nums[mid] < min) min = nums[mid];
            high = mid - 1;
        }
    }
    return min;
}

// Striver's solution:

int findMin(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[low] <= arr[mid]) {
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        else {
            high = mid - 1;
            ans = min(ans, arr[mid]);
        }
    }
    return ans;
}

/*
Can we optimize it further? Yes we can.

Whenever we reach a searching space that is entirely sorted (not either left or right sorted),
when it is entirely sorted, we know that the first element of the search space will be its minimum.
So we don't need to do binary search further.
*/

// Further optimized code:

int findMin(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;

    while (low <= high) {
        int mid = (low + high) / 2;

        // search space is already sorted
        // then always arr[low] will be smaller
        // in that search space
        if (arr[low] <= arr[high]) {
            ans = min(ans, arr[low]);
            break;
        }

        if (arr[low] <= arr[mid]) {
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        else {
            high = mid - 1;
            ans = min(ans, arr[mid]);
        }
    }
    return ans;
}

// T.C. = For all unique elements, it is simple. Normal binary search. so O(log n)

// Your homework is to search minimum in a rotated sorted array with duplicates and find its T.C. in all cases.
// Same method will be used as we did to search an element in a rotated dorted array with duplicates. TRYY IT.





