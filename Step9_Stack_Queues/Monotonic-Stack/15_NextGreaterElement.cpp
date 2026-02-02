#include<bits/stdc++.h>
using namespace std;

// Brute force solution:

vector<int> nextLargerElement(vector<int> arr) {
    int size = arr.size();
    vector<int> ans(size, 0);
    for (int i = 0; i < size - 1; i++) {
        int elem = arr[i];
        int max = elem;
        for(int j=i;j<size;j++){
            if(arr[j] > max){
                max = arr[j];
                break;
            }
        }
        if(max == elem) ans[i] = -1;
        else ans[i] = max;
    }
    ans[size-1] = -1;
    return ans;
}

// Optimal Solution:

vector<int> nextLargerElement(vector<int> arr) {
    stack<int> st;
    int size = arr.size();
    vector<int> ans(size);
    for(int i=size-1;i>=0;i--){
        if(st.empty()){
            ans[i] = -1;
            st.push(arr[i]);
        }
        else{
            while(!st.empty() && st.top() <= arr[i]) st.pop();
            if(st.empty()) ans[i] = -1;
            else ans[i] = st.top();
            st.push(arr[i]);
        }
    }
    return ans;
}