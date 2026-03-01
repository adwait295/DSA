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
    public:
    
    // Brute force solution: For each node, we try to find the longest path passing through that node (lh + rh of that node) i.e. that node is the curvepoint of the path.
    int height1(TreeNode* root){
        if(root == nullptr) return 0;

        int lh = height1(root->left);
        int rh = height1(root->right);

        return 1 + max(lh, rh);
    }

    int diameterOfBinaryTree1(TreeNode* root){
        if(root == nullptr) return 0;

        int lh = height1(root->left);
        int rh = height1(root->right);

        int diameter1 = lh + rh;

        int leftNodeDiameter = diameterOfBinaryTree1(root->left);
        int rightNodeDiameter = diameterOfBinaryTree1(root->right);

        return max({diameter1, leftNodeDiameter, rightNodeDiameter});
    }

    // T.C. = O(n^2) 
    // S.C. = O(H) The space complexity is determined by the maximum depth of the recursion stack, which corresponds to the height of the tree, H. Thus, the space complexity is O(H), which can go upto O(N) in case of skewed binary tree.

    // height1() bhi height1() ku call karuchi au diameterOfBinaryTree1() bhi height1() ku call karuchi sethipain O(n^2) heijauchi.

    //  In this approach, for each node, we calculate the height of its left and right subtrees, which takes O(N) time. Since this calculation is done for each of the N nodes in the tree, the total time complexity is O(N * N) = O(N^2)

    // Optimal solution (Striver's solution):

    //  A more efficient strategy is to calculate these heights in a bottom-up fashion using a Postorder traversal. This technique enables the validation of balance conditions and the computation of the diameter simultaneously during the traversal.

    public:
    int diameterOfBinaryTree2(TreeNode* root) {
        int diameter2 = 0;
        height2(root, diameter2);
        return diameter2;
    }

    private:
    int height2(TreeNode* node, int& diameter2) {
        // Passing the diameter2 by reference is necessary, otherwise the changes made to diameter2 in height2() will not reflect in the diameter2 variable of diameterOfBinaryTree2().

        // In JAVA, the variables can't be passed by reference, so to pass the variable, we can create an array with name diameter of size = 1 and then pass it by reference. 

        if (!node) {
            return 0;
        }

        int lh = height2(node->left, diameter2);
        int rh = height2(node->right, diameter2);

        diameter2 = max(diameter2, lh + rh);

        return 1 + max(lh, rh);
    }

    // T.C. = O(n)
    // S.C. = O(h) i.e. O(n) in case of a skewed B.T.

    // Optimal solution (My solution):

    public:
    int diameter = 0;

    int height(TreeNode* root){
        if(root == nullptr) return 0;

        int lh = height(root->left);
        int rh = height(root->right);

        diameter = max(diameter, lh + rh);

        return 1 + max(lh, rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;
    }

    // T.C. = O(n)
    // S.C. = O(n)

};