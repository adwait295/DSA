#include<bits/stdc++.h>
using namespace std;

// Return the minimum integer k such that Koko can eat all the bananas within h hours where k = bananas/hour.

// e.g. [3,6,7,11] h=8
// We are asked the 'minimum'. We know the range of answers (k) can be from 1 to 11. Why?
// Because if k = 12, then Koko will take 4 hours to complete the bananas.
// if k = 13, then also 4 hours; if k = 14, then also 4 hours and so on. So we will obviously take the 
// minimum value as that's what is asked in the question.

// So as we know the range and we are asked the min, so we know we can apply BS.
// Remember, range deciding is the most important part of binary search.

// Instead of taking range of 1 to 11, we can also take 1 to 100 and BS will still work because
// our answer (k) still lies in the range (be it 1 to 11 OR 1 to 10000000000000). But we don't take it
// obviously because we need to take the minimum required range to apply binary search to, in order to 
// reduce the time complexity. The length of the range will determine the T.C. of our BS algorithm.

// Brute force solution: Linear Search

long long reqTime(vector<int> &arr,int bananasPerHour){
    long long totalHours = 0;
    for(int i=0;i<arr.size();i++){
        totalHours += (arr[i] + bananasPerHour - 1) / bananasPerHour; // Mmmmmm Interesting!
        // We cannot use ceil() here because arr[i]/bananasPerHour will cause integer division 
        // as both are integers, so ceil() will be of no use as it takes double type value as input.
        // Instead of that, we use the above statement to calculate the ceil value directly without ceil().
    }
    return totalHours;

    // T.C. = O(n)
}

int koko1(vector<int> arr, int h){
    
    int maxElementOfArray = *max_element(arr.begin(), arr.end()); 
    // O(n) because max_element() of C++ STL does linear search.
    for(int i=1;i<=maxElementOfArray;i++){ // O(maxElement of given array)
        long long req_time = reqTime(arr,i);
        if(req_time <= h) return i;
    }
}

// T.C. = O(maxElement of given array * n) + O(n). This will give Time Limit Exceeded (TLE) when we run it.

// So how do we optimize this? Yes you are right! Its binary search on answers baby.
// Because we know there's a range, we are asked the min and we observe the pattern that: from 1 to 
// min-1,  there is ❌❌❌ and from min to the maximum element of the range we decided, there is ✅✅✅✅,
// where min is our required answer we will find using BS.

// Optimal Approach: Binary Search

// My answer:

int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1, high = *max_element(piles.begin(), piles.end()); // O(n)
    int answer = INT_MAX;
    while(low <= high){ // O(log of maximum element of array) i.e. log (high)
        int mid = (low + high) / 2;
        long long req_time = reqTime(piles, mid); // O(n)
        if(req_time > h) low = mid + 1;
        else{
            answer = mid;
            high = mid - 1;
        }
    }
    return answer;
}

// T.C. = O(log high * n) + O(n)

// Striver's answer:

int findMax(vector<int> &v) { // O(n)
    int maxi = INT_MIN;
    for (int i = 0; i < v.size(); i++) {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}

int calculateTotalHours(vector<int> &v, int hourly) { // O(n)
    int totalH = 0;
    int n = v.size();
    for (int i = 0; i < n; i++) {
        totalH += ceil((double)v[i] / (double)hourly);
    }
    return totalH;
}

int minimumRateToEatBananas(vector<int> &v, int h) {
    int low = 1;
    int high = findMax(v); // O(n)

    while (low <= high) { // O(log high)
        int mid = (low + high) / 2;
        int totalH = calculateTotalHours(v, mid); // O(n)

        if (totalH <= h) {
            high = mid - 1;   // can try smaller speed
        } else {
            low = mid + 1;    // need bigger speed
        }
    }
    return low;   // <-- final answer
}

// T.C. = O(log high * n) + O(n)

// Why returning low? Refer notes.

// Why taking long long to store totalHours in my answer but not in totalH in striver's answer?
// Because my answer is first causing addition of two integers and then division. The addition part can 
// cause overflow, so we use long long. But Striver's solution directly causes the division and stores the
// ceil value so no overflow so totalH can be stored in int type.