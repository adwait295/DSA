#include<bits/stdc++.h>
using namespace std;

// there is an in-built function to find out maximum of two numbers

int maxx(int a, int b){
    if(a>=b) return a; // as there is one line, we can write it without braces
    else return b; // if we do not write this line then y will contain any random garbage value in case a<b
    // because as the maxx() could not find a return statement
    // it returned a garbage value to y

    // SO ALWAYS MAKE SURE YOU WRITE A RETURN STATEMENT in a return type function 
}
int main(){
    int a,b;
    cin >> a >> b;

    int x = max(a,b);
    cout<<x<<endl;

    // but if we want to make a max function of our own
    // we can but our function names should not match
    // the in-built functions of c++

    int y = maxx(a,b);
    cout<<y<<endl;
}