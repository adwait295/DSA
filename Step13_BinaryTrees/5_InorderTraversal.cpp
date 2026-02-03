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
    vector<vector<int>> levelOrder(TreeNode* root){
        vector<vector<int>> ans;

        if(root == nullptr) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> levelElements;
            for(int i=1;i<=size;i++){
                TreeNode* temp = q.front();
                levelElements.push_back(temp->data);
                q.pop();

                TreeNode* leftNode = temp->left;
                TreeNode* rightNode = temp->right;
                if(leftNode != nullptr) q.push(leftNode);
                if(rightNode != nullptr) q.push(rightNode);
            }
            ans.push_back(levelElements);
        }

        return ans;
    }
};