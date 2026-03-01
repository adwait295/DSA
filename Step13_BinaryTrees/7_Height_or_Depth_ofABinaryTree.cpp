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

class Solution {
public:

    // Recursive implementation:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;

        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        return 1 + max(lh, rh);
    }

    // Iterative implementation using Level Order Traversal:
    int maxDepth1(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<TreeNode*> q;

        q.push(root);

        int count = 0;
        while(!q.empty()){
            count++;
            int size = q.size();
            for(int i=1;i<=size;i++){
                TreeNode* temp = q.front();
                q.pop();

                TreeNode* leftNode = temp->left;
                TreeNode* rightNode = temp->right;
                if(leftNode != nullptr) q.push(leftNode);
                if(rightNode != nullptr) q.push(rightNode);
            }
        }

        return count;
    }

    // Both recursive and iterative implementations take O(n) T.C. 
    /*
    For recursive, S.C. = O(h), h is for maximum height, the maximum S.C. = O(n) when the binary tree is degenerative. In that case, iterative is better.
    For iterative, S.C. = O(w) , w is for maximum width, the maximum S.C. = O(n) when the binary tree is balanced. In that case, recursive is better. 

    So both have same T.C. and similar wort case S.C. and therefore we can use either of them whenever we like to (we even know the preferences now written above). 
    */
};