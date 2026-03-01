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

// Brute force solution:
// We take a particular node and think of it as the curving point of a path.
// We just think of two nodes at a time i.e. the left child node A and the right child node B and we try to calculate path sum from Node A to Node B. Everything works out from this simple thought as we write the recursion which covers every node we need eventually. So in recursion, start simple (i.e. as small problem as possible; solve it and then eventually the bigger problems will be solved with little tweaks)

class Solution{
    public:
    int maxi = INT_MIN;

    int pathSum(TreeNode* root){
        if(root == nullptr) return 0;

        int leftPathSum = max(0, pathSum(root->left));
        int rightPathSum = max(0, pathSum(root->right));

        return root->data + max(leftPathSum, rightPathSum);
    }

    int maxPathSum(TreeNode* root){
        if(root == nullptr) return 0;

        int leftPathSum = max(0, pathSum(root->left));
        int rightPathSum = max(0, pathSum(root->right));

        maxi = max(maxi, root->data + leftPathSum + rightPathSum);

        maxPathSum(root->left);
        maxPathSum(root->right);

        return maxi;
    }

    // T.C. = O(n^2)
    // S.C. = O(h)
};

// Optimal solution(my solution):

class Solution {
public:
    int maxPathSumm = INT_MIN;
    int pathSum(TreeNode* root){
        if(root == nullptr) return 0;

        int leftPathSum = max(0, pathSum(root->left));
        int rightPathSum = max(0, pathSum(root->right));

        maxPathSumm = max(maxPathSumm, root->data + leftPathSum + rightPathSum);

        return root->data + max(leftPathSum, rightPathSum);
    }

    int maxPathSum(TreeNode* root){
        pathSum(root);
        return maxPathSumm;
    }

    // T.C. = O(n)
    // S.C. = O(h)
};