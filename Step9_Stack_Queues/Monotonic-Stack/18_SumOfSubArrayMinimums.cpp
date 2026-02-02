#include<bits/stdc++.h>
using namespace std;

class Solution {   
public:
    const int MOD = 1000000007; // don't write 1e9 + 7.
    // const long long MOD = 1000000007LL;

    int sumSubarrayMins(vector<int> &arr) {
        long long sum = 0;
        int size = arr.size();
        for(int i=0;i<size;i++){
            int mini = INT_MAX;
            for(int j=i;j<size;j++){
                mini = min(mini, arr[j]);
                sum = (sum + mini) % MOD; // after every operation, we can do a modulo to avoid accidental overflow (although there won't be overflow as we have used long long). 
            }
        }
        // cout << sum << endl;
        return sum;
    }

    // T.C. = O(n^2)
    // S.C. = O(1)
};

class Sol{
    private:
    vector<int> findNSE(vector<int> &arr){
        stack<int> st;
        int size = arr.size();
        vector<int> nse(size, 0);

        for(int i=size-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            nse[i] = (st.empty()) ? size : st.top();

            st.push(i);
        }

        return nse;
    }

    vector<int> findPSEE(vector<int> &arr){
        stack<int> st;
        int size = arr.size();
        vector<int> psee(size, 0);

        for(int i=0;i<size;i++){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            psee[i] = (st.empty()) ? -1: st.top();
            st.push(i);
        }

        return psee;
    }

    public:
    int sumSubarrayMins(vector<int> &arr){
        vector<int> nse = findNSE(arr);
        vector<int> psee = findPSEE(arr);

        const int MOD = 1000000007; long long sum = 0;

        int size = arr.size();
        int left = 0, right = 0;

        for(int i=0;i<size;i++){
            left = i - psee[i];
            right = nse[i] - i;

            long long freq = left * right * 1LL;

            int val = (freq * arr[i] * 1LL) % MOD;

            sum = (sum + val) % MOD;
        }

        return sum;
    }
};