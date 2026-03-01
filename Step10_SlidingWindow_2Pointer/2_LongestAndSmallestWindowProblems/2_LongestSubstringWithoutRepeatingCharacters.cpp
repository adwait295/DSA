#include<bits/stdc++.h>
using namespace std;

int longestNonRepeatingSubstring(string& s){
    int l = 0, r = 0, size = s.size();

    int maxLen = 1;

    unordered_map<char, int> mpp;
    while(r < size){
      mpp[s[r]]++;
      while(mpp[s[r]] == 2){
        mpp[s[l]]--;
        l++;
      }
      maxLen = max(maxLen, r-l+1);
      r++;
    }

    return maxLen;
}