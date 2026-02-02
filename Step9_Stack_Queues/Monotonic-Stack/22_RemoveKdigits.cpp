#include<bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k) {
    int n = num.size();
    stack<char> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && num[i] < st.top() && k > 0){
            st.pop();
            k--;
        }
        st.push(num[i]);
    }

    while(!st.empty() && k > 0){
        k--;
        st.pop();
        if(st.empty()) return "0";
    }

    string res = "";
    while(!st.empty()){
        res = st.top() + res;
        st.pop();
    }

    /*
    If we write this way, it will give me MLE (Memory Limit Exceeded):
     string res = "";
        // Reversing and adding to the result:
        while(!st.empty()){
            char ch = st.top();
            res = ch + res;
            st.pop();
        }

        because:
        string is immutable-like for concatenation.
        Every time you do res = char + res,
        A new string is allocated.
        Entire old res is copied.
        If the stack has n characters, this becomes:
        1 + 2 + 3 + ... + n  = O(n²)
    */

    int i = 0;
    for(;i<res.size();i++) if(res[i] != '0') break;

    res = res.substr(i);
    if(res == "") return "0";
    else return res;
}