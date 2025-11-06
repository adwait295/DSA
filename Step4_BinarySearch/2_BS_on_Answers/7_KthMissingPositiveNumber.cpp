#include<bits/stdc++.h>
using namespace std;

// Brute force solution:

// There are a lot of brute force solutions to this question but the simplest one is:

// Logic: If there is a number <= k in the array, then k will increase its value by 1, each time. Refer notes.

int missingNumber(vector<int> &arr, int k){
    for(int i=0;i<arr.size();i++){
        if(arr[i] <= k) k++;
        else break;
    }
    return k;
    // Take e.g. [4,5,6,9,13] for k=3, k=4, k=6 and do dry runs. You will understand for sure.
    // Another e.g. [2,3,4,7,11] for k=5.
}

// T.C. = O(n)
// S.C. = O(1)

// Optimal solution:

// As the array is sorted, and we are asked to find a number, sooooooo YES YES YES, you guessed it right! 
// Its Binary Search baby.
// And if the interviewer asks us to optimize the brute force solution, what is better than O(n)?
// O(log n) right? so from there too we can have the idea/intuition to use BS, as array is sorted.

/*
Can we apply the typical binary search algorithm?
No, we cannot. Why?
Because we are looking for the missing number. This number is not there in the array. So we cannot apply the 
typical 'binary search in a sorted array' i.e. the normal binary search.

Can we apply BS on Answers? 
We cannot because Binary Search on Answers is only applicable when we are looking for min/max and we know
that some portion is ✅✅✅✅✅✅ and other portion is ❌❌❌❌❌ so we either look for min or the max.
But over here, that's not the case.

The case is very different.

*/

/*
If we somehow figure out between which two elements of our array, the kth missing element lies, then our
problem will be solved. So our target is to find the two nearby indexes of the kth missing element and then
we will figure out how to find the answer.

We have to stand at those two indexes between which our kth missing element will be found.
*/

// My solution:

int findKthPositive(vector<int>& arr, int k) {
    int low = 0, high = arr.size() - 1;
    int ans = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] - (mid + 1) < k) low = mid + 1;
        else{
            ans = mid;
            high = mid - 1;
        }
    }
    if(ans == 0) return k; // e.g. [4,5,7,11] k=3. missing element is before the first element of array.
    else if(ans == -1) return arr[arr.size()-1] + (k-(arr[arr.size()-1] - arr.size()));
    // missing element is after the last element of array.
    // e.g. [2,3,4,6,7] k=3
    else{ // e.g. [2,3,4,7,11] k=5
        int missing = arr[ans - 1] - ans;
        int more = k - missing;
        return arr[ans - 1] + more;
    }
}

// T.C. = O(log n)
// S.C. = O(1)

// Striver's solution:

int missingK(vector<int> vec, int n, int k) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int missing = vec[mid] - (mid + 1);
        if (missing < k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return k + high + 1; // low + k
}

// T.C. = O(log n)
// S.C. = O(1)