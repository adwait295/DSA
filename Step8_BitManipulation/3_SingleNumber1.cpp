#include<bits/stdc++.h>
using namespace std;

// Brute solution: O(n^2) as for each element of the array, there will be an inside loop to check the number of times that element has appeared.

// Better solution:
int brute(vector<int> &nums){
    unordered_map<int, int> mpp;
    for(int i=0;i<nums.size();i++){ // O(n)
        mpp[nums[i]]++; // O(1) in case of unordered map & O(log (size of map)) in case of ordered map.
    }
    for(auto it: mpp){ // O(n/2 + 1) as size of map = n/2 + 1.
        if(it.second == 1) return it.first;
    }
    return -1;

    // T.C. = O(n + (n/2 + 1))
    // S.C. = O(n/2 + 1)
}

// Optimal solution:

int singleNumber(vector<int>& nums){
    int ans = 0;
    for(int i=0;i<nums.size();i++){
        ans ^= nums[i];
    }
    return ans;

    // T.C. = O(n)
    // S.C. = O(1)
}