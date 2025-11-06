#include<bits/stdc++.h>
using namespace std;

/*
In DSA, if an element appears multiple times in both input arrays, the resulting intersection 
might include that element with a multiplicity equal to minimum number of times it appeared
in both the arrays. This is often referred to as finding the intersection "with duplicates" 
or "with multiplicity".
*/

/* 
Brute force solution:
We will use a vis[] to store 0 or 1 so that we can know that the element in the other array
has been visited before or not. If visited, value will become one, otherwise remain 0. 
*/

vector<int> findArrayIntersection(vector<int> &A, int n, vector<int> &B, int m)
{
    vector<int> ans;
    int vis[m] = {0}; // can be vice-versa
    // We can use the vis[] for the smaller array so that the S.C. will be less.
    // If we don't do that, it won't make much of a difference.
    for (int i = 0; i < n; i++) // element in the first array
    {
        for (int j = 0; j < m; j++) // element in the second array
        {
            if (A[i] == B[j] && vis[j] == 0){// if both are same and the corresponding element in second array has not been visited before.
                ans.push_back(A[i]);
                vis[j] = 1;
                break; // Wherever same element found, we add to ans[] and break.
                // If the element with same value is found after that, even if its same,
                // it will not correspond to the same value element in the first array
                // as it has already been used. It shall correspond to the same value
                // element in the first array (if any) later.
            }

            if (B[j] > A[i]) break;
        }
    }
    return ans;
}

/*
T.C. = O(n*m)
S.C. = O(m) or O(n) depending upon for which array we are keeping the vis[].
and extra space will be occupied by 'ans' vector, which we use just to store and return
the intersection, not to solve the problem, which will be O(n1+n2) in the worst case.
*/

// Optimal solution : Two-pointer approach

vector<int> findArrayIntersection1(vector<int> &A, int n, vector<int> &B, int m) {
    int i = 0;
    int j = 0;
    vector<int> ans;
    while (i < n && j < m) {
        if (A[i] < B[j]) {
            i++;
        }
        else if (B[j] < A[i]) {
            j++;
        }
        else {
            ans.push_back(A[i]);
            i++;
            j++;
        }
    }
    return ans;
}

/*
T.C. = O(n1+n2) As we can see that in the worst case,
we might have to visit every element of each input array once.

S.C. = O(n1+n2) which we use to store the answer, not to solve the problem.
so we use O(1) extra space to solve the problem.
*/

int main(){
    int size1, size2;
    cin >> size1 >> size2;
    vector<int> a;
    vector<int> b;
    for(int i=1;i<=size1;i++)
    {
        int n;
        cin >> n;
        a.push_back(n);
    }

    for(int i=1;i<=size2;i++)
    {
        int n;
        cin >> n;
        b.push_back(n);
    }

    vector<int> c = findArrayIntersection1(a,size1,b,size2);

    for(int i=0;i<c.size();i++)
    {
        cout << c[i] << " ";
    }

    return 0;
}




