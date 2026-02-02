#include<bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums) {
    int maxJump = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (i > maxJump) return false;
        if (maxJump >= n - 1) return true;
        maxJump = max(maxJump, i + nums[i]);
    }
    return true;
}