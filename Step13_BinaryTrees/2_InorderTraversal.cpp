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

// Recursive implementation:

// My solution:

class Solution1 {
   public:
   
    vector<int> ans;
    vector<int> inorder(TreeNode* root) {
        if (root == nullptr) return ans;

        // cout << "yes" << endl;

        inorder(root->left);
        ans.push_back(root->data);
        inorder(root->right);

        return ans;
    }
};

// Striver's solution:

class Solution{
    private:

    void recursiveInorder(TreeNode* root, vector<int> &arr){
        if(root == nullptr) return;

        recursiveInorder(root->left, arr);
        arr.push_back(root->data);
        recursiveInorder(root->right, arr);
    }

    public:

    vector<int> inorder(TreeNode* root){
        vector<int> arr;

        recursiveInorder(root, arr);

        return arr;
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(7);

    Solution sol = Solution();
    // Solution1 sol = Solution1();

    vector<int> ans = sol.inorder(root);

    cout << "Inorder Traversal: ";

    for(auto it: ans) cout << it << " ";

    cout << endl;

    return 0;
}

// T.C. = O(n), where n is the number of nodes in the binary tree, due to the traversal of each node once. 
/*

S.C. = O(h), where h is the height of the tree for the recursion stack.

The h can be n in the worst case, when we are given a degenerate binary tree.

In case of a balanced binary tree, h will be log n base 2. Because in case of balanced binary tree, the depth won't be much i.e. the tree will be shrinked because of the balancing out on each side of every node of the tree. 

*/ 

// O(n) extra space is used just to return the answer. 




// Iterative implementation:

/*
In recursive implementation, we used to come back to a node to access it after we were done with it's left part. That coming back was possible due to the recursive call stack (because recursion remembers where the call originated from), otherwise we had no other way to come back up because we don't have a pointer to the parent node of a node.

So in the iterative method, we will use a stack ourselves (i.e. a stack of our own) which will remember where the call was originated from, similar to the recursive call stack. By doing that, we can convert the recursive solution into an iterative solution. 
*/

// My solution:

vector<int> inorder(TreeNode* root){
    vector<int> ans;
    stack<TreeNode*> st;

    st.push(root);
    TreeNode* temp = root->left;
    while(!st.empty() || temp != nullptr){
        while(temp != nullptr){
            st.push(temp);
            temp = temp->left;
        }
        TreeNode* node = st.top();
        ans.push_back(node->data);
        temp = node->right;
        st.pop();
    }

    return ans;
}

// Striver's solution:

vector<int> inorder(TreeNode* root){
    vector<int> ans;
    stack<TreeNode*> st;

    st.push(root);
    TreeNode* node = root->left;

    while(true){
        if(node != nullptr){
            st.push(node);
            node = node->left;
        }
        else{
            if(st.empty()) break;
            else{
                TreeNode* temp = st.top();
                ans.push_back(temp->data);
                node = temp->right;
                st.pop();
            }
        }
    }

    return ans;
}


// Both the recursive and iterative approaches will have the same T.C. and S.C. as both are traversing n nodes and using a call stack. In the recursive approach, we are not using the stack by ourselves but it is being used on the inside, so ultimately it's the same. 

// In an interview, we should explain both the approaches because that will showcase that how much we know the topic in depth and it will leave a very very lasting impact. 