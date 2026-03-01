#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};

// My solution: Uff Mind blowing !! (Correct on the first attempt)
// I am not passing the vector by reference, so i don't have to pop back again and again while going upwards. 

class Solution {
   public:
    vector<vector<int>> ans;

    vector<vector<int>> allRootToLeaf(TreeNode* root) { 
		vector<int> rootToLeaf;
		traversal(root, rootToLeaf);
		return ans; 
	}

	void traversal(TreeNode* root, vector<int> vector){
		if(root == nullptr) return;
		vector.push_back(root->data);
		if(root->left == nullptr && root->right == nullptr) ans.push_back(vector);

		traversal(root->left, vector);
		traversal(root->right, vector);
	}
};

// Striver's solution: passing the current path vector and all root to leaf paths vector by reference so he has to pop back the current path vector each time before going upwards. 

// Concept of Striver's solution and my solution are same. 

// For all root to leaf paths:

class Solution{
    public:
    vector<vector<int>> allRootToLeaf(TreeNode* root){
        vector<vector<int>> allPaths;
        vector<int> currentPath;
        dfs(root, currentPath, allPaths);
        return allPaths;
    }

    private:
    void dfs(TreeNode* root, vector<int> &currentPath, vector<vector<int>> &allPaths){
        if(root == nullptr) return;
        currentPath.push_back(root->data);

        if(root->left == nullptr && root->right == nullptr) allPaths.push_back(currentPath);
        else {
            dfs(root->left, currentPath, allPaths);
            dfs(root->right, currentPath, allPaths);
        }
        
        currentPath.pop_back();
    }

    /*
    Time Complexity : O(N) where N is the number of nodes in the binary tree. Each node of the binary tree is visited exactly once during the traversal.

    Space Complexity : O(N) where N is the number of nodes in the binary tree. This is because the stack can potentially hold all nodes in the tree when dealing with a skewed tree (all nodes have only one child), consuming space proportional to the number of nodes.
    */
};

// Solution For root to 'node' path:  GOOD QUESTION - TRY IT ON YOUR OWN ONCE
// The question states that we have to find the path from the root to a particular node (node passed to the function) or a particular value (value passed to the function). The question states beforehand that the given node or value is always present in the binary tree. 

class Solution{
    public:
    vector<int> rootToNodePath(TreeNode* root, int B){
        // As value is given, so we have to find a node whose node->data is matching the given value and then we have to return the path of that node from root.
        vector<int> path;
        if(root == nullptr) return path;
        getPath(root, path, B);
        return path;
    }

    bool getPath(TreeNode* root, vector<int> &path, int x){
        if(root == nullptr) return false; // The path has ended and still we haven't found the value.
        path.push_back(root->data);

        // If we return true, this means we found the path and that is stored in the path vector right now (so we just need to go upwards without doing anything), this means while going upwards we don't need to pop back the elements as we have found our answer.

        // If we are returning false, this means the path (branch) we took doesn't have our answer and hence before returning false for that branch, we pop out the element from the path vector and then return false upwards. 

        if(root->data == x) return true; 
        if(getPath(root->left, path, x) || getPath(root->right, path, x)) return true;

        path.pop_back();
        return false;
    }
};
