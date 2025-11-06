#include<bits/stdc++.h>
using namespace std;

// Return the nth root of a number m. If the root doesn't exist, return -1.

// Brute force solution: Linear Search

// Normal method to compute power x^y : O(n)

int power1(int x, int y){
    long long power = 1; // multiplication involved, so might exceed. Be careful.
    for(int i=1;i<=y;i++){
        power = power * x;
    }
    return power;
}

// Binary exponentiation method (also known as exponentiation by squaring),
// to compute power x^y : O(log n) base 2.

int power(int x, int y){
    long long power = 1;
    while(y > 0){
        if(y % 2 == 1){ // 'y' i.e. power is odd.
            power = power * x;
            y = y - 1;
        }
        else{
            x = x * x;
            y = y / 2;
        }
    }

    return power;
}

int root(int m, int n){

    for(int i=1;i<=m;i++){
        if(power(i,n) == m) return i;
        else if(power(i,n) > m) break;
    }
    return -1;
}

// T.C. = O(nth root of m) * O(log n):
// O(nth root of m) can be O(m) at worst case as 1th root of m is m itself.
// O(log n) to compute the power each time using power exponentiation method. 
// The interviewer won't be happy about the O(m) part.

// So can we apply BS here? Yes, probably. Why?
// Because whenever the mid^n is less than m, we move towards right and whenever the mid^n is greater
// than m, we move towards left. So we know when to move right and when to move left. We also know the range
// in which the answer might lie i.e. from 1 to m. Whatever be the lowest possible answer is assigned to 'low'
// and highest possible answer is assigned to 'high' at the beginning.

// Optimal solution: Binary search.

int NthRoot(int m, int n){

    int low = 1, high = m;
    while(low <= high){

      int mid = (low + high) / 2;

      int midN = power(mid,n); // mid^n is calculated using the binary exponentiation method which is O(log n)

      if(midN == m) return mid;
      else if(midN < m) low = mid + 1;
      else high = mid - 1;  
    }
    return -1;
}

// T.C. = O(log m) * O(log n) both are base 2 obviously.

// BUT THERE'S A CACHE HERE.

/*
While calculating x^y, we have to take care there is no overflow. 
For e.g. n = 10 & m = 10^9.

low = 1, high = 10^9, mid = (10^9)/2.

whenever we do mid * mid * mid......10times, it becomes around 10^90 which will obviously cause overflow.

so in order to prevent that, we need to stop when the power is exceeding the m because we don't require to 
calculate after that; if the power crosses our m, then it will obviously not be our answer, so we need to 
move on.

so instead of fully calculating mid^n, we need to stop when mid*mid*mid..... becomes >m.
*/

// So now:

// return 1 if ==m
// return 0 if <m
// return 2 if >m

// Normal method:

int func(int mid, int n, int m){
    long long ans = 1;
    for(int i=1;i<=n;i++){
        ans = ans * mid;
        if(ans > m) return 2;
    }
    if(ans == m) return 1;
    return 0;
}

// Binary exponentiation method:

int func1(int mid, int n, int m){
    long long ans = 1;
    long long base = mid;
    int exp = n;

    while (exp > 0){
        if (exp & 1){
            ans = ans * base;
            if (ans > m) return 2;  // too large
        }
        base = base * base;
        if (base > m && exp > 1) return 2; // optimization: base already exceeds m
        exp >>= 1;
    }

    if (ans == m) return 1;
    return 0;
}

/*
exp & 1 is a bitwise AND operation.

exp & 1 checks whether the last bit (the least significant bit) of exp is 1.

If it’s 1, that means exp is odd.

If it’s 0, that means exp is even.


exp >>= 1; means right shift by 1 bit, and it’s equivalent to doing integer division by 2.
*/

int NthRootFinal(int m, int n){

    int low = 1, high = m;
    while(low <= high){

      int mid = (low + high) / 2;

      int midN = func1(mid,n,m); 

      if(midN == 1) return mid;
      else if(midN == 0) low = mid + 1;
      else high = mid - 1;  
    }
    return -1;
}

// This gives us the answer without causing overflow while calculating powers. 
// Now, no cache.

// In every question which deals with binary search on answers, we have to think of these types of edge cases
// where they are overflowing and then deal with them. 

// Finally writing the iterative and recursive binary exponentiation method for Competetive Programming:

// Iterative:

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
} 

// Recursive:

long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}   