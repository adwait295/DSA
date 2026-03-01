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

    map<int, vector<pair<int, int>>> mpp;

    static bool comp(pair<int, int> &a, pair<int, int> &b){
        return a.first < b.first;
    }

    void traversal(TreeNode* root, int row, int column){
        if(root == nullptr) return;
        mpp[column].push_back({row, root->data});
        traversal(root->left, row+1, column-1);
        traversal(root->right, row+1, column+1);
    }

    vector<int> topView(TreeNode *root){
        vector<int> ans;
        traversal(root, 0, 0);

        for(auto it: mpp){
            auto vectorr = it.second;
            sort(vectorr.begin(), vectorr.end(), comp);
            ans.push_back(vectorr[0].second);
        }

        return ans;
    }
};

/*
Time Complexity → O(n log n)

DFS visits each node once → n

Each insertion into map costs log n → n log n

Sorting all stored nodes across all columns totals n log n

Iterating the map is O(n) (not log n per step)

👉 Total = O(n log n)

Space Complexity → O(n)

Map + vectors store each node once → O(n)

Recursion stack worst case (skewed tree) → O(n)

👉 Total = O(n)
*/

// Striver's solution:

class Solution{
    public:

    vector<int> topView(TreeNode* root){
        vector<int> ans;
        if(root == nullptr) return ans;
        map<int, int> mpp;
        queue<pair<TreeNode*, int>> q; // storing only column number because we do not have to store the entire column from top to bottom for which we would require a row number.
        q.push({root, 0});
        while(!q.empty()){
            auto p = q.front(); q.pop();
            TreeNode* node = p.first;
            int colNum = p.second;
            if(mpp.find(colNum) == mpp.end()) mpp[colNum] = node->data;

            if(node->left) q.push({node->left, colNum-1});
            if(node->right) q.push({node->right, colNum+1});
        }

        for(auto it: mpp) ans.push_back(it.second);

        return ans;
    }
};

// T.C. = O(N log N) where N is the number of nodes in the Binary Tree.
// This complexity arises because the algorithm performs a Breadth-First Search (BFS) traversal of the tree, visiting each node exactly once. And during the traversal, various map operations are performed which take log K complexity where K can be N in the worst case. Thus, the overall time complexity comes out to be O(N*logN).

// S.C. = The space complexity of the algorithm is O(N), where N is the number of nodes in the Binary Tree. This space is primarily consumed by the queue used for BFS traversal, which can hold up to N/2 nodes in the worst case scenario of a balanced tree. Additionally, a map is used to store nodes based on their vertical positions, potentially also using up to N/2 entries in the worst case. Therefore, the overall space usage is proportional to the maximum width of the tree at any level.