#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};

// Using the recursive method for inorder traversal:
// T.C. = O(n), S.C. = O(n) which is the auxillary stack space. 
// The iterative method is also same in terms of time and space complexities. 

// The Morris Traversal takes nearly O(n) T.C. and O(1) S.C. It's speciality is that it does not consume any extra space. 
// How? It uses the concept of threaded binary tree. 

class Solution {
public:
    vector<int> getInorder(TreeNode* root) {
        vector<int> inorder;
    	if(root == nullptr) return inorder;
        TreeNode* curr = root;
        while(curr != nullptr){
            if(curr->left == nullptr){
                inorder.push_back(curr->data);
                curr = curr->right;
            }
            else{
                TreeNode* temp = curr->left;
                while(temp->right && temp->right != curr) temp = temp->right;

                if(temp->right == nullptr){
                    temp->right = curr;
                    curr = curr->left;
                }

                else{
                    temp->right = nullptr;
                    inorder.push_back(curr->data);
                    curr = curr->right;
                }
            }
        }
        return inorder;
    }
};