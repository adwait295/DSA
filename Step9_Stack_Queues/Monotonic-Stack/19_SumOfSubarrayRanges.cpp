#include<bits/stdc++.h>
using namespace std;

class Solution {
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

    long long sumSubarrayMins(vector<int> &arr){
        vector<int> nse = findNSE(arr);
        vector<int> psee = findPSEE(arr);

        long long sum = 0;

        int size = arr.size();
        int left = 0, right = 0;

        for(int i=0;i<size;i++){
            left = i - psee[i];
            right = nse[i] - i;

            long long freq = left * right * 1LL;

            long long val = freq * arr[i];

            sum = sum + val;
        }

        return sum;
    }

    vector<int> findNGE(vector<int> &arr){
      stack<int> st;
      int size = arr.size();
      vector<int> nge(size, 0);

      for(int i=size-1;i>=0;i--){
        while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();
        nge[i] = (st.empty()) ? size : st.top();
        st.push(i);
      }

      return nge;
    }

    vector<int> findPGEE(vector<int> &arr){
      stack<int> st;
      int size = arr.size();
      vector<int> pgee(size, 0);

      for(int i=0;i<size;i++){
        while(!st.empty() && arr[st.top()] < arr[i]) st.pop();
        pgee[i] = st.empty() ? -1 : st.top();
        st.push(i);
      }
      return pgee;
    }

    long long sumSubarrayMaxs(vector<int> &arr){
      vector<int> nge = findNGE(arr);
      vector<int> pgee = findPGEE(arr);

      long long sum = 0;

        int size = arr.size();
        int left = 0, right = 0;

        for(int i=0;i<size;i++){
            left = i - pgee[i];
            right = nge[i] - i;

            long long freq = left * right * 1LL;

            long long val = freq * arr[i];

            sum = sum + val;
        }

        return sum;

    }
public:
    long long subArrayRanges(vector<int> &arr) {
      return sumSubarrayMaxs(arr) - sumSubarrayMins(arr);
    }
};