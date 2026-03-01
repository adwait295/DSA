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

    // Recursive:
    bool isSameTree(TreeNode* p, TreeNode* q) {
       if(p == nullptr && q == nullptr) return true;
       if(p == nullptr || q == nullptr) return false; // Hmm Interesting!! (because of the previous statement, this statement works perfectly in sync)

        return (p->data == q->data) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

        // T.C. = O(n) because we visit each node of both trees once during the traversal simultaneously.

        // S.C. = O(h), where h is the height of the recursion stack which can go as high as n. 
    }

    // Iterative:
    bool isSameTree1(TreeNode* p, TreeNode* q){
        if(p == nullptr && q == nullptr) return true;
        if(p == nullptr || q == nullptr) return false;

        stack<TreeNode*> st1;
        stack<TreeNode*> st2;

        st1.push(p), st2.push(q);

        while(!st1.empty() && !st2.empty()){
            TreeNode* head1 = st1.top();
            TreeNode* head2 = st2.top();

            if(head1->data != head2->data) return false;
            st1.pop(), st2.pop();

            TreeNode* leftNode1 = head1->left;
            TreeNode* leftNode2 = head2->left;
            TreeNode* rightNode1 = head1->right;
            TreeNode* rightNode2 = head2->right;

            if(leftNode1 != nullptr && leftNode2 == nullptr || leftNode1 == nullptr && leftNode2 != nullptr) return false;

            if(rightNode1 != nullptr && rightNode2 == nullptr || rightNode1 == nullptr && rightNode2 != nullptr) return false;

            if(leftNode1 != nullptr) st1.push(leftNode1);
            if(leftNode2 != nullptr) st2.push(leftNode2);
            if(rightNode1 != nullptr) st1.push(rightNode1);
            if(rightNode2 != nullptr) st2.push(rightNode2);
        }

        return true;

        // T.C. = O(n) because we visit each node of both trees once during the traversal simultaneously.

        // S.C. = O(2h), each h because of each stack which can go upto n each for a degenerative BT.

        // Constants don't matter in T.C. and S.C. anyway. 
    }
};