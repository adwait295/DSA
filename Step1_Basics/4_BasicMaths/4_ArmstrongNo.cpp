#include<bits/stdc++.h>
using namespace std;

bool isArmstrong(int x){ // Leetcode Premium

    // Negative numbers are not considered Armstrong numbers
    if(x<0) return false;
    
    int m = x;
    int sum = 0;

    int cnt = 0;

    if (x>0){
        cnt = (int)(log10(x)+1); // domain of logarithmic function is >0
    }

    while(x!=0)
    {
        int digit = x%10;
        x/=10;
        sum+= pow(digit,cnt);
    }
    if (sum == m) return true;
    else return false;
}

int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n;
        cin>>n;
        cout<< isArmstrong(n)<< endl;
    }
    return 0;
}