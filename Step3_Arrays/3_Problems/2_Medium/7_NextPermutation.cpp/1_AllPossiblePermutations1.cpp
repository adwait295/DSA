#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void recurPermute(vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans, int freq[]) {
        if (ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!freq[i]) {
                ds.push_back(nums[i]);
                freq[i] = 1;
                recurPermute(ds, nums, ans, freq);
                // Backtracking, so that other iterations are unaffected due to this iteration:
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int freq[nums.size()]; // We can directly do int freq[nums.size()] = {0}; Then we dont require the for loop to do that.
        for (int i = 0; i < nums.size(); i++) freq[i] = 0;
        recurPermute(ds, nums, ans, freq);
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
