#include<bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k) {
    int size = s.size();
    int hash[26] = {0};
    int l=0, r=0, maxFreq=0, maxLen=0;
    while(r < size){
        hash[s[r] - 'A']++;
        maxFreq = max(maxFreq, hash[s[r] - 'A']);
        if((r-l+1)-maxFreq > k){
            hash[s[l] - 'A']--;
            l++;
        }
        maxLen = max(maxLen, r-l+1);
        r++;
    }
    return maxLen;
}