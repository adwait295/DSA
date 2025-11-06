#include<bits/stdc++.h>
using namespace std;

// Brute solution:

vector<vector<int>> rotateMatrix(vector<vector<int>> &a, int n){
    vector<vector<int>> x (n,vector<int>(n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            x[j][n-1-i] = a[i][j];
        }
    }
    return x;
}

// T.C. = O(n^2).
// S.C. = O(n^2).

// The interviewer will obviously be not happy with the O(n^2) space complexity and will ask us to do the 
// rotation 'in place'.

// Optimal solution: Observation is the key.

/*
Steps:
1. Transpose.
2. Reverse every row.
*/

vector<vector<int>> rotateMatrix1(vector<vector<int>> &a, int n){
    // Transpose: Perform a dry run and see why i goes till n-2 and j starts from i+1
    for(int i=0;i<n-1;i++) // O(n), not exactly but close to.
    {
        for(int j=i+1;j<n;j++) // O(n), not exactly but close to.
        {
            if(i != j){// The diagonal elements remain in their original places.
                swap(a[i][j],a[j][i]); // Mirror elements, where the principle diagonal is the mirror.
            }
        }
    }
    // Reverse every row:
    for(int i=0;i<n;i++){// O(n)
        reverse(a[i].begin(),a[i].end()); // a[i] is the row. // O(n) 
        // The reverse() can have a T.C. of O(n/2) if we write our own reverse() using two pointer approach
    }   
    return a;
}

// T.C. = O(n^2 + n^2).
// S.C. = O(1).

int main(){
    int size;
    cin >> size;
    vector<vector<int>> a(size,vector<int>(size,0));
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> x = rotateMatrix(a,size);

    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            cout << x[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}