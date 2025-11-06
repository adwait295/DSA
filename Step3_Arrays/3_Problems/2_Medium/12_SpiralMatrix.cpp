#include<bits/stdc++.h>
using namespace std;


// This is an implementation based question.

/*
There is only one solution to this problem which is the optimal solution.

Then why is the interviewer asking this question?
There are two reasons:
1. He wants to check our implementation skills.
2. He wants to know how clean can we write our code. 

So our focus will be to find the easiest implementation.
*/

vector<int> spiralMatrix(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    int left = 0, right = m - 1;
    int top = 0, bottom = n - 1;
    vector<int> ans;

    // Take e.g. [1,2,3,4,5,6]
    // Take e.g. [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]
    // Perform dry run for both examples and you will understand everything.

    while (top <= bottom && left <= right){
        // For the below two conditions, the while condition as well as their own for condition
        // is checking if top<=bottom & left<=right or not as required by specific loop:

        // right
        for (int i = left; i <= right; i++) {
            ans.push_back(mat[top][i]);
        }
        top++;

        // down
        for (int i = top; i <= bottom; i++) {
            ans.push_back(mat[i][right]);
        }
        right--;

        // But after doing top++ & right--, we again need to check if they cross boundary conditions or not;
        // so before continuing, we check them as required for each loop and then go ahead if satified.
        // The conditions are as follows:

        // left
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                ans.push_back(mat[bottom][i]);
            }
            bottom--;
        }

        // up
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                ans.push_back(mat[i][left]);
            }
            left++;
        }
    }
    return ans;
}

// T.C. = O(n*m) because we visit each element exactly once & there are n*m elements.
// S.C. = O(n*m) for storing all the elements in the ans vector.

// In order to write clean code, you should always write pseudo code first. 

/*
1. Visualization.
2. Intuition.
3. Pseudo Code.
4. Dry run.
5. Code.
6. Edge cases.
*/