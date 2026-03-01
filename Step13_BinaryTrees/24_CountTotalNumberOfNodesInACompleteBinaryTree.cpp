#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};

// Brute force solution:

// My solution: Using any traversal(in, pre, post, level), everytime we visit a node, we increase the count by 1. 

class Solution {
public:
    int countNodes(TreeNode* root) { 
        int count = 0;
        if(root == nullptr) return count;
        dfs(root, count);
        return count;
    }
    private:
    void dfs(TreeNode* root, int &count){
        if(root == nullptr) return;

        // Preorder:
        count++;
        dfs(root->left, count);
        dfs(root->right, count);

        /*
        Inorder:
        dfs(root->left, count);
        count++;
        dfs(root->right, count);

        Postorder:
        dfs(root->left, count);
        dfs(root->right, count);
        count++;

        Where count occurs doesn't matter, the answer is same. Only the type of dfs changes. 
        */
    }

    // T.C. = O(n)
    // S.C. = O(log n) because it is told in the question that the tree is a complete binary tree, not a normal binary tree. 
};


// Optimal solution : Sexy solution !! - Applicable only because the tree is a complete binary tree

// The number of nodes of a complete binary tree = 2 ^ h - 1. where h is the height of the tree. 

// Approach:
// 1. We go on deeper and deeper from the root until we find a complete binary subtree. Wherever we find it, we don't go any further and directly use the formula to calculate the total number of nodes for that subtree. 
// 2. If our present considered subtree at any step is not a complete binary tree, then we use the formula -> total nodes = 1 + number of nodes on the left + number of nodes on the right and go deeper. 

class Solution{
    public:

    int countNodes(TreeNode* root){
        if(root == nullptr) return 0;

        // We calculate the left and right height of the current considered subtree including the current root. 
        int lh = leftHeight(root);
        int rh = rightHeight(root);

        if(lh == rh) return (1 << lh) - 1; 
        // If left height = right height, then the present considered subtree is a complete binary tree and hence number of nodes of the subtree = (2 ^ h) - 1. where h = lh = rh. Hence no need to calculate the height further in the subtree. 

        // If the present considered subtree is not a complete binary tree, we go deeper and use the formula, total nodes = 1(for the present root node) + number of nodes on the left + number of nodes on the right.
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    private:

    // This method of computation of left and right height is only possible because the given tree is a complete binary tree. 

    int leftHeight(TreeNode* root){ // Calculating extreme left height of the left branch (which will also be the actual (maximum) height of the left branch because in a complete binary tree, the leaf nodes are as left as possible)
        int height = 0;
        while(root != nullptr){
            height++;
            root = root->left;
        }
        return height;
    }

    // Now the sexy thing - visualize and you will understand for sure.

    int rightHeight(TreeNode* root){ // Calculating extreme right height of the right branch (not the actual (maximum) height of the right branch - both are different because in a complete binary tree, the leaf nodes are as left as possible, so it is possible that on left side - a leaf node is present but on right side - the leaf node is not present)
        int height = 0;
        while(root != nullptr){
            height++;
            root = root->right;
        }
        return height;
    }
};

// If you still don't get the solution, Striver is always there :)