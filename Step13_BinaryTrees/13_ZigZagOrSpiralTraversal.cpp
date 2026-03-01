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

// My solution:

class Solution{
    public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root){
        vector<vector<int>> ans;
        if(root == nullptr) return ans;

        queue<TreeNode*> q;
        q.push(root);

        int leftRightFlag = 1;

        while(!q.empty()){
            int size = q.size();
            vector<int> levels;
            for(int i=1;i<=size;i++){
                TreeNode* temp = q.front();
                q.pop();

                TreeNode* leftNode = temp->left;
                TreeNode* rightNode = temp->right;
                if(leftNode != nullptr) q.push(leftNode);
                if(rightNode != nullptr) q.push(rightNode);

                levels.push_back(temp->data);
            }
            if(leftRightFlag == -1) reverse(levels.begin(), levels.end());
            ans.push_back(levels);
            leftRightFlag *= -1;
        }

        return ans;
    }
};

// T.C. = O(n + n + n) = O(3n) = O(n)
/*
Each element is pushed(enqueued) once (n) & popped(dequeued) once (n).
We are NOT reversing n elements each time.
We are reversing disjoint subsets whose total size = n. So reverse() takes a total of O(n) at max although we know it does not reverse total n elements but close to n/2 elements as it reverses only alternate levels.
*/

// Striver's solution:

class Solution{
    public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root){
        vector<vector<int>> ans;
        if(root == nullptr) return ans;

        queue<TreeNode*> q;
        q.push(root);

        int leftRightFlag = true;

        while(!q.empty()){
            int size = q.size();
            vector<int> levels(size);
            for(int i=0;i<size;i++){
                TreeNode* temp = q.front();
                q.pop();

                TreeNode* leftNode = temp->left;
                TreeNode* rightNode = temp->right;
                if(leftNode != nullptr) q.push(leftNode);
                if(rightNode != nullptr) q.push(rightNode);

                int index = leftRightFlag? i : size - i - 1;

                levels[index] = temp->data;
            }
            ans.push_back(levels);
            leftRightFlag = !leftRightFlag;
        }

        return ans;
    }
};

// T.C. = O(2n) = O(n); The total cost of O(n) for reversing alternate levels is avoided by this approach. 