#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(int x) {
       if(x>0){
        int revN = 0;
        int m = x;
        while(x != 0)
        {
            int digit = x % 10;
            x = x / 10;

            // Checking overflow
            if(revN>INT_MAX/10 || (revN==INT_MAX/10 && digit>7)) return false;

            revN=revN*10 + digit;
        }
        if (revN == m) return true;
        else return false;
       } 
       else if (x<0) return false;
       // In leetcode, in a given test case, the reverse of -121 was given as 121-, which was not palindrome
       // So to satisfy the test-case, any number which is negative, will not obviously be palindrome because of - sign in the end
       // So I wrote this condition and it worked
       else return true;
    }

int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n;
        cin>>n;
        cout<< isPalindrome(n)<< endl;
    }
    return 0;
}