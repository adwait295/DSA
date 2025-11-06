#include<bits/stdc++.h>
using namespace std;

// Brute force solution:

vector<int> union1(vector<int> a, vector<int> b){
    int n1 = a.size();
    int n2 = b.size();
    set<int> st;
    for(int i=0;i<n1;i++) st.insert(a[i]); // O(n1 log n) 
    // where n is the size of st which varies at every step.
    // So we cannot step that the T.C. is exactly n1 log n because the
    // the size of st is not n at every step but we assume the worst case.
    for(int i=0;i<n2;i++) st.insert(a[i]); // O(n2 log n)
    vector<int> temp;
    for(auto it: st) temp.push_back(it); // O(n1 + n2)
    // n1+n2 because in the worst case, both a and b have all unique elements.

    return temp; 
}

/*
T.C. = O(n1 log n + n2 log n + (n1+n2))
S.C. = O(n1 + n2) because we use a set data structure to solve the problem 
We use an extra n1+n2 space to store the elements of set into a temp vector 
which also takes O(n1+n2) space but we dont use the temp to solve the problem.
so S.C. = O(n1+n2) + O(n1+n2) finally.
*/

// Optimal solution: Two-pointer method

vector<int> union2(vector<int> &a, vector<int> &b){
    int n1 = a.size();
    int n2 = b.size();
    vector<int> unionArr;
    
    int i=0, j=0;
    while(i<n1 && j<n2)
    {
        if(a[i] <= b[j]){
            if(unionArr.size() == 0 || unionArr.back() != a[i]){
                unionArr.push_back(a[i]);
            }
            i++;
        }
        else{
            if(unionArr.size() == 0 || unionArr.back() != b[j]){
                unionArr.push_back(b[j]);
            }
            j++;
        }
    }
    while(i<n1){
       if(unionArr.size() == 0 || unionArr.back() != a[i]){
            unionArr.push_back(a[i]);
        }
        i++; 
    }
    while(j<n2){
      if(unionArr.size() == 0 || unionArr.back() != b[j]){
            unionArr.push_back(b[j]);
        }
        j++;  
    }

    return unionArr;
}

/* 
As in the process, we are visiting each element of both arrays a & b once,
so the T.C. = O(n1+n2).
S.C. = O(n1+n2) if all the elements are unique and that is for returning
the answer, not for solving the problem. We must tell this to the
interviewer.
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

    vector<int> c = union2(a,b);

    for(int i=0;i<c.size();i++)
    {
        cout << c[i] << " ";
    }

    return 0;
}