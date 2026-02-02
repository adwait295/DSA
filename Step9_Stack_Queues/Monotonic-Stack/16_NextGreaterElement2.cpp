#include<bits/stdc++.h>
using namespace std;

// Brute force solution: It will give *Time Limit Exceeded*

vector<int> nextGreaterElements(vector<int> &arr) {
    int size = arr.size();
    vector<int> ans(size, -1);
    for (int i = 0; i < size; i++) {
        for (int j = (i + 1)%size; j != i; j = (j + 1) % size) {
            if (arr[j] > arr[i]) {
                // cout << arr[j] << endl;
                ans[i] = arr[j];
                break;
            }
        }
    }
    return ans;
}

// Optimal solution : My solution

vector<int> nextGreaterElements(vector<int> &arr) {
    stack<int> st;
    int size = arr.size();
    vector<int> ans(size, -1);
    int maxIndex = -1, maxi = INT_MIN;
    for(int i=0;i<size;i++){
        if(arr[i] > maxi){
            maxi = max(maxi, arr[i]);
            maxIndex = i; 
        }
    }
    ans[maxIndex] = -1;
    st.push(maxi);
    for(int i=(maxIndex-1+size)%size;i!=maxIndex;i=(i-1+size)%size){
        if(st.empty()) ans[i] = -1;
        else{
            while(!st.empty() && arr[i] >= st.top()) st.pop();
            if(st.empty()) ans[i] = -1;
            else ans[i] = st.top();
            // cout << ans[i] << " " << i << endl;
            st.push(arr[i]);
        }
    }
    return ans;
}