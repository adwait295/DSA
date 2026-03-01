#include<bits/stdc++.h>
using namespace std;

int totalFruits(vector<int>& fruits) {
    int size = fruits.size(), maxLen = 0;

    unordered_map<int, int> mpp;
    int l = 0, r = 0;
    while(r < size){
      mpp[fruits[r]]++;

      if(mpp.size() > 2){
        mpp[fruits[l]]--;
        if(mpp[fruits[l]] == 0) mpp.erase(fruits[l]);
        l++;
      }

      maxLen = max(maxLen, r-l+1);
      r++;
    }
    return maxLen;
}