#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int setBitCost(int n, int k) {
        int count = 0;
        for(int i=0;i<32;i++){
            if(n & (1 << i)) count++;
        }
        return count*k;
    }
};