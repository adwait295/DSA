#include<bits/stdc++.h>
using namespace std;

/* 
The most important part is deciding the range:
e.g. [1,2,3,4,5,6,7,8,9,10]

Lets say we take weight capacity of ship = 8. 
Then 9 and 10 will not be able to be loaded into the ship because partial weights cannot be loaded right?
Will you break the item so that it becomes 8kg and then load it into the ship😂? Obviously no.

So low = max element of the given array of weights of items.

We know the minimum value of 'days' that can be given to us is 1.

if we take weight capacity of ship as the sum of all weights of the array, then all the items can be loaded
at once into the ship and it will take one day.

whatever we take from 55 (sum in the above example) to infinity, the number of days will be 1. 
We need the minimum, so we take high = sum of all weights given in the array i.e. 55 in the above example.

so the answer will be always in the range [max element, sum of all elements].
*/

// Brute force solution:

int func(vector<int> &weight, int capacity){ // O(n)
    int days = 1, load = 0;
    for(int i=0;i<weight.size();i++){
        if(load + weight[i] > capacity){
            days++;
            load = weight[i];
        }
        else load += weight[i];
    }
    return days;
}

int minimumCapacity(vector<int> &weight, int days){

    int maxElement = INT_MIN;
    long long sum = 0;
    for(int i=0;i<weight.size();i++){ // O(n)
        maxElement = max(maxElement,weight[i]);
        sum += weight[i];
    }

    for(int capacity=maxElement;capacity<=sum;capacity++){ // O(sum - maxElement + 1)
        int daysReqd = func(weight,capacity);
        if(daysReqd <= days) return capacity;
    }
    return -1;
}

// T.C. = O(n) + (O(sum - maxElement + 1) * O(n))

// Optimal solution:

// My solution:

long long sum(vector<int> &arr){
    long long sum = 0;
    for(int i=0;i<arr.size();i++) sum += arr[i];
    return sum;
}

bool possible(vector<int> &arr, long long weightCapacity, int days){
    int noOfDays = 0, i = 0;
    long long weight = weightCapacity;
    while(i < arr.size()){
        if(weight - arr[i] >= 0){
            weight = weight - arr[i];
            i++;
        }
        else{
            noOfDays++;
            weight = weightCapacity;
        }
    }
    noOfDays++;
    return noOfDays <= days;
}

int shipWithinDays(vector<int>& weights, int days) {
    int low = *max_element(weights.begin(), weights.end()); // O(n)
    long long high = sum(weights); // O(n)

    while(low <= high){ // O(log (high-low+1))
        long long mid = (low + high) / 2;
        if(possible(weights, mid, days)) high = mid - 1; // O(n)
        else low = mid + 1;
    }
    return low;
}

// T.C. = O(2n) + O(log (high-low+1)) * O(n)

// Striver's solution:

int findDays(vector<int> &weights, int cap) {
    int days = 1, load = 0;
    for(int i = 0; i < weights.size(); i++) {
        if(weights[i] + load > cap) {
            days += 1;
            load = weights[i];
        }
        else {
            load += weights[i];
        }
    }
    return days;
}

int leastWeightCapacity(vector<int> &weights, int d) {
    int low = *max_element(weights.begin(), weights.end()); // O(n)
    int high = accumulate(weights.begin(), weights.end(), 0); // O(n)
    while(low <= high) { // O(log (high-low+1))
        int mid = (low + high) / 2;
        int numberOfDays = findDays(weights, mid); // O(n)
        if(numberOfDays <= d) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
}

// T.C. = O(2n) + O(log (high-low+1)) * O(n)