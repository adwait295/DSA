#include<bits/stdc++.h>
using namespace std;

/*
There may be duplicates of the target in the array. We just have to find out if the target is present 
in the array or not (i.e. Does it exist in the array or not?). We do not have to return the indices where 
the target occurs because there are duplicates and doing it using binary search is not possible; 
We would have to use proper linear search to do it. 
*/



/*
Let us take cases where the previous algorithm(without duplicates) will work here in this 
problem(i.e. with duplicates):

1. [6,7,1,2,3,4,4,5] -> it will work as 6 is not <=2 but 2<=5 so we know left part is unsorted and right 
is sorted.

2. [4,5,1,2,3,3,4,4] -> this will work too because 4 not <=2 but 2<=4. so left is unsorted and right sorted.

3. [3,1,2,3,3,3,3,3] -> this will not work because in the left half 3<=3 but still the left part is unsorted.

But unlike us, the computer will not be able to see the whole array with its own naked eyes right? 
So as 3<=3, so it thinks that the left half is sorted and proceeds further which might cause problems.

Our checking of sorted halves is solely dependent upon comparisions of low, mid and high. If they become
equal due to presence of duplicates as in e.g. 3 where a[low] = a[mid] = a[high] then the computer will think
either half is sorted depending upon which check comes first -> the left or the right. 

So it is important that we shrink (trim) the search space and eliminate the only condition which causes this
problem where:
(a[low] = a[mid] = a[high]) and then continue further will this condition is eliminated.

Then point where the condition does not occur, we will be able to identify the sorted half as it is a rotated
sorted array and do binary search as required. 

So how do we do this?
We do this by trimming or shrinking the search space from either side whenever the condition arises, 
and we do keep doing it until that condition is eliminated.

e.g. [3,3,3,1,3,3,3,3,3] target = 1

a[low] = a[mid] = a[high] = 3 != 1. so:
search space becomes: [3,3,1,3,3,3,3].

a[low] = a[mid] = a[high] = 3 != 1. so:
search space becomes: [3,1,3,3,3].

again. so:
[1,3,3].

now that condition is eliminated. So we can apply our previous binary search algorithm from this point, 
not until the problematic condition is eliminated. 
*/

bool searchInARotatedSortedArrayII(vector<int>& arr, int k) {
    int n = arr.size();
    int low = 0, high = n - 1;
    
    while(low <= high) {
        int mid = (low + high) / 2;
        
        if(arr[mid] == k) return true;
        
        if(arr[low] == arr[mid] && arr[mid] == arr[high]) { // problematic condition
            low++; // trim from left side
            high--; // trim from right side
            continue; // because we cannot do binary search until the problematic condition gets eliminated.
            // so go back and check again.
        }
        
        if(arr[low] <= arr[mid]) {
            if(arr[low] <= k && k <= arr[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } 
        else {
            if(arr[mid] <= k && k <= arr[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return false;
}

// T.C. = O(log n) -> average case i.e. in most of the cases because it's a binary search algorithm ofc.
// T.C. = O(n/2), not exactly but close to, in the worst case. 

// How?
// e.g. [3,3,1,3,3,3,3] target = 1. OR e.g. [3,3,3,3,3,3] target = 2.
// We cannot do a binary search until we get rid of the problematic condition. 
// And to get rid of it, we might have to trim almost n/2 on either sides in the worst case 
// i.e. we can keep trimming till the half the size of the array if needed to achieve that point
// from where we can apply binary search. so in the worst case it reaches close to O(n/2) when we trim
// almost a complete half (n/2) on either side. 

/*
In the future, if you get problems like these that have duplicates, always try to solve the problem in terms 
of unique elements first, and then see where the unique will fail (under which condition) and then
try to eliminate the condition for which certain test cases are failing and try to fit in those test cases
by making changes to the code by which the problematic condition will be eliminated.

This is how you generally approach a problem with duplicates in it.
*/


