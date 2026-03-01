#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};

// I obviously could not solve the problem.

class Solution{
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track){
        if(root == nullptr) return;
        parent_track[root] = nullptr;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front(); q.pop();
            if(temp->left){
                parent_track[temp->left] = temp;
                q.push(temp->left);
            }
            if(temp->right){
                parent_track[temp->right] = temp;
                q.push(temp->right);
            }
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k){
        unordered_map<TreeNode*, TreeNode*> parent_track; // to map each node with its parent node. 
        markParents(root, parent_track);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target); 
        // Approach:
        // target node ru start kariba au sabu directions(left, right, parent) re jiba gote unit at a time. jo node re bhi pahanchuche, taara bhi left, right au parent achi. ta semti agaku jiba sabu directions re each node paain au jetebele bhi jauche ko patte bhi, distance++ kariba. jetebele sabu directions re distance = k heijiba from target, sethi break karideba au q re jaha thiba se nodes guda sabu target thu k distance re achanti. Its like a chain reaction starting from 'target'.
        visited[target] = true;
        int currDist = 0;
        while(!q.empty()){
            int size = q.size();
            if(currDist++ == k) break;
            for(int i=0;i<size;i++){
                TreeNode* currNode = q.front(); q.pop();
                // Left subtree:
                if(currNode->left && visited[currNode->left] != true){
                    q.push(currNode->left);
                    visited[currNode->left] = true;
                }
                // Right subtree:
                if(currNode->right && visited[currNode->right] != true){
                    q.push(currNode->right);
                    visited[currNode->right] = true;
                }
                // Parent:
                if(parent_track[currNode] && visited[parent_track[currNode]] != true){
                    q.push(parent_track[currNode]);
                    visited[parent_track[currNode]] = true;
                }
            }
        }

        vector<int> res;
        while(!q.empty()){
            TreeNode* temp = q.front(); q.pop();
            res.push_back(temp->data);
        }

        return res;
    }
};

/*
Time Complexity: Traversing the tree to create the parent hashmap requires visiting each node once (O(N)), exploring all nodes at a distance of 'K' in the worst case is O(N), and the logarithmic lookup time for the hashmap is O(log N) if we use ordered map. Therefore, the overall time complexity simplifies to O(N).

Space Complexity: The space complexity is determined by the data structures used: O(N) for the parent hashmap, O(N) for the DFS queue, and O(N) for the visited hashmap. Thus, the total space complexity is O(N).
*/