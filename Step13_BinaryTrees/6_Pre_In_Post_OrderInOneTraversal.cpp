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

class Solution{
    vector<vector<int> > treeTraversal(TreeNode* root){
		vector<vector<int>> ans;
		vector<int> Pre, In, Post;
		stack<pair<TreeNode*, int>> st;

		if(root == nullptr) return {{}, {}, {}};

		st.push({root, 1});

		while(!st.empty()){
			auto it = st.top(); // or auto [node, num] = st.top();
			// Basically it.first is 'node', and it.second is 'num'.
			st.pop(); // We remove it from the stack so that we can update its count and put it back again if the count is 2 or 3 after updating.

			if(it.second == 1){ // or num == 1
				Pre.push_back(it.first->data); // node->data
				it.second++; // num++;
				st.push(it); // st.push({node, num})
				
				if(it.first->left != nullptr) st.push({it.first->left, 1});
			}

			else if(it.second == 2){
				In.push_back(it.first->data);
				it.second++;
				st.push(it);

				if(it.first->right != nullptr) st.push({it.first->right, 1});
			}

			else{
				Post.push_back(it.first->data);
			}
		}
		
		return {In, Pre, Post};
	}
};