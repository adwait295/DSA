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

// My solution:

class Solution{
    public:

    void leftBoundaryTraversal(TreeNode* root, vector<int> &ans){
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr) return;

        ans.push_back(root->data);

        if(root->left) leftBoundaryTraversal(root->left, ans);
        else leftBoundaryTraversal(root->right, ans);
    }

    void leafNodeTraversal(TreeNode* root, vector<int> &ans){
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr) ans.push_back(root->data);

        leafNodeTraversal(root->left, ans);
        leafNodeTraversal(root->right, ans);
    }

    void rightBoundaryTraversal(TreeNode* root, vector<int> &ans){
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr) return;

        if(root->right) rightBoundaryTraversal(root->right, ans);
        else rightBoundaryTraversal(root->left, ans);

        ans.push_back(root->data);
    }

    vector<int> boundary(TreeNode* root){
        vector<int> ans;
        if(root == nullptr) return ans;
        ans.push_back(root->data);

        leftBoundaryTraversal(root->left, ans);
        leafNodeTraversal(root->left, ans);
        leafNodeTraversal(root->right, ans);
        rightBoundaryTraversal(root->right, ans);

        return ans;
    }
};

// Striver's solution:

/*
If traversal is linear → loop
If traversal branches → recursion or stack

Additional knowledge:
Recursion is never a true necessity in programming (for problems solvable with finite memory).
It’s a convenience for expressing certain patterns — especially hierarchical or branching ones.

Anything recursive can be rewritten iteratively with an explicit stack.

But in practice, we treat some situations as “recursion-necessary” because the iterative version becomes ugly or error-prone.
*/

class Solution{

    private:

    bool isLeaf(TreeNode* root){
        if(root->left == nullptr && root->right == nullptr) return true;
        return false;
    }

    void leftBoundaryTraversal(TreeNode* root, vector<int> &ans){
        TreeNode* currNode = root->left;
        while(currNode != nullptr){
            if(!isLeaf(currNode)) ans.push_back(currNode->data);
            if(currNode->left) currNode = currNode->left;
            else currNode = currNode->right;
        }
    }

    void leafNodeTraversal(TreeNode* root, vector<int> &ans){
        if(isLeaf(root)) ans.push_back(root->data);
        if(root->left != nullptr) leafNodeTraversal(root->left, ans);
        if(root->right != nullptr) leafNodeTraversal(root->right, ans);
    }

    void rightBoundaryTraversal(TreeNode* root, vector<int> &ans){
        TreeNode* currNode = root->right;
        vector<int> temp;
        while(currNode != nullptr){
            if(!isLeaf(currNode)) temp.push_back(currNode->data);
            if(currNode->right) currNode = currNode->right;
            else currNode = currNode->left;
        }
        for(int i=temp.size()-1;i>=0;i--) ans.push_back(temp[i]);
    }

    public:
    vector<int> boundary(TreeNode* root){
        vector<int> ans;
        if(root == nullptr) return ans;
        if(!isLeaf(root)) ans.push_back(root->data);

        leftBoundaryTraversal(root, ans);
        leafNodeTraversal(root, ans);
        rightBoundaryTraversal(root, ans);

        return ans;
    }
};