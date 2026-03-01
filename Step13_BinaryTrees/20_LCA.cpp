#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};

// Brute force solution:

// My solution: Getting paths from root to node for both nodes and then finding out the last common between them. 

class Solution {

private:
    vector<TreeNode*> ppath(TreeNode* root, TreeNode* p){ // root to p path
        vector<TreeNode*> path = {};
        getPath(root, p, path); // O(n) T.C.
        return path;
    }
    vector<TreeNode*> qpath(TreeNode* root, TreeNode* q){ // root to q path
        vector<TreeNode*> path = {};
        getPath(root, q, path); // O(n) T.C.
        return path;
    }
    bool getPath(TreeNode* root, TreeNode* node, vector<TreeNode*> &path){
        if(root == nullptr) return false;
        path.push_back(root);
        if(root == node) return true;

        if(getPath(root->left, node, path) || getPath(root->right, node, path)) return true;

        path.pop_back();
        return false;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1 = ppath(root, p); // O(n) S.C.
        vector<TreeNode*> path2 = qpath(root, q); // O(n) S.C.

        TreeNode* lastCommonNode = nullptr;
        // Finding the last common node between two paths: O(n^2) T.C. 
        for(int i=0;i<path1.size();i++){
            TreeNode* temp = path1[i];
            for(int j=0;j<path2.size();j++){
                if(temp == path2[j]) lastCommonNode = temp;
            }
        }

        return lastCommonNode;
    }

    // T.C. = O(n + n + n^2)
    // S.C. = O(n + n)
};

// Optimal solution:

// Striver's solution: 

class Solution{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == nullptr || root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left == nullptr) return right;
        else if(right == nullptr) return left;
        else return root;
    }

    // T.C. = O(n) for a single DFS traversal
    // S.C. = O(n) for auxillary recursive stack space. 
};