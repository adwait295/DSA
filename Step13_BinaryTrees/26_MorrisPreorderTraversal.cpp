#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};

class Solution {
   public:
    vector<int> preorder(TreeNode* root) { 
		vector<int> preorder;
		if(root == nullptr) return preorder;
		TreeNode* curr = root;
		while(curr){
			if(curr->left == nullptr){
				preorder.push_back(curr->data);
				curr = curr->right;
			}
			else{
				TreeNode* temp = curr->left;
				while(temp->right && temp->right != curr) temp = temp->right;

				if(temp->right == nullptr){
					temp->right = curr;
					preorder.push_back(curr->data);
					curr = curr->left;
				}

				else{
					temp->right = nullptr;
					curr = curr->right;
				}
			}
		} 
		return preorder;
	}
};

// T.C. = O(n)
// S.C. = O(1)