#include<bits/stdc++.h>
using namespace std;

int findXOR(int n){
    if(n % 4 == 0) return n;
    else if(n % 4 == 1) return 1;
    else if(n % 4 == 2) return n+1;
    else return 0;
}

int findRangeXOR(int l, int r){
    return findXOR(l-1) ^ findXOR(r);
}