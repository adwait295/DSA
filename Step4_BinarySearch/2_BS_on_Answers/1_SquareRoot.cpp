#include<bits/stdc++.h>
using namespace std;

// Brute force solution:

int squareroot1(int n){
    int ans = 1; // minimum value of square root of a positive integer.
    for(int i=1;i<=n;i++){
        if((i*i) <= n) ans = i; // if n = 28, then ans = 1,2,3,4,5 are possible but not 6,7,8,9,....
        // We choose the greatest possible value of 'ans' and return it (which is the floor value of sq.root).
        else break;
    }
    return ans;

    // T.C. = O(n), near about but not always equal to, obviously.
}

// Remember:
// Whenever we see such cases where till a certain point, the answers are possible and after a certain point,
// the answer is not possible, we can always apply binary search on that.

// If we know that the answer is within a particular range and we are asked to find the min/max, then
// we always apply Binary Search.

int floorSqrt(int n){
    int low = 1, high = n;
    while(low <= high){
        long long mid = (low + high) / 2;
        long long val = mid * mid;
        // We take long long because imagine we are given n = 10^9. so in that case val = 10^18 which will
        // cause overflow. So to prevent that, we need to be alert and take long long whenever we come across
        // these situations.
        if(val <= n){
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return high; // Why high? -> Refer notes.
}