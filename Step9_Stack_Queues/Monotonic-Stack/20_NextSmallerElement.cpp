#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElements(const vector<int>& arr) {
    int size = arr.size();
    stack<int> st;

    vector<int> nse(size, 0);

    for(int i=size-1;i>=0;i--){
        while(!st.empty() && st.top() >= arr[i]) st.pop();
        if(st.empty()) nse[i] = -1;
        else nse[i] = st.top();

        st.push(arr[i]);
    }

    return nse;
}