#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> setsWithOddSum(vector<int> nums) {
      vector<vector<int>> ans;
      int size = nums.size();
      int count = (1 << size);
      for(int i=0;i<count;i++){
        vector<int> subset;
        for(int j=0;j<nums.size();j++){
          if(i & (1 << j)) subset.push_back(nums[j]);
        }
        int sum = accumulate(subset.begin(), subset.end(), 0);
        if(sum & 1) ans.push_back(subset);
      }
      return ans;
  }
};