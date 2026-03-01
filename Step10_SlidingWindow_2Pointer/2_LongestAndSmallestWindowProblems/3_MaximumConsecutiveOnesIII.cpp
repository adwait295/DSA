#include<bits/stdc++.h>
using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int l=0, r=0, size = nums.size();

    vector<int> zeroIndices; int firstZeroIndex = 0;

    int maxLen = 1;

    while(r < size){
        if(nums[r] == 0){
            zeroIndices.push_back(r);
            if(k > 0){
                k--;
            } 
            else{
                l = zeroIndices[firstZeroIndex] + 1;
                // cout << l << endl;
                firstZeroIndex++;
            }
        }
        maxLen = max(maxLen, r-l+1);  
        r++;
    }
    return maxLen;
}