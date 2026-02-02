#include<bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int numberOccursTwice(vector<int> nums) {
        int number = 0;
        for (int i = 0; i < 32; i++) {
            int count = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] & (1 << i)) count++;
            }
            if (count % 3 != 0) number |= (1 << i);
        }
        return number;
    }
};