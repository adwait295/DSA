#include<bits/stdc++.h>
using namespace std;

vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
    int size0 = indices.size();
    vector<int> ans(size0, 0);
    int size = arr.size();
    for(int i=0;i<size0;i++){
        int index = indices[i];
        int elem = arr[index];
        int count = 0;
        for(int j=index+1;j<size;j++){
            if(arr[j] > elem) count++;
        }
        ans[i] = count;
    }
    return ans;
}