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

// Recursive implementation:

class Solution{
    public:
    vector<int> ans;
    vector<int> postorder(TreeNode* root){
        if(root == nullptr) return ans;

        postorder(root->left);
        postorder(root->right);
        ans.push_back(root->data);

        return ans;
    }
};

// Iterative implementation:

class Solution1{

    // Using two stacks:
    
    vector<int> postOrder1(TreeNode* root){
        vector<int> ans;
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;

        if(root == nullptr) return {};

        st1.push(root);

        while(!st1.empty()){
            TreeNode* temp = st1.top();
            TreeNode* rightNode = temp->right;
            TreeNode* leftNode = temp->left;

            st2.push(temp);
            st1.pop();

            if(leftNode != nullptr) st1.push(leftNode);
            if(rightNode != nullptr) st1.push(rightNode);
        }

        while(!st2.empty()){
            ans.push_back(st2.top()->data);
            st2.pop();
        }

        return ans;
    }

    // Using one stack:

    vector<int> postOrder2(TreeNode* root){
        vector<int> ans;
        stack<TreeNode*> st;

        if(root == nullptr) return {};

        st.push(root);

        while(!st.empty()){
            TreeNode* temp = st.top();
            ans.push_back(temp->data);
            st.pop();

            TreeNode* rightNode = temp->right;
            TreeNode* leftNode = temp->left;

            if(leftNode != nullptr) st.push(leftNode);
            if(rightNode != nullptr) st.push(rightNode);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};