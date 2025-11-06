#include<bits/stdc++.h>
using namespace std;

// Brute force solution:

void rearrange(vector<int> &a){
    int size = a.size();
    vector<int> pos; // Lists/Vectors are always preferred over arrays.
    vector<int> neg;
    for(int i=0;i<size;i++) // O(n)
    {
        if(a[i] < 0) neg.push_back(a[i]);
        if(a[i] > 0) pos.push_back(a[i]);
    }
    for(int i=0;i<(size/2);i++) // O(n/2)
    {
        a[2*i] = pos[i];
        a[2*i + 1] = neg[i];
    }
}

// T.C. = O(3n/2)
// S.C. = O(n/2) + O(n/2) = O(n)

// Optimal solution:

vector<int> rearrange1(vector<int> &a){
    int size = a.size();
    vector<int> ans(size);
    int pos = 0, neg = 1;
    for(int i=0;i<size;i++)
    {
        if(a[i] > 0){
            ans[pos] = a[i];
            pos += 2;
        }
        else{
            ans[neg] = a[i];
            neg += 2;
        }
    }

    return ans;
}

// T.C. = O(n)
// S.C. = O(n)

int main(){
    int size;
    cin >> size;
    vector<int> a;
    for(int i=1;i<=size;i++)
    {
        int n;
        cin >> n;
        a.push_back(n);
    }

    vector<int> answer = rearrange1(a);

    cout << "Rearranged Array: " << endl;

    for(int i=0;i<size;i++) cout << answer[i] << " ";

    cout << '\n';

    return 0;
}