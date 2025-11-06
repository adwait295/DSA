#include<bits/stdc++.h>
using namespace std;

// Subarray - contiguous part of the array. (elements cannot be skipped)
// Subsequence - non-contiguous part of the array. (elements can be skipped)

// arr[] = {1,2,3,1,1,1,1,4,2,3}
// e.g. of subarray: {1}, {1,2,3}, {1,1,1}, {1,4,2}, etc.
// e.g. of subsequence: {1,4,3}, {1,1,3}, {1,1,1,1,1}, etc.

// Every subarray is a subsequence but not vice-versa.

// An entire array is also a subarray. 

// Brute force solution:
// Generate all the possible subarrays and find sum of each subarray.
// Then choose the longest among those whose sum = k.

int subarr(int arr[], int n, int k){
    int len = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int s = 0;
            for(int k=i;k<=j;k++) s = s + arr[k];
            if(s == k) len = max(len, j-i+1);
        }
    }
    return len;
}

// T.C. nearly equal to O(n^3), not exactly because both the two inner loops are shrinking/diminishing/reducing.
// S.C. = O(1)

// Better version of Brute force solution:

int subarr1(int arr[], int n, int k){
    int len = 0;
    for(int i=0;i<n;i++)
    {
        int s = 0;
        for(int j=i;j<n;j++)
        {
            s = s + arr[j];
            if(s == k) len = max(len, j-i+1);
        }
    }
    return len;
}

// T.C. = O(n^2), still not exactly because obviously the inner loop is shrinking.
// S.C. = O(1)

// So we brought our brute solution's time complexity to O(n^2), initially it was O(n^3).

// Better solution: in case of "no negatives" in array & Optimal solution: in case of "negatives also present" in the array.

int subarr2(vector<int> a, long long k){
    map<long long, int> preSumMap;
    long long sum = 0; // storing the prefixsum
    int maxLen = 0;
    for(int i=0;i<a.size();i++)
    {
        sum = sum + a[i];
        if(sum == k){ // Checking if the prefixsum of entire considered subarray (from 0th index to that index) is equal to k.
            maxLen = max(maxLen,i+1);
        }
        long long rem = sum - k;
        if(preSumMap.find(rem) != preSumMap.end()){ // If there exists a subarray from 0 uptill an index before that index whose sum = x - k.
            int len = i - preSumMap[rem];
            maxLen = max(maxLen,len);
        }
        if(preSumMap.find(sum) == preSumMap.end()){ // Checking if there are zeroes in the subarray because if there are, then the prefixsum must have been the same at some index previously.
            preSumMap[sum] = i;
        }
    }
    return maxLen;
}

// T.C. = O(n log n) in maps.
// T.C. = O(n) in unordered maps(best/avg case) and O(n^2) in unordered maps(worst case).
// S.C. = O(n) because of the hash map.

// Optimal solution for "no negatives" array: 2 pointer & greedy approach

int subarr3(vector<int> a, long long k){
    int left = 0, right = 0;
    long long sum = a[0];
    int n = a.size();
    int maxLen = 0;
    while(right < n)
    {
        while(left <= right && sum > k)
        {
            sum -= a[left];
            left ++;
        }
        if(sum == k) maxLen = max(maxLen, right-left+1);
        right++;
        if(right < n) sum += a[right];
    }
    return maxLen;
}

/*
T.C. = O(2n)
It looks like there are two while loops, so the time complexity will be O(n^2).
But that is not the case. n^2 happens when for every iteration of outer loop, the inner loop
iterates n times. And hence n*n = n^2.

But here, the inner while loop, over the course of entire iteration of outer while loop for 
n times, iterates a total of n times in the worst case.
Not for every iteration; But for entire iteration.

Hence, the outer loop iterates a total of n times.
The inner loop iterates a total of n times. (For total iteration of outer loop, not for every iteration)
So they add up and the code runs maximum for 2n times.

If still confused, take an example, do a dry run. You will understand for sure.

S.C. = O(1)
*/

// If we explain everything like this to the interviewer, he will be like shocked and 
// blindly give us the job :)

int main(){
    int size;
    cin >> size;
    vector<int> a;

    long long searchElement;
    cin >> searchElement;

    for(int i=1;i<=size;i++)
    {
        int n;
        cin >> n;
        a.push_back(n);
    }
    cout << "Longest subarray is of length: " << subarr3(a,searchElement);

    return 0;
}


