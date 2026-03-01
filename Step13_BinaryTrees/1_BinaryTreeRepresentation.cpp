#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        data = val;
        left = right = nullptr;
    }
};

class Solution{
    // .... whatever we have to write in a function and submit.
    // e.g. vector<int> anyFunction(TreeNode* root){}
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(7);

    Solution sol = Solution();

    // vector<int> ans = sol.anyFunction(root);

    // for(auto it: ans) cout << it << " ";

    // cout << endl;

    return 0;
}