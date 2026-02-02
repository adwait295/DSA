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
    vector<int> preorder(TreeNode* root){
        if(root == nullptr) return ans;

        ans.push_back(root->data);
        preorder(root->left);
        preorder(root->right);

        return ans;
    }
};

// Iterative implementation:


class Solution1{
    
    public:

    // My solution:

    vector<int> preorder(TreeNode* root){
        vector<int> ans;
        stack<TreeNode*> st;

        if(root == nullptr) return {};

        ans.push_back(root->data);
        st.push(root);
        TreeNode* temp = root->left;
        while(!st.empty() || temp != nullptr){
            while(temp != nullptr){
                st.push(temp);
                ans.push_back(temp->data);
                temp = temp->left;
            }
            temp = st.top()->right;
            st.pop();
        }

        return ans;
    }

    // Striver's solution: Mind-blowing!!

    vector<int> preorderTraversal(TreeNode* root){
        vector<int> ans;
        stack<TreeNode*> st;

        if(root == nullptr) return {};

        st.push(root);

        while(!st.empty()){
            TreeNode* temp = st.top();
            ans.push_back(temp->data);

            TreeNode* rightNode = temp->right;
            TreeNode* leftNode = temp->left; // We push it later so that we can access it first. (LIFO nature of stack)

            st.pop();

            if(rightNode != nullptr) st.push(rightNode);
            if(leftNode != nullptr) st.push(leftNode);
        }

        return ans;
    }
};

// T.C. = O(n)
 
// S.C. = O(h), where h is the height of the stack (recursive call stack or our own stack), which can be n in the worst case (degenerate binary tree) or log n base 2 in the best case (balanced binary tree). 

// Both recursive and iterative methods are same in T.C. & S.C. but it is good to know both because it will help our problem solving skills.
