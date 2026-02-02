#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// Brute force solution (My solution):
int divide(int dividend, int divisor) {
    ll absDividend = abs((ll)dividend), absDivisor = abs((ll)divisor), sum = 0, count = 0;
    while(sum <= absDividend){
        sum += absDivisor;
        count++;
    }

    count--;

    if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)){
        if((0 - count) < INT_MIN){
            return INT_MIN;
        }
        return (0 - (int)count);
    }
    else{
        if(count > INT_MAX) return INT_MAX;
        else return (int)count;
    }
    return 0;

    // T.C. = O(dividend / divisor)
    // S.C. = O(1)
}

// Optimal solution:

int divide1(int dividend, int divisor){
    if(dividend == divisor) return 1;
    if(divisor == 1) return dividend;
    if(dividend == INT_MIN && divisor == -1) return INT_MAX;

    bool isPositive = !((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0));

    ll n = abs((ll)dividend), d = abs((ll)divisor);

    ll ans = 0, sum = 0;

    while(n >= d){
        ll temp = d, multiple = 1;
        while(n >= (temp << 1)){
            temp <<= 1;
            multiple <<= 1;
        }
        n -= temp;
        ans += multiple;
    }

    if(ans > INT_MAX) return isPositive ? INT_MAX : INT_MIN;

    return isPositive ? ans : -ans;

    // T.C. = O(log n * log n)
    // S.C. = O(1)
}

// Different version of the same solution:

int divide(int dividend, int divisor) {
        
    // Edge cases
    if(dividend == divisor) return 1;
    if(dividend == INT_MIN && divisor == -1) return INT_MAX;
    if(divisor == 1) return dividend;
        
    // Variable to store the sign of result
    bool isPositive = true;
        
    // Updating the sign of quotient
    if(dividend >= 0 && divisor < 0) 
        isPositive = false;
    else if(dividend <= 0 && divisor > 0)
        isPositive = false;
            
    // Storing absolute dividend & divisor
    long n = dividend;
    long d = divisor;
        
    n = abs(n);
    d = abs(d);
        
    // Variable to store the answer
    int ans = 0;
        
    /* Looping while dividend is 
    greater than equal to divisor */
    while(n >= d) {
        int count = 0;
            
        /* Finding the required 
        largest power of 2 */
        while(n >= (d << (count+1))) {
            count++;
        }
        
        // Updating the answer & dividend
        ans += (1 << count);
        n -= (d << count);
    }
        
    // Handling overflowing condition
    if(ans == (1 << 31) && isPositive) 
        return INT_MAX;
    if(ans == (1 << 31) && !isPositive)
        return INT_MIN;
    
    /* Returning the quotient 
    with proper sign */
    return isPositive ? ans : -1*ans;
}