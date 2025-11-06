#include<bits/stdc++.h>
using namespace std;

int Fibonacci(int n){
    
    if(n <= 1)
    return n;

    return Fibonacci(n-1) + Fibonacci(n-2);
    // Whichever recursion call is made first, it will be executed first and then the next recursive call is executed
    // i.e. Fibonacci(n-1) is executed first, then Fibonacci(n-2)
    // i.e. The recursive calls are not executed simultaneously - one is ended and then the next comes

    /*
    T.C. nearly equal to O(2^n) i.e. Exponential Time complexity
    Why not exactly equal to?
    Because we are not calling f(3) & f(3) from f(4) but f(3) & f(2 i.e. 3-1), so the right side recursion call has a little less steps than the left side

    At every step, 2 sub-branches are created and hence 2*2*2.... = 2^n

    Exponential time complexity is managed by or lessened by Dynamic Programming which we will study later
    */
}

int main(){

    int n;
    cin >> n;

    cout << Fibonacci(n);

    return 0;
}