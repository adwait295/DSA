#include<bits/stdc++.h>
using namespace std;

int kDistinctChar(string& s, int k) {
    int size = s.size();
    unordered_map<char, int> mpp;
    int l = 0, r = 0, maxLen = 0;
    while(r < size){
        mpp[s[r]]++;
        if(mpp.size() > k){
            mpp[s[l]]--;
            if(mpp[s[l]] == 0) mpp.erase(s[l]);
            l++;
        }
        maxLen = max(maxLen, r-l+1);
        r++;
    }
    return maxLen;
}