#include<bits/stdc++.h>
using namespace std;

// Brute force solution:

int minBitsFlip(int start, int goal){
    string x = "";
    while(start != 0){ // O(log start)
        if((start & 1) == 0) x += "0"; // Always use parentheses when combining bitwise(&, |) and comparision (==) operators because '==' has more precedence than '&'.
        else x += "1";
        start >>= 1;
    }
    reverse(x.begin(), x.end()); // O(log start)
    // cout << x << endl;

    string y = "";
    while(goal != 0){ // O(log goal)
        if((goal & 1) == 0) y += "0";
        else y += "1";
        goal >>= 1;
    }
    reverse(y.begin(), y.end()); // O(log goal)
    // cout << y << endl;

    int len1 = x.size(), len2 = y.size(), a = 0, b = 0, count = 0;
    // O(max(len1, len2)) i.e. O(max(log start, log goal))
    if(len1 > len2){
        a = len1 - len2;
        for(int i=0;i<len1-len2;i++){
            if(x[i] == '1') count ++;
        }
        for(int i=0;i<len2;i++){
            if(y[i] != x[a]) count++;
            a++;
        }
    }
    else if(len1 < len2){
        b = len2 - len1;
        for(int i=0;i<len2-len1;i++){
            if(y[i] == '1') count ++;
        }
        for(int i=0;i<len1;i++){
            if(y[b] != x[i]) count++;
            b++;
        } 
    }
    else{
       for(int i=0;i<len1;i++){
            if(y[b] != x[i]) count++;
            b++;
        }  
    }
    return count;

    // T.C. = 2*O(log start + log goal) + O(max(log start, log goal))
    // T.C. = O(log start + log goal)
}

// Better solution:

int minBitsFlip2(int start, int goal) { 
    int comp = start ^ goal, count = 0;
    for(int i=0;i<31;i++){
        if(comp & (1 << i)) count++;
    }
    return count;

    // T.C. = O(31)
    // S.C. = O(1)
}


// Optimal solution:

int minBitsFlip2(int start, int goal) { 
    int comp = start ^ goal, count = 0;
    while(comp != 0){
        count += comp & 1;
        comp >>= 1;
    }
    return count;

    // T.C. = O(log comp) or O(log start^goal)
    // S.C. = O(1)
}
