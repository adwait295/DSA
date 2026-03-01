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

// completely same as the top view Striver's solution except one step:

// In top view, we do if(mpp.find(colNum) == mpp.end()) mpp[colNum] = node->data; because we want only the first element of a particular column to go into the map.

// In bottom view, we do mpp[colNum] = node->data; because we want each time an element of the same column, it replaces the previous element - because if an element comes later, it is at a deeper row or level during BFS and we want the deepest.

// Misconception:
// We cannot do bottom view by DFS method unlike the vertical order traversal and top view question. Only BFS method can be used. 

// I proved it wrong. My solution:

class Solution{
    public:

    map<int, vector<pair<int, int>>> mpp;

    static bool comp(const pair<int, int> &a, const pair<int, int> &b){
        return a.first < b.first;
    }

    void traversal(TreeNode* root, int row, int column){
        if(root == nullptr) return;
        mpp[column].push_back({row, root->data});
        traversal(root->left, row+1, column-1);
        traversal(root->right, row+1, column+1);
    }

    vector<int> bottomView(TreeNode *root){
        vector<int> ans;
        traversal(root, 0, 0);

        for(auto it: mpp){
            auto vectorr = it.second;
            stable_sort(vectorr.begin(), vectorr.end(), comp);
            ans.push_back(vectorr[vectorr.size()-1].second);
        }

        return ans;
    }
};

// Striver's solution:


class Solution{
    public:

    vector<int> bottomView(TreeNode* root){
        vector<int> ans;
        if(root == nullptr) return ans;
        map<int, int> mpp;
        queue<pair<TreeNode*, int>> q; 
        q.push({root, 0});
        while(!q.empty()){
            auto p = q.front(); q.pop();
            TreeNode* node = p.first;
            int colNum = p.second;
            mpp[colNum] = node->data; // except this step, rest everything same as top view question.

            if(node->left) q.push({node->left, colNum-1});
            if(node->right) q.push({node->right, colNum+1});
        }

        for(auto it: mpp) ans.push_back(it.second);

        return ans;
    }
};

// What i learned to make my DFS solution right:

/* =========================================================
   sort() vs stable_sort() — COMPLETE BEHAVIOR GUIDE
   =========================================================

   Both functions sort elements in a range.

   #include <algorithm>

   ---------------------------------------------------------
   DEFAULT BEHAVIOR (NO COMPARATOR)
   ---------------------------------------------------------

   sort(v.begin(), v.end());
   stable_sort(v.begin(), v.end());

   → Elements are sorted using operator '<'

   For pair<int,int>, sorting is "LEXICOGRAPHIC":

       1️⃣ compare first
       2️⃣ if equal → compare second

   Example:
       {4,7}, {4,2}, {3,5}

   After sort:
       {3,5}, {4,2}, {4,7}

   ---------------------------------------------------------
   USING A COMPARATOR
   ---------------------------------------------------------

   sort(v.begin(), v.end(), comp);
   stable_sort(v.begin(), v.end(), comp);

   → ONLY the comparator defines ordering
   → default pair comparison is ignored

   Comparator must:
       ✔ return bool
       ✔ use const references ('const')
       ✔ define STRICT ordering (use < not <=) - Important

   Example:

       bool comp(const pair<int,int>& a, const pair<int,int>& b){
           return a.first < b.first;
       }

   Now sorting compares ONLY .first.

   ---------------------------------------------------------
   WHAT HAPPENS WHEN KEYS ARE EQUAL?
   ---------------------------------------------------------

   If comparator considers two elements 'a' and 'b' equal, then:

       comp(a,b) = false
       comp(b,a) = false

   they are treated as "equivalent".

   ---------------------------------------------------------
   sort() BEHAVIOR
   ---------------------------------------------------------

   sort() is NOT stable because "Equal elements may change order."

   Example:

       original:
           {4,7}, {4,2}, {4,5}

       after sort by first:
           order may be ANY permutation:
           e.g. {4,7}, {4,5}, {4,2} OR {4,7}, {4,2}, {4,5} OR {4,2}, {4,7}, {4,5}

   Time Complexity:
       O(n log n)
   Memory:
       O(log n)

   ---------------------------------------------------------
   stable_sort() BEHAVIOR
   ---------------------------------------------------------

   stable_sort() PRESERVES original order
   of equivalent elements.

   Example:

       original:
           {4,7}, {4,2}, {4,5}

       after stable_sort by first:
           {4,7}, {4,2}, {4,5}   ← same order

   Time Complexity:
       O(n log n)
   Memory:
       O(n) extra space

   ---------------------------------------------------------
   WHEN TO USE EACH
   ---------------------------------------------------------

   Use sort() when:
       ✔ stability not required
       ✔ faster & less memory
       ✔ most competitive programming

   Use stable_sort() when:
       ✔ tie order must remain unchanged
       ✔ sorting by one key but preserving original order
       ✔ multi-key sorting (secondary keys already ordered)

   ---------------------------------------------------------
   IMPORTANT COMPARATOR RULES
   ---------------------------------------------------------

   ✔ must use const references:
       bool comp(const T& a, const T& b)

   ✔ must return STRICT comparison:
       return a < b;

   ❌ never use <=
   ❌ never modify elements

   ---------------------------------------------------------
   MULTI-KEY SORTING (example)
   ---------------------------------------------------------

   sort by first, then second:

    return a.first < b.first || (a.first == b.first && a.second < b.second);

   ---------------------------------------------------------
   QUICK SUMMARY
   ---------------------------------------------------------

   sort():
       ✔ O(n log n)
       ✔ NOT stable
       ✔ low memory

   stable_sort():
       ✔ O(n log n)
       ✔ stable
       ✔ uses extra memory

   =========================================================
*/
