#include<bits/stdc++.h>
using namespace std;

// My solution:

string removeOuterParentheses(string s) {
    stack<char> st; // O(n/2) S.C. in the worst case when e.g. s = "((((()))))". It won't be O(n) because in the question it is given s is a valid parentheses string. 
    string ans = ""; // close to O(n) S.C. for storing the answer to return it.
    for(int i=0;i<s.size();i++){ // O(n) T.C.
        if(s[i] == '(') st.push(s[i]);
        else st.pop();
        if(st.empty()){
            string a = s.substr(0, i+1); // O(n) S.C. in the worst case 
            // e.g. s = "((((()))))"
            a.erase(0, 1);
            a.erase(a.size()-1, 1);
            ans += a;
            s = s.substr(i+1);
            i = -1;
        }
    }
    return ans;

    // T.C. = O(n)
    // S.C. = O(n/2 + n) (for our algorithm) + O(n) (to store the answer and return it)
}

// Editorial:

string removeOuterParentheses(string s){
    string ans = ""; // close to O(n) S.C. 
    int balance = 0;
    for(char c: s){ // O(n) T.C. 
        if(c == '('){
            if(balance > 0) ans += c;
            balance++;
        }
        else{
            balance--;
            if(balance > 0) ans += c;
        }
    }
    return ans;

    // T.C. = O(n)
    // S.C. = O(n) just to return the answer. No additional data structures are used.
}