#include<bits/stdc++.h>
using namespace std;

void checkPrime(int n){ // Brute force approach
    int cnt = 0;
    for(int i=1;i<=n;i++)
    {
        if (n % i == 0) cnt++;
    }
    if (cnt == 2) cout<< "Prime number" << endl;
    else cout<< "Not a prime number" << endl;
}

void checkPrime2(int n){ // Optimal approach
    int cnt = 0;
    for(int i = 1; i*i<=n; i++)
    {
        if(n % i == 0){
            if(n/i != i) cnt+=2;
            else cnt++;
        }
    }
    if (cnt == 2) cout<< "Prime number" << endl;
    else cout<< "Not a prime number" << endl;
}

int main(){
    int t;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        int n;
        cin >> n;
        checkPrime2(n);
    }
}