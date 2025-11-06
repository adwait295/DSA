#include<bits/stdc++.h>
using namespace std;

int reverse(int x){
    int revN = 0;
    while (x != 0) {
        int digit = x % 10;
        x /= 10;

        // Check for overflow
        if (revN > INT_MAX/10 || (revN == INT_MAX/10 && digit > 7)) return 0;
        if (revN < INT_MIN/10 || (revN == INT_MIN/10 && digit < -8)) return 0;

        // a 32-bit signed integer should lie between INT_MIN = -2147483648 and INT_MAX = 2147483647
        // So we check if the revN is surpassing these limits

        revN = revN * 10 + digit;
    }
    return revN;
}

int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n;
        cin>>n; // good test case n = 1534236469
        cout<< reverse(n) << endl;
    }
    return 0;
}

