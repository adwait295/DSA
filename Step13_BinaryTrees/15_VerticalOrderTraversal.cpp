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

// The first thing we have to do is - give each node a coordinate pair (x, y) or (row, column) or (level, vertical) so that we can decide in which column a node lies and then segregate them according to the columns coordinate.
// We can give the coordinates to the nodes by any traversal (in, pre, post, level).
// I did it using pre-order traversal (using recursion) and Striver did it using level order traversal (using queue). 



/*
IMPORTANT: READ BEFORE READING THE SOLUTION.

   =========================================================
   std::map TIME COMPLEXITY CHEAT SHEET (C++)
   ---------------------------------------------------------
   std::map is implemented using a Red-Black Tree
   → height ≈ log₂(n)
   → operations requiring search take O(log n)

   ===============================
   O(log n) OPERATIONS
   ===============================

   // Insert / Update
   mp[key] = value;          // inserts if key missing
   mp.insert({key, value});
   mp.emplace(key, value);

   // Access / Lookup
   mp[key];                  // lookup (or insert if missing)
   mp.at(key);               // access existing key

   // Search
   mp.find(key);

   // Count key existence
   mp.count(key);

   // Erase
   mp.erase(key);

   // Range queries (ordered)
   mp.lower_bound(key);
   mp.upper_bound(key);

   =========================================================
   O(1) OPERATIONS (per step)
   =========================================================

   // Iterator access
   it->first;
   it->second;

   // Size / empty
   mp.size();
   mp.empty();

   =========================================================
   ITERATION COST
   =========================================================

   for(auto it : mp)   // traversal
       ...

   → O(n) total
   → NOT O(log n) per step

   =========================================================
   IMPORTANT NOTES
   =========================================================

   mp[key]
   → O(log n) lookup
   → if key missing → inserts → still O(log n)

   map is ORDERED by keys.

   =========================================================
   map vs unordered_map
   =========================================================

   map:
       insert/find → O(log n)
       ordered keys ✔

   unordered_map:
       insert/find → O(1) average
       no ordering ✘

   =========================================================
   WHEN TO USE map
   =========================================================

   ✔ need sorted keys
   ✔ need ordered traversal
   ✔ need lower_bound / range queries

   Otherwise → prefer unordered_map for speed.
   =========================================================

*/


// My solution:

class Solution{
    public:

    map<int, vector<pair<int,int>>> mpp;

    static bool comp(pair<int, int> &a, pair<int, int> &b){
        if(a.first < b.first) return true;
        if(a.first == b.first){
            if(a.second < b.second) return true;
        }
        return false;
    }

    void traversal(TreeNode* root, int row, int column){
        if(root == nullptr) return;

        mpp[column].push_back({row, root->data});

        traversal(root->left, row+1, column-1);
        traversal(root->right, row+1, column+1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {	
        vector<vector<int>> ans;
        traversal(root, 0, 0);

        for(auto it: mpp){ // Maps store in sorted order of keys by default obviously. 
            vector<pair<int, int>> temp = it.second;
            sort(temp.begin(), temp.end(), comp);
            vector<int> temp1;
            for(int i=0;i<temp.size();i++){
                auto x = temp[i];
                temp1.push_back(x.second);
            }
            ans.push_back(temp1);
        }

        return ans;
    }
};

// Striver's solution: Using a multiset.

vector<vector<int>> verticalTraversal(TreeNode* root){
    map<int, map<int, multiset<int>>> nodes; // 2-D Map
    // {vertical, {level, {values}}}
    /*
    Visual example:

              3
             / \
            9   20
               /  \
              15   7

    Coordinates:
    3  → (0,0)
    9  → (-1,1)
    20 → (1,1)
    15 → (0,2)
    7  → (2,2)

    Stored as:
    -1 → { 1 → {9} }
     0 → { 0 → {3}, 2 → {15} }
     1 → { 1 → {20} }
     2 → { 2 → {7} }

    */
    queue<pair<TreeNode*, pair<int, int>>> q; // {node, {level, vertical}}
    vector<vector<int>> ans;
    q.push({root, {0, 0}});
    while(!q.empty()){      
        auto p = q.front();
        q.pop();
        TreeNode* node = p.first;
        int x = p.second.first, y = p.second.second;
        // 2-D map element access:
        nodes[y][x].insert(node->data); // Sets store in sorted order. We took a multiset because in normal sets, duplicate elements can't be stored. There may be a case where the two elements with the same row & same column number might have the same value - In that case a multiset is necessary to store duplicate values in sorted order. As it's ultimately a set too, we cannot push so we insert. 
        if(node->left) q.push({node->left, {x+1, y-1}});
        if(node->right) q.push({node->right, {x+1, y+1}});
    }
    // 2-D Map traversal:
    for(auto p: nodes){
        vector<int> col;
        for(auto q: p.second) col.insert(col.end(), q.second.begin(), q.second.end()); // We can do push_back too because 'col' is a vector. 

        /*
        v.insert(pos, val);   // Insert single element 
        v.insert(pos, n, val);   // Insert multiple copies of an element
        v.insert(pos, {val1, val2, ...})   // Insert list of elements
        v.insert(pos, first, last);   // Insert range of elements
        */

       ans.push_back(col);
    }

    return ans;
}

/*
Time Complexity:O(N * logN) : This complexity arises from performing levelorder traversal using BFS, where each node's insertion and retrieval operations in nested maps take logarithmic time. Overall, it reflects the combined cost of processing each node and managing the node mappings.

Space Complexity: O(N + N/2) : The space usage is dominated by the map storing nodes by their vertical and level information, occupying O(N) space. Additionally, the queue for BFS can occupy up to O(N/2) space in a balanced tree's worst-case scenario, contributing to the total space complexity.
*/

// Editorial's solution: Using a priority queue instead of multiset; rest all same.

vector<vector<int>> verticalTraversal(TreeNode* root) {
    // List to store the final result
    vector<vector<int>> result;

    if (root == nullptr) {
        return result;
    }

    // Map to store the nodes at each vertical distance and level
    map<int, map<int, priority_queue<int, vector<int>, greater<int>>>> nodesMap;

    // Queue for BFS traversal (stores node along with its x and y coordinates)
    queue<pair<TreeNode*, pair<int, int>>> q;
    q.push({root, {0, 0}});  // (node, {x, y})

    // Perform BFS
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        TreeNode* node = p.first;
        int x = p.second.first;
        int y = p.second.second;

        // Add the node's value to the map at the correct x and y
        nodesMap[x][y].push(node->data);

        // Add the left child with updated coordinates to the queue
        if (node->left != nullptr) {
            q.push({node->left, {x - 1, y + 1}});
        }

        // Add the right child with updated coordinates to the queue
        if (node->right != nullptr) {
            q.push({node->right, {x + 1, y + 1}});
        }
    }

    // Prepare the result by sorting keys and compiling nodes
    for (auto& p : nodesMap) { // & is used so that any changes in 'p' also reflects in the elements of the 'nodesMap' too obviously. 
        vector<int> column;
        for (auto& q : p.second) {
            while (!q.second.empty()) { // Because of priority queue. We cannot insert into 'column' directly from .begin() to .end() as we did in case of a multiset. 
                column.push_back(q.second.top());
                q.second.pop();
            }
        }
        result.push_back(column);
    }

    return result;
}    