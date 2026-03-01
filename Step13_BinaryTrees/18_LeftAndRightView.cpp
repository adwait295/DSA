#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};

// My solution:

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i=1;i<=size;i++){
                TreeNode* temp = q.front(); q.pop();
                if(i == size) ans.push_back(temp->data);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }

        return ans;
    }

    vector<int> leftSideView(TreeNode* root){
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i=1;i<=size;i++){
                TreeNode* temp = q.front(); q.pop();
                if(i == 1) ans.push_back(temp->data);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }

        return ans;
    }
};

// Striver's solution:

// Brute solution: BFS

class Solution{
    public:
    vector<int> rightSideView(TreeNode* root){
        vector<int> ans;
        if(root == nullptr) return ans;

        vector<vector<int>> levelOrderTraversal = levelOrder(root);

        for(auto level: levelOrderTraversal) ans.push_back(level.back());

        return ans;
    }

    vector<int> leftSideView(TreeNode* root){
        vector<int> ans;
        if(root == nullptr) return ans;

        vector<vector<int>> levelOrderTraversal = levelOrder(root);

        for(auto level: levelOrderTraversal) ans.push_back(level.front());

        return ans;
    }

    private:
    vector<vector<int>> levelOrder(TreeNode* root){
        vector<vector<int>> levelOrderTraversal;
        if(root == nullptr) return levelOrderTraversal;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level(size, 0);
            for(int i=0;i<size;i++){
                TreeNode* temp = q.front(); q.pop();
                level[i] = temp->data;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            levelOrderTraversal.push_back(level);
        }

        return levelOrderTraversal;
    }

    /* =========================================================
   SPACE COMPLEXITY ANALYSIS — LEFT & RIGHT SIDE VIEW
   =========================================================

   Let n = number of nodes in the tree
   Let h = height of the tree

   ---------------------------------------------------------
   COMPONENT            SPACE     REASON
   ---------------------------------------------------------

   Queue (BFS)          O(n)
   → stores nodes of one level at a time
   → worst case (complete tree) last level ≈ n/2 nodes

   2D vector storing    O(n)
   level order          → stores every node value once
   traversal              across all levels

   Answer vector        O(n)
   → stores one node per level
   → worst case (skewed tree) levels = n

   ---------------------------------------------------------
   TOTAL SPACE          O(n)
   ---------------------------------------------------------

   WHY NOT MORE?

   ✔ Each node value stored at most once
   ✔ Queue never holds more than n nodes
   ✔ No extra recursive stack used

   ---------------------------------------------------------
   NOTE (Optimization Insight)
   ---------------------------------------------------------
   We do NOT need to store the full level order.

   We can compute side view during BFS:
       → queue  : O(n)
       → answer : O(h)

   Still O(n) worst case, but less memory usage.

   =========================================================
*/


};

// T.C. = O(n)
// S.C. = O(n) The space complexity is determined by the maximum number of nodes stored in the queue at any point during the traversal. In the worst case, this could be all nodes of the last level of the binary tree, which could amount to N/2 nodes.




// Optimal solution: Good one.
// DFS - (root, right, left) for right side view and (root, left, right) for left side view. 

// In an interview, the more clean, the more short, the more crisp solution we write, it will give us more advantage. 

class Solution{
    public:

    vector<int> rightSideView(TreeNode* root){
        vector<int> ans;
        recursionRight(root, 0, ans);
        return ans;
    }

    vector<int> leftSideView(TreeNode* root){
        vector<int> ans;
        recursionLeft(root, 0, ans);
        return ans;
    }

    private:
    
    void recursionRight(TreeNode* root, int level, vector<int> &ans){
        if(root == nullptr) return;

        if(level == ans.size()) ans.push_back(root->data); // Whenever it comes across a level which is not already filled by the rightmost, it fills it; otherwise it moves on to the next level.

        recursionRight(root->right, level+1, ans);
        recursionRight(root->left, level+1, ans);
    }

    void recursionLeft(TreeNode* root, int level, vector<int> &ans){
        if(root == nullptr) return;

        if(level == ans.size()) ans.push_back(root->data); // Whenever it comes across a level which is not already filled by the leftmost, it fills it; otherwise it moves on to the next level.

        recursionLeft(root->left, level+1, ans);
        recursionLeft(root->right, level+1, ans);
    }

    // T.C. = O(n), same as brute force BFS solution
    // S.C. = O(h), which is log n base 2 in best case (full binary tree) and n in the worst case (skewed binary tree) which is almost never given.
    // In brute solution, the S.C. was O(n/2) in the worst case (full binary tree) which was a lot.
};