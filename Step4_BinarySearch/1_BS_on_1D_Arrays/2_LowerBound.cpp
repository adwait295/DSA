#include<bits/stdc++.h>
using namespace std;

// Method 1:

int lowerBound(vector<int> arr, int target, int size){
    int low = 0, high = size - 1;
    int answer = size;

    while(low <= high){
        int mid = (low + high) / 2;

        if(arr[mid] >= target){ // maybe an answer
            answer = mid; 
            high = mid - 1; // look for smaller index on the left as we have to find the smallest.
        }
        else low = mid + 1; // look for right
    }
    return answer;
}

/*
Method 2: using the lower_bound() in C++ STL.

lb = lower_bound(arr.begin(),arr.end(),target) 
This will give an iterator pointing to that index as lower_bound() returns an iterator.

In order to get the index:
index = lb - arr.begin()

So:
lb = lower_bound(arr.begin(),arr.end(),target)                  -> This lb is an iterator.
lb = lower_bound(arr.begin(),arr.end(),target) - arr.begin()    -> This lb is the index.

We use the .begin() & .end() in case of vectors, not arrays.

In case of arrays, we right lb = lower_bound(arr,arr+size,target)  -> This lb is an iterator too. 

If we are asked to find the lower bound in a particular portion of the array/vector & not the entire array:

e.g. from index 2 to 6: [2,6]

lb = lower_bound(arr+2,arr+7,target) -> gives an iterator pointing to the lower bound in this portion of array.

*/