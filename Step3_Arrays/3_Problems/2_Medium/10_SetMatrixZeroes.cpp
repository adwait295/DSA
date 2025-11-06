#include<bits/stdc++.h>
using namespace std;

// Brute force solution: (for binary matrix/2-D arrays, i.e. array only contains 0 & 1)

void markRow(vector<vector<int>> &a, int i){
    for(int j=0;j<a[0].size();j++)
    {
        if(a[i][j] != 0) a[i][j] = -1;
    }
}

void markCol(vector<vector<int>> &a, int j){
    for(int i=0;i<a.size();i++)
    {
        if(a[i][j] != 0) a[i][j] = -1;
    }
}

void setZeroes0(vector<vector<int>> &a){
    int n = a.size(); // number of rows
    int m = a[0].size(); // number of columns
    for(int i=0;i<n;i++) // O(n)
    {
        for(int j=0;j<m;j++) // O(m)
        {
            if(a[i][j] == 0){
                markRow(a,i); // O(n)
                markCol(a,j); // O(m)
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j] == -1) a[i][j] = 0;
        }
    }

}

// T.C. = O(n*m*(n+m) + n*m) which is coming in the order of n^3 (if n=m). 
// It is very high, so the interviewer will obviously ask us to optimize it.
// S.C. = O(1).

// Better solution: We will mark the rows/columns which need to be 0.

void setZeroes1(vector<vector<int>> &a){
    int rows[a.size()] = {0}, columns[a[0].size()] = {0};
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<a[0].size();j++)
        {
            if(a[i][j] == 0){
                rows[i] = 1;
                columns[j] = 1;
            }
        }
    }

    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<a[0].size();j++)
        {
            if(rows[i] || columns[j]){
                a[i][j] = 0;
            }
        }
    }
}

// T.C. = O(n*m + n*m) i.e. in the order of n^2.
// S.C. = O(n+m).

// We know in order to traverse a 2-D array, we need the n^2 time complexity. We cannot have less than that.
// So if the interviewer asks us to further optimize the solution, we know we have to optimize the S.C.

// Optimal solution:

void zeroMatrix(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    // Refer notes for better visualization.
    // Better write what we are taking (->) so that we don't get confused:
    // int cols[m] = {0};  -> matrix[0][anything except 0].
    // int rows[n] = {0};  -> matrix[anything][0] .
    int col0 = 1; // to mark the 0th column; taken separately to avoid collision of the rows[] & columns[].
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matrix[i][j] == 0) {
                // mark the i-th row:
                matrix[i][0] = 0;
                // mark the j-th col:
                if(j != 0) // We don't fuck with matrix[0][0] to avoid collision.
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(matrix[i][j] != 0){
                // Check for row & column.
                if(matrix[0][j] == 0 || matrix[i][0] == 0) matrix[i][j] = 0;
            }
        }
    }

    if(matrix[0][0] == 0){
    for(int j = 0; j < m; j++) matrix[0][j] = 0;
    }

    if(col0 == 0) {
        for(int i = 0; i < n; i++) matrix[i][0] = 0;
    }

}

// T.C. = O(2*n*m)
// S.C. = we take only one extra variable i.e. col0. and that's it.


int main(){
    int rows, columns;
    cin >> rows >> columns;
    vector<vector<int>> a(rows,vector<int>(columns,0));
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            cin >> a[i][j];
        }
    }

    zeroMatrix(a);

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}