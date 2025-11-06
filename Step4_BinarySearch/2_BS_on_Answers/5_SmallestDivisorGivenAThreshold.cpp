#include<bits/stdc++.h>
using namespace std;

// Finding the range is the most important thing.

/*
For applying binary search on answers, we need the following things:
1. min/max is asked in the question.
2. range is known or determined by us.
3. pattern of ✅ and ❌, i.e. where answer is possible and where it is not possible. 
*/

/*
e.g. [1,2,5,9] threshold = 6

divisor is always positive, so low = 1.

when we divide every element:
by 9, we get 1+1+1+1 = 4 which is <=6.
by 10 and above, we get the same thing. 

so as we need 'smallest' we take high = 9 i.e. the maximum element in the array

We can see that the minimum value of the sum that can be is equal to the size of the array i.e. 4 here.
because anything from max element to infinity, when divide all the elements of the array, will give a sum of 4.

But in case, the threshold given in the question is less than the size of the array, then the answer is not 
possible. So we return -1 in that case.

This is the case of 'No divisor possible' and this is the edge case.
*/

// Brute force solution:

int smallestDivisor(vector<int> &arr, int threshold){
    int maxElement = *max_element(arr.begin(),arr.end()); // O(n)
    for(int divisor=1;divisor<=maxElement;divisor++){ // O(maxElement)
        int sum = 0;
        for(int i=0;i<arr.size();i++){ // O(n)
            sum += ceil((double)arr[i] / (double)divisor);
        }
        if(sum <= threshold) return divisor;
    }
    return -1; // edge case

    // T.C. = O(n) + O(maxElement * n)
    // S.C. = O(1)
}

// Optimal solution:

// My solution:

bool result(vector<int> &arr, int divisor, int threshold){ // O(n)
    int sum = 0;
    for(int i=0;i<arr.size();i++){
        sum += ceil((double)arr[i] / (double)divisor);
    }
    return sum <= threshold;
}

int smallestDivisor(vector<int>& nums, int threshold) {
    int low = 1, high = *max_element(nums.begin(),nums.end()); // O(n)

    if(nums.size() > threshold) return -1; // edge case

    while(low <= high){ // O(log of maximum element)
        int mid = (0LL + low + high) / 2;
        if(result(nums,mid,threshold)) high = mid - 1; // O(n)
        else low = mid + 1;
    }
    return low;
}

// T.C. = O(n) + O(log of max element * n)
// S.C = O(1)

// Striver's solution:

int sumByD(vector<int>& arr, int div) {
    int sum = 0;
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        sum = sum + ceil((double)(arr[i]) / (double)(div));
    }
    return sum;
}

int smallestDivisor(vector<int>& arr, int limit) {
    int low = 1, high = *max_element(arr.begin(), arr.end());

    if(arr.size() > limit) return -1; // edge case

    while(low <= high) {
        int mid = (low + high) / 2;
        if(sumByD(arr, mid) <= limit) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
}
