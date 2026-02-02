#include<bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> powerSet(vector<int>& nums) {
        int size = nums.size();
        int count = 1 << size;

        vector<vector<int>> ans;

        for (int i = 0; i < count; i++) { // O(2^n)
            vector<int> subset;
            for (int j = 0; j < size; j++) { // O(n)
                if (i & (1 << j)) subset.push_back(nums[j]);
            }
            ans.push_back(subset);
        }
        return ans;

        // T.C. = O(2^n * n)
    }
};