#include<bits/stdc++.h>
using namespace std;

string DecimalToBinary(int n){ // We can also use list or any other appropriate DS instead of string to store the bits.
    string result = "";
    while(n > 0){ // or n != 1
        if(n % 2 == 0) result += "0";
        else result += "1";

        n = n / 2;
    }
    reverse(result.begin(), result.end());

    return result;

    // T.C. = O(log n)
    // S.C. = O(log n) as number of steps is same as the number of bits we are storing in the string.
}

int BinaryToDecimal(string x){
    int len = x.size();
    len -= 1;
    
    int i = 0; int res = 0;
    while(len >= 0){
        if(x[i] == '1') res += pow(2,len);

        len --; i++;
    }

    return res;

    // T.C. = O(n)
    // S.C. = O(1)
}

// OR:

int BinaryToDecimal1(string x){
    int len = x.size();

    int p2 = 1, num = 0;
    for(int i=len-1;i>=0;i--){
        if(x[i] == '1') num += p2;

        p2 *= 2;
    }
    return num;

    // T.C. = O(n), where n is the size of string.
    // S.C. = O(1)
}

// Count the number of set bits in an integer:

int brute(int x){
    int count = 0;

    while(x > 0){
        count += x & 1; // same as if(x % 2 == 1) count++;
        x >>= 1; // same as x /= 2;
    }

    return count;

    // T.C. = O(log n), each bit is checked once. 
    // S.C. = O(1)
}

int better(int x){
    int count = 0;
    while(x){ // or x != 0
        x &= (x-1); // continuously turning off the last set bit (right most)
        count ++;
    }
    return count;

    // T.C. = O(k) where k is the number of set bits.
    // S.C. = O(1)
}

int optimal(int x){
    return __builtin_popcount(x); // C++ STL.

    // T.C. = O(1)
    // S.C. = O(1)
}

int main(){

    // int n;
    // cin >> n;
    // cout << DecimalToBinary(n) << endl;

    // string s;
    // getline(cin, s);
    // cout << BinaryToDecimal(s) << endl;
    // cout << BinaryToDecimal1(s) << endl;

    int a;
    cin >> a;
    // cout << brute(a) << endl;
    // cout << better(a) << endl;
    cout << optimal(a) << endl;

    return 0;
}