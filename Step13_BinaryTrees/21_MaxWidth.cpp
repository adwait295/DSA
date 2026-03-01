#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};

// My solution: After watching editorial video

int widthOfBinaryTree(TreeNode* root) {
    int maxWidth = 0;
    if(root == nullptr) return maxWidth;
    queue<pair<TreeNode*, long long>> q; // After normalizing indices, if it still overflows (in leetcode), so we take indexes as long long. I came to know this because for a test case, it showed error in leetcode even after normalizing.
    q.push({root, 0});

    while(!q.empty()){
        int size = q.size();
        maxWidth = max(maxWidth, (int)q.back().second - (int)q.front().second + 1); // both data types of the max() should be same for comparision. If one is int, then the other should also be int. 
        int minIndex = q.front().second;

        for(int i=0;i<size;i++){
            auto [node, index] = q.front();
            q.pop();
            index -= minIndex; // Normalize to prevent overflow.
            if(node->left) q.push({node->left, 2 * index + 1});
            if(node->right) q.push({node->right, 2 * index + 2});
        }
    }

    return maxWidth;
}


// Striver's solution: Obv same method just diff way of writing.
// His solution will show error for a particular test case on leetcode for which i did queue<pair<TreeNode*, long long>> q; in my code. 


int widthOfBinaryTree(TreeNode* root) {
    if(!root) return 0;
    int ans = 0;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    while(!q.empty()){
        int size = q.size();
        int mmin = q.front().second;
        int first, last;

        for(int i = 0; i < size; i++){
            int cur_id = q.front().second - mmin;
            TreeNode* node = q.front().first;
            q.pop();
            if(i == 0) first = cur_id;
            if(i == size - 1) last = cur_id;
            if(node->left) q.push({node->left, cur_id*2 + 1}); // It will show error here if i submit on leetcode causing overflow. 
            if(node->right) q.push({node->right, cur_id*2 + 2});
        }

        ans = max(ans, last - first + 1);
    }
    
    return ans;
}

// For both solutions:
// T.C. = O(n) for level order traversal.
// S.C. = O(n), n/2 in the worst case when queue has to hold all the nodes of the last level of the Binary Tree when it's a complete binary tree.
