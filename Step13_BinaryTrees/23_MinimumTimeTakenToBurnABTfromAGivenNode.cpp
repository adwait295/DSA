#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val): data(val), left(nullptr), right(nullptr) {}
};

// My solution:

class Solution{

		void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track){
			if(root == nullptr) return;
			queue<TreeNode*> q;
			parent_track[root] = nullptr;
			q.push(root);
			while(!q.empty()){
				TreeNode* currNode = q.front(); q.pop();
				if(currNode->left){
					parent_track[currNode->left] = currNode;
					q.push(currNode->left);
				}
				if(currNode->right){
					parent_track[currNode->right] = currNode;
					q.push(currNode->right);
				}
			}
		}

	public:
		int timeToBurnTree(TreeNode* root, int start){
            unordered_map<TreeNode*, TreeNode*> parent_track;
			markParents(root, parent_track);

			TreeNode* target;
			queue<TreeNode*> q1;
			q1.push(root);
			while(!q1.empty()){
				TreeNode* temp = q1.front(); q1.pop();
				if(temp->data == start){
					target = temp;
					break;
				}
				if(temp->left) q1.push(temp->left);
				if(temp->right) q1.push(temp->right);
			}

			unordered_map<TreeNode*, bool> visited;
			visited[target] = true;
			queue<TreeNode*> q2;
			q2.push(target);
			int maxDist = -1;
			while(!q2.empty()){
				int size = q2.size();
				maxDist++;
				for(int i=1;i<=size;i++){
					TreeNode* currNode = q2.front(); q2.pop();
					if(currNode->left && !visited[currNode->left]){
						q2.push(currNode->left);
						visited[currNode->left] = true;
					}
					if(currNode->right && !visited[currNode->right]){
						q2.push(currNode->right);
						visited[currNode->right] = true;
					}
					if(parent_track[currNode] && !visited[parent_track[currNode]]){
						q2.push(parent_track[currNode]);
						visited[parent_track[currNode]] = true;
					}
				}
			}

			return maxDist;
		}	
};

// Striver's solution: Just a different way (better way) of writing the same logic

class Solution {
public:
    int timeToBurnTree(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> mpp;
        TreeNode* target = bfsToMapParents(root, mpp, start);
        int maxi = findMaxDistance(mpp, target);
        return maxi;
    }

private:
    TreeNode* bfsToMapParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mpp, int start) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* res = new TreeNode(-1);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->data == start) res = node;

            if (node->left != nullptr) {
                mpp[node->left] = node;
                q.push(node->left);
            }

            if (node->right != nullptr) {
                mpp[node->right] = node;
                q.push(node->right);
            }
        }
        return res;
    }

    int findMaxDistance(unordered_map<TreeNode*, TreeNode*>& mpp, TreeNode* target) {
        queue<TreeNode*> q;
        q.push(target);
        unordered_map<TreeNode*, int> vis;
        vis[target] = 1;
        int maxi = 0;

        while (!q.empty()) {
            int size = q.size();
            int fl = 0;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left != nullptr && vis.find(node->left) == vis.end()) {
                    fl = 1;
                    vis[node->left] = 1;
                    q.push(node->left);
                }

                if (node->right != nullptr && vis.find(node->right) == vis.end()) {
                    fl = 1;
                    vis[node->right] = 1;
                    q.push(node->right);
                }

                if (mpp.find(node) != mpp.end() && vis.find(mpp[node]) == vis.end()) {
                    fl = 1;
                    vis[mpp[node]] = 1;
                    q.push(mpp[node]);
                }
            }
            if (fl == 1) maxi++;
        }
        return maxi;
    }
};

// For both solutions:

/*
Time Complexity : O(N) where n is the number of nodes in the tree, due to BFS traversals

SpaceComplexity : O(N) for storing the parent mapping and the visited set.
*/