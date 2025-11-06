#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void recurPermute(int index, vector<int> &nums, vector<vector<int>> &ans) {
        if (index == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);
            recurPermute(index + 1, nums, ans);
            // Backtracking, so that other iterations are unaffected due to this iteration:
            swap(nums[index], nums[i]); // backtrack
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> ans;
        recurPermute(0, nums, ans);
        return ans;
    }
};

int main(){
    int size;
    cin >> size;
    vector<int> v;
    for(int i=1;i<=size;i++)
    {
        int n;
        cin >> n;
        v.push_back(n);
    }

    Solution obj;
    vector<vector<int>> ans = obj.permute(v);

    for(auto it: ans)
    {
        for(auto x: it)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}