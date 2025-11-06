#include<bits/stdc++.h>
using namespace std;

// Same elements cannot be added to give the target.

/*
There are two varieties of this question:

One is - if we found two elements whose sum is the target, return yes, otherwise no.

Other is - if we found the two elements, return their indices as an array, 
otherwise return {-1,-1}
*/

// Brute force solution:

vector<int> twoSum1(vector<int> &arr, int target){
    int size = arr.size();
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++) 
        {
            if(arr[i] + arr[j] == target)
            return {i,j};
        }
    }
    return {-1,-1};
}

/*
T.C. = O(n^2), not exactly but close to.

Still slightly better than the extreme brute force solution where both i and j would be 
starting from 0 and going till last element. It would have had more number of iterations
and T.C. would still be = O(n^2), but more close to.

So we CAN always try to get (if present) another brute solution from the extreme brute 
solution with a slightly better time complexity.

S.C. = O(1)
*/

// Better solution: Hashing

vector<int> twoSum2(vector<int> &arr, int target){
    int size = arr.size();
    unordered_map<int,int> mpp;
    for(int i=0;i<size;i++) // O(n)
    {
        if(mpp.find(target - arr[i]) != mpp.end()){
            return {mpp[target - arr[i]], i};
        }
        mpp[arr[i]] = i; // O(log n)
    }
    return {-1,-1};
}

/*
T.C. = O(n log n), if we take maps. As finding/inserting a key takes log n time.
T.C. = O(n), if we take unordered maps. (in the best & avg cases)
In the worst case T.C. = O(n^2) in unordered maps.

S.C. = O(n)
*/

// The better solution is the optimal for the variety 2.


// Slightly Better solution: Two-pointer approach (Greedy)

// If the interviewer asks us to solve the question without the map data structure, then
// we can try this solution.

// It is slightly better for variety 1 because it has same T.C. but S.C. = O(1).

bool twoSum3(vector<int> &arr, int target){
    int size = arr.size();
    sort(arr.begin(), arr.end()); // O(n log n)
    int left = 0, right = size-1;
    while(left <= right) // O(n)
    {
        int sum = arr[left] + arr[right];

        if(sum == target) return true;
        else if (sum > target) right--;
        else left++;
    }
    return false;
}

/*
Is this a good approach for variety 2?

Not recommended for variety 2?

No, because for variety 2, we would have to store (value, index) in some other data structure
& then sort it so that after sorting, we still have the original indexes along with the values.

But this is not an optimal approach, as we would end up taking more space because we are 
using a data structure of N ✖ 2.

It is the optimal approach for variety 1.
*/

// T.C. = O(n + n log n)
// S.C. = O(1)

/* 
The interviewer might argue that we are changing the array.
In that case, we will say - If you want to take into account the modified array, then we 
are taking O(n) S.C. 

I am not taking any extra space but I am distorting the original array.
If you want to consider that distorted array S.C., well and good, the S.C. = O(n)

If you dont want to consider, then it is O(1)

This is theoretical and we can always explain to the interviewer.
*/


int main(){
    int size;
    cin >> size;
    int target;
    cin >> target;
    vector<int> arr;
    for(int i=1;i<=size;i++)
    {
        int n;
        cin >> n;
        arr.push_back(n);
    }
    //vector<int> x = twoSum1(arr,target);
    //vector<int> x = twoSum2(arr,target);

    //cout << "[" << x[0] << "," << x[1] << "]";

    bool x = twoSum3(arr, target);
    if(x == 0) cout << "NOT found" << endl;
    else cout << "Found" << endl;

    return 0;

}