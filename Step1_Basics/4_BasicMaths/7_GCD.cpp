#include<bits/stdc++.h>
using namespace std;

void findGCD(int a, int b){ // Brute force approach
    int gcd = 1;
    for(int i=1;i<=min(a,b);i++)
    {
        if(a % i == 0 && b % i == 0) gcd=i;
    }
    cout<<gcd<<endl;
    // T.C. = O(min(a,b))
}

void findGCD1(int a, int b){ // Better approach
    for(int i = min(a,b); i>=1; i--)
    {
        if(a % i == 0 && b % i == 0)
        {
            cout << i << endl;
            break;
        }
    }

    // T.C. = O(min(a,b))
}

void findGCD(int a, int b){ // Optimal Approach
    // Euclidean Algorithm
    // GCD (a,b) = GCD(a%b,b) where a>b, until one of them becomes 0
    // when one of them is 0 then the other becomes the GCD

    while(a>0 && b>0)
    {
        if(a>b) a = a%b;
        else b = b%a;
    }
    
    if(a==0) cout<<b<<endl;
    else cout<<a<<endl;

    // T.C. = O(logx(min(a,b)))
    // log because we know that whenever / or % is done, log comes into action
    // x or phi is base of log because the divisor it not constant at every step, it fluctuates
    // min(a,b) because this is where we start doing %
}

int main(){
    int a,b;
    cin >> a >> b;
    findGCD(a,b);
    return 0;
}