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

    bool checkSymmetric(TreeNode* left, TreeNode* right){
        if(left == nullptr && right == nullptr) return true;
        if(left == nullptr || right == nullptr) return false;

        if(left->data != right->data) return false;

        return checkSymmetric(left->left, right->right) && checkSymmetric(left->right, right->left);
    }
    
    bool isSymmetric(TreeNode* root){
        if(root == nullptr) return true;
        return checkSymmetric(root->left, root->right);
    }
};

// Iterative implementation:

/* 
Converting recursion logic to iterative thinking, instead of using a recursion stack, we explicitly store pairs to compare. 

KEY IDEA: Using a queue (BFS traversal) or a stack (DFS traversal) to hold "node pairs".

Iterative approach is basically "literally simulating recursion manually".
*/

class Solution{
    public:
    bool isSymmetric(TreeNode* root){
        if(root == nullptr) return true;

        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root->left, root->right});

        while(!q.empty()){
            auto [a, b] = q.front();
            q.pop();

            if(a == nullptr && b == nullptr) return true;
            if(a == nullptr || b == nullptr) return false;

            if(a->data != b->data) return false;

            q.push({a->left, b->right});
            q.push({a->right, b->left});
        }

        return true;
    }
};

// Both recursive and iterative implementations are :

// T.C. = O(n)
// S.C. = O(h)

// The stack and queue versions are identical, we just switch from BFS to DFS traversal. We store the same pair of nodes, just in a stack instead of a queue. Rest everything is same. 

// Traversals are different, comparisions are same. 

//The correctness does NOT depend on order

// Because symmetry condition is local to each pair

// We aren’t computing levels or distances — just validating mirror structure.

// So either works.

// These concepts of converting recursion into iterative comes across many tree problems. 