#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};

// My solution: Recursion

class Solution {	
public:	
    TreeNode* searchBST(TreeNode* root, int val) {
    	if(root == nullptr) return nullptr;

        if(val == root->data) return root;
        if(val < root->data) return searchBST(root->left, val);
        return searchBST(root->right, val);
    }
    // T.C. = O(log n)
    // S.C. = O(h) which is the auxillary stack space due to recursion which at worst can be log n.
};

// Striver's solution: Iteration

class Solution{
public: 
    TreeNode* searchBST(TreeNode* root, int val){
        while(root != nullptr && root->data != val){
            root = val < root->data ? root->left : root->right;
        }
        return root;
    }

    // T.C. = O(log n)
    // S.C. = O(1)
};