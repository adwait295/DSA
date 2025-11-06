#include<bits/stdc++.h>
using namespace std;

void printDivisors(int n){ // Brute force solution
    for(int i=1;i<=n;i++)
    {
        if (n%i == 0) cout << i << " ";
    }
    // T.C. = O(n)
}

void printDivisors2(int n){ // Optimal solution
    vector<int> v;
    for(int i=1;i*i<=n;i++) // O(sqrt(n))
    {
        if(n % i == 0){
            v.push_back(i); 
            if(n/i != i) v.push_back(n/i);
        }
    }
    sort(v.begin(),v.end());
    // O(n1 log n1) where n1 = number of elements in v or number of factors of n

    for(auto i:v) // O(n1)
    {
        cout << i << " ";
    }

    // So total T.C. = O(sqrt(n)) + O(n1 log(n1)) + O(n1)
    // T.C. = O(sqrt(n) + n1 log (n1) + n1)
}

int main(){
    int t;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        int n;
        cin>>n;
        printDivisors(n);
        cout<<endl;
    }
    return 0;
}