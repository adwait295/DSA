#include<bits/stdc++.h>
using namespace std;

void pattern1(int n){

    for(int i=0;i<n;i++) // the only code we need to write in online compilers
    {
        for(int j=0;j<n;j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
}

int main(){ //Backend code at online compilers
    
    int t; // Number of test cases
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        pattern1(n);
    }
    return 0;
}

// Test cases - Our program internally runs for multiple cases
/* In real life or the coding world, there will
be thousands of test cases
Any program that we write will be run on thousands of 
test cases. */

// SO ALWAYS PRACTICE ON ONLINE CODING PLATFORMS
// BECAUSE WE WILL GIVE INTERVIEWS/CODING ROUNDS ON THOSE TYPE OF PLATFORMS