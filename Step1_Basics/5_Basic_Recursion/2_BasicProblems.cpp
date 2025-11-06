#include<bits/stdc++.h>
using namespace std;

// Print statement before the recursive call:
// First function's print statement is executed first

void printName(int i, int n, string x){ // Print Name n times
    if(i>n) return; // base case is written on the problem statement
    cout << x << endl;
    printName(i+1,n,x);

    // T.C. = O(n)
    // S.C. = O(n) 
    // The space complexity is hypothetical because there is no array or variable
    // We use the internal memory of the computer for 'stack space' and so space complexity becomes O(n)

}

void printNumbers(int i, int n){ // Print from 1 to n
    if(i>n) return; 
    cout << i << endl;
    printNumbers(i+1,n);
}

void printNumbers1(int n){ // Print from n to 1
    if(1>n) return; 
    cout << n << endl;
    printNumbers1(n-1);

    /*
    Or we can take printNumbers1(int i, int n)
    Then we do printNumbers1(i-1,n) until i<1 (Base condition)
    From main() we call printNumbers1(n,n)
    */
}

// Print statement after the recursive call: Backtracking:
// Last function's print statement is executed first

void printNumbers2(int i, int n){
    
    if(i<1) return; // return statement terminates the function then and there
    printNumbers2(i-1,n);
    cout << i <<endl;
    // Even if i goes from n to 1 , i.e. i-1 is being done at every step, we print i from 1 to n
    // just because cout is waiting for the function call above it to be executed
}

void printNumbers3(int i, int n){
    
    if(i>n) return;
    printNumbers3(i+1,n);
    cout << i << endl;
}


int main(){
    int n;
    cin >> n;
    // string name;
    // cin >> name;
    // printName(1,n,name);
    // printNumbers(1,n);
    // printNumbers1(n);
    // printNumbers2(n,n);
    // printNumbers3(1,n);
    return 0;
}