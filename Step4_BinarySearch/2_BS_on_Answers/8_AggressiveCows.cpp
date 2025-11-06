#include<bits/stdc++.h>
using namespace std;

// Google interview question.

// Now, we will be moving to the other part of BS on Answers, where we will be asked to find min of max or
// max of min, i.e. (min)max or (max)min.

// Here (minimum distance b/w any two cows) is maximum possible.

// We know that the minimum distance between any two cows is possible only when those two cows are at 
// consecutive stalls. So for distance to be minimum in a particular arrangement of cows, we have to find
// the minimum consecutive-distance because obviously the minimum will happen to be b/w consecutive stalls.
// so we sort the stalls to keep the consecutive stalls together.

// because obviously if S1,S2,S3 are kept in order, minimum distance will be either b/w S1 & S2 or S2 & S3, 
// not between S1 & S3 because it is not consecutive and (S3-S1) = (S2-S1) + (S3-S2). So farther distances
// will obviously be always more than consective distances.

// The maximum consecutive distance possible will be maxi-mini; so our high = maxi - mini
// The minimum consecutive distance possible can be calculated by comparing all the consecutive distances
// and then can be stored in low.
// But we will not calculate the low (we can do if we want for further optimization. It is better.)
// We will take low = 1 in all cases because that won't make much of a difference to the time complexity.
// As whatever low we calculate, that [low,high] will always lie inside [1,high], so there is no big problem
// in taking the range as [1,high], won't make a big difference in T.C.

// If we would have taken high = 10^9, it would still be correct obviously, but 
// then the range would have been huge and would have affected the T.C.
// so the interviewer would have had a problem with that, but taking low = 1 rather than the minimum consecutive
// distance won't make much of a difference because it won't make the range huge, so won't affect T.C. so 
// the interviewer won't be bothered if we take low = 1 instead of calculating low.

// Brute force solution: Linear Search:
// We will start from low (i.e. 1 taken by us) and go till high, and check for which
// 'min-taken-consecutive distance',all consecutive distances 
// b/w any two cows >= our min-taken-consecutive-distance, when we are able to place
// all k cows. Whenever atleast one consecutive distance b/w any two cows becomes < our min-taken-consecutive-distance, 
// when we place all k cows, i.e. it is not possible to maintain the '>=' condition,
// we will return the previous min-taken-consecutive distance taken by us:

// Why? Because for x, it was >= but for x+1 it is <, so for x it must have been =, otherwise how for x+1 it 
// would be < right?; so whenever x+1 fails the '>=' condition we return x.

bool CanWePlace(vector<int> &arr, int minDistance, int k){ // O(n)
    int countCows = 1, lastCowPosition = arr[0]; // because the elements of arr are positions.
    // because it is very obvious that we will place our first cow (cows are not numbered) at index 0 because,
    // We are not trying to figure out the arrangements, we are trying to figure out whether a minDistance 
    // is possible to maintain or not.
    for(int i=1;i<arr.size();i++){
        if(arr[i] - lastCowPosition >= minDistance){
            countCows++;
            lastCowPosition = arr[i];
        }
        if(countCows >= k) return true; // This condition is written inside the for loop because the moment we
        // reach k cows, we return true because it is possible we are able to place more than k cows with this
        // minDistance but we don't need to know how many cows; we just need to know 'k' is possible or not.
    }
    return false;
}

int min_max(vector<int> &arr, int k){
    sort(arr.begin(),arr.end()); // O(n log n)
    
    int size = arr.size();

    int low = INT_MAX;
    for(int i=1;i<size;i++){ // O(n)
        low = min(low, arr[i]-arr[i-1]);
    }
    // I calculated low rather than taking low = 1, to make my code better.
    int high = arr[size-1] - arr[0]; // max element - minimum element

    for(int i=low;i<=high;i++){ // O(high - low)
        if(CanWePlace(arr,i,k)) continue; // O(n)
        else return i-1;
    }
}

// T.C. = O(n log n + n + ((high-low)*n)); we can see it is reaching quadratic T.C. 
// S.C. = O(1)

// Obviously the interviewer will not be happy with the T.C. and will ask us to optimize it.

// We can notice that the only part that we can optimize is O(high - low), which is linear. 
// How to optimize it? Can we make it O(log (high-low))? Can we apply binary search to this problem?

// YES we can!!

// Why? 

// We have already done similar problems. 

// e.g. [0,3,4,7,9,10] k=4
// From 1 to 3, it is ✅✅✅✅, from 4 to (high-low) it is ❌❌❌❌. So as we can see this pattern, we
// can apply BS and high will be our answer because it will end up at polarity ✅ as the pattern is
// ✅✅✅❌❌❌.

int aggressiveCows(vector<int> &stalls, int k){

    sort(stalls.begin(),stalls.end()); // O(n log n)
    
    int size = stalls.size();

    int low = INT_MAX;
    for(int i=1;i<size;i++){ // O(n)
        low = min(low, stalls[i]-stalls[i-1]);
    }
    // I calculated low rather than taking low = 1, to make my code better.
    int high = stalls[size-1] - stalls[0]; // max element - minimum element

    while(low <= high) {
        int mid = (low + high) / 2;
        if(CanWePlace(stalls, mid, k) == true) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return high;
}

// This is the reason why we should do linear search first. Because once we understand the linear search, 
// it is super simple to convert it into a binary search.

// T.C. = O(n log n + n + ((log (high-low))*n))
// S.C. = O(1)
    