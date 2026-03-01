#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};

// We can create a unique binary tree using preorder and inorder because "an inorder of a binary tree is unique if that tree's preorder is given". i.e. in other words, if the preorder and inorder of the same tree is given, the tree we make using both of them combined, will surely be a unique binary tree.

class Solution{
public:
    TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder){
        unordered_map<int, int> inMap; // O(n) S.C. 

        for(int i=0;i<inorder.size();i++){
            inMap[inorder[i]] = i;
        }

        TreeNode* root = buildTree(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, inMap);

        return root;
    }

private:
    TreeNode* buildTree(vector<int> &postorder, int postStart, int postEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> &inMap){
        if(postStart > postEnd || inStart > inEnd) return nullptr;

        TreeNode* root = new TreeNode(postorder[postEnd]);

        int inRoot = inMap[root->data];
        int numsLeft = inRoot - inStart;

        root->left = buildTree(postorder, postStart, postStart+numsLeft-1, inorder, inStart, inRoot-1, inMap);

        root->right = buildTree(postorder, postStart+numsLeft, postEnd-1, inorder, inRoot+1, inEnd, inMap);

        return root;
    }    

    // T.C. = O(n) because each node of the B.T. is visited once due to recursion.
    // S.C. = O(n) (due to inorder hashmap) + O(h) (auxillary stack space due to recursion, where h is the height of the binary tree) 
};
