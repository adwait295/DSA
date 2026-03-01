#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};

// My solution:

vector<int> floorCeilofBST(TreeNode* root, int key){
    int floor = INT_MIN, ceil = INT_MAX;
	while(root != nullptr && root->data != key){
		int data = root->data;
		if(data <= key && data > floor) floor = data;
		if(data >= key && data < ceil) ceil = data;
		root = key < data ? root->left : root->right;
	}
	if(floor == INT_MIN) floor = -1;
	if(ceil == INT_MAX) ceil = -1;
	if(root == nullptr) return {floor, ceil};
	else return {key, key};
}

// Other version of my solution:

vector<int> floorCeilofBST(TreeNode* root, int key){
    int floor = -1, ceil = -1;
	while(root != nullptr && root->data != key){
		int data = root->data;
		if(data < key) floor = data;
		if(data > key) ceil = data;
		root = key < data ? root->left : root->right;
	}
	if(root == nullptr) return {floor, ceil};
	else return {key, key};
}

// Striver's solution:

vector<int> floorCeilofBST(TreeNode* root, int key){
    int floor = -1, ceil = -1;

    TreeNode* current = root;

    while(current){
        if(current->data == key){
            floor = key;
            ceil = key;
            break;
        }

        if(current->data < key){
            floor = current->data;
            current = current->right;
        }
        else{
            ceil = current->data;
            current = current->left;
        }
    }

    return {floor, ceil};
}

// All solutions are O(n) T.C. (in the worst case obv) & O(1) S.C. 