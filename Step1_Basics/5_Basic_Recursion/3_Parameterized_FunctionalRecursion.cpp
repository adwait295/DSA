#include<bits/stdc++.h>
using namespace std;

void printSum(int i, int sum){ 
    // Parameterized Recursion:
    // The parameter does the work inside the function and gets printed at the end
    // i.e. sum parameter is doing the work and "getting printed"

    if(i<1){
        cout << sum << endl;
        return;
    }
    printSum(i-1,sum+i); // 0+n+(n-1)+(n-2)+(n-3) and so on
}

int printSum1(int n){
    // Functional Recursion:
    // The function does the work and returns a value at the end
    // The problem is broken down into smaller parts
    if(n==0)
    return 0;
    return n + printSum1(n-1); // n+(n-1)+(n-2) and so on
}

void printFactorial(int i, int factorial){ // Parameterized
    
    if(i<1){
        cout << factorial << endl;
        return;
    }
    printFactorial(i-1,factorial*i);
}

int printFactorial1(int n){ // Functional
    if (n == 0) return 1;
    return n*printFactorial1(n-1);
}

// T.C. = O(n) // Function call is taking place n times
// S.C. = O(n) // Auxillary space or stack space where n functions are awaiting to be completed

int main(){

    int n;
    cin >> n;
    // printSum(n,0);
    // cout << printSum1(n);
    // printFactorial(n,1);
    // cout << printFactorial1(n);
    return 0;
}