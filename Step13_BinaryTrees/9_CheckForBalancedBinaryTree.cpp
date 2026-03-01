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

// Brute force solution:

int height(TreeNode* root){
    if(root == nullptr) return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    return 1 + max(lh, rh);
}

bool isBalanced(TreeNode *root){
    if(root == nullptr) return true;
	if(isBalanced(root->left) && isBalanced(root->right) && abs(height(root->left) - height(root->right)) <= 1) return true;
    return false;
}

// height() bhi height() ku call karuchi au isBalanced() bhi height() ku call karuchi sethipain O(n^2) heijauchi.

// T.C. = O(n^2), n for visiting each node for checking left and right and n for finding the height of left and right for that node.

// ---------------- BRUTE FORCE IDEA ----------------
//
// For EVERY node:
//   1. Recursively check if left subtree is balanced
//   2. Recursively check if right subtree is balanced
//   3. Compute height(left)  -> traverses whole left subtree
//   4. Compute height(right) -> traverses whole right subtree
//
// ⚠️ IMPORTANT:
// height() itself is O(size_of_subtree)
// And we call height() AGAIN for many nodes.
//
// In worst case (skewed tree):
//
// Node1 -> height() visits ~n nodes
// Node2 -> height() visits ~n-1 nodes
// Node3 -> height() visits ~n-2 nodes
// ...
//
// Total work:
//
// n + (n-1) + (n-2) + ... + 1
// = n(n+1)/2
// = O(n^2)
//
// 🧠 Intuition for future me:
// We recompute heights again and again.
// Same subtree scanned multiple times.
// That's why it becomes quadratic.
//
// Space Complexity:
// Recursion stack depth can go up to O(n) in skewed tree.
 

// Optimal solution:

/*
Intuition:
The O(N*N) time complexity of the previous method can be improved by incorporating the balance check directly within the tree traversal process. Instead of recalculating the heights of the left and right subtrees at each node repeatedly, these heights can be determined in a bottom-up fashion via postorder traversal(using recursion). This method allows for the efficient validation of balance conditions during traversal, minimizing redundant computations and enabling the early identification of unbalanced nodes.
*/

int height1(TreeNode* root){
    if(root == nullptr) return 0;

    int lh = height1(root->left);
    if(lh == -1) return -1;

    int rh = height1(root->right);
    if(rh == -1) return -1;

    if(abs(lh - rh) > 1) return -1;

    return 1 + max(lh, rh);
}

bool isBalanced1(TreeNode* root){
    return height1(root) != 1;
}

// T.C. = O(n) for visiting each node for checking left and right and finding height of left and right subtree at the same time, simultaneously.

// ---------------- OPTIMAL IDEA ----------------
//
// Instead of computing height separately,
// we combine TWO tasks into ONE traversal:
//
//   ✔ Compute height
//   ✔ Check balance
//
// height1() returns:
//   -> actual height (if subtree is balanced)
//   -> -1 (if subtree is NOT balanced)
//
// Trick:
// If left or right returns -1,
// we immediately propagate -1 upward.
// No extra traversals.
//
// KEY DIFFERENCE FROM BRUTE:
//
// Each node is visited ONLY ONCE.
// We never recompute subtree heights.
//
// So total work:
//
// visit node1 once
// visit node2 once
// ...
// visit noden once
//
// => O(n)
//
// 🧠 Intuition for future me:
// This is just a single DFS traversal.
// No repeated subtree scanning.
// That's why it becomes linear.
//
// Space Complexity:
// Recursion stack = tree height = O(h)
// Worst case skewed -> O(n)


// So overally:

// REMEMBER:
// Brute = "recalculate heights many times"
// Optimal = "calculate height while checking balance in one DFS"

// When revising after months, just ask:

// ❓ Are we recomputing subtree information?

// YES → Probably O(n²)

// NO → Probably O(n)

// That single question saves tons of time in contests.
