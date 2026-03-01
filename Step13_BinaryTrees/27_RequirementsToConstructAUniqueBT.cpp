#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};

/*
Given: The traversals represented by integers:
1 -> Preorder
2 -> Inorder
3 -> Postorder

Given a pair of tree traversal, return true if a unique binary tree can be constructed using the two traversals, otherwise false.

The concept of "uniqueness" implies that there must be only one binary tree that matches the provided traversal sequences. Without this requirement, multiple trees could fit the same traversals, leading to ambiguity.

We can definitely create binary trees, the question asks - can we create a unique binary tree?

Solution:
A binary tree can only be uniquely constructed if: One of the traversals must be Inorder, because Inorder preserves the relative position of nodes. The second traversal must be either Preorder or Postorder

Why do we need Inorder for uniqueness?
Inorder preserves relative left and right positions, ensuring a consistent tree structure. Without Inorder, Preorder and Postorder alone are ambiguous.

Can a unique binary tree be reconstructed from only one traversal?
No, unless additional constraints (like BST properties) are given. A single traversal does not provide enough information about left vs. right children.

Can one DFS traversal uniquely define a binary tree?

If you are given only one traversal:

Preorder alone ❌

Inorder alone ❌

Postorder alone ❌

NOT sufficient
Multiple different trees can produce the same traversal.
Any single DFS traversal can represent multiple binary trees.

Why does this happen?

A single DFS traversal does not tell you where left subtree ends and right subtree begins.

Only inorder traversal gives positional separation.

When is the tree uniquely determined?
✅ Inorder + Preorder → UNIQUE tree
✅ Inorder + Postorder → UNIQUE tree

Because:

Inorder → tells left vs right subtree boundary

Pre/Post → tells root order

5. Special Case (important for exams & interviews)

Preorder + Postorder CAN form a unique tree
ONLY IF the tree is a:

✅ Full Binary Tree (every node has 0 or 2 children)

Otherwise ❌ ambiguous.

Intuition Trick (remember this)

✔ Need root info → Pre/Post
✔ Need left-right boundary → Inorder

👉 That’s why inorder is essential.

*/
// My solution:

class Solution{	
	public:	
		bool uniqueBinaryTree(int a, int b){
			if(a == 2 && b == 2) return false;
			if(a == 2 || b == 2) return true;
			return false;
		}
};

// Striver's solution:

class Solution {
public:
    bool uniqueBinaryTree(int a, int b) {
        // Return false if both traversals are the same 
        // or if they are preorder and postorder
        return !(a == b || (a == 1 && b == 3) || (a == 3 && b == 1));
    }
};


// T.C. = O(1)
// S.C. = O(1)