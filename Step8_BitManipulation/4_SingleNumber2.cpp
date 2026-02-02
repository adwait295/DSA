#include<bits/stdc++.h>
using namespace std;

// Brute force solution:

int singleNumberBrute(vector<int> &arr){
    unordered_map<int, int> mpp;
    for(int i=0;i<arr.size();i++) mpp[arr[i]]++; // O(n)
    for(auto it: mpp){ // O(n/3 + 1)
        if(it.second == 1) return it.first;
    }
    return 0;

    // T.C. = O(n + n/3 + 1)
    // S.C. = O(n/3 + 1)
}

// Better solution:

int singleNumberBetter(vector<int> &arr){
    int ans = 0;
    for(int i=0;i<32;i++){
        int count = 0;
        for(int j=0;j<arr.size();j++){
            if(arr[j] & (1 << i)) count++;
        }
        if(count % 3 == 1) ans |= 1 << i;
    }
    return ans;

    // T.C. = O(32*n)
    // S.C. = O(1)
}

// Even better & practically optimal solution: 

// My version:

int singleNumberBest(vector<int> &arr){
    sort(arr.begin(), arr.end()); // O(n log n)
    int element = arr[0], count = 0;
    for(int i=0;i<arr.size();i++){ // O(n)
        if(arr[i] == element) count++;
        else{
            if(count != 3) return element;
            element = arr[i];
            count = 1;
        }
    }
    if(count != 3) return arr[arr.size()-1];

    // T.C. = O(n log n + n)
    // S.C. = O(1)
}

// Better than my version:

int singleNumberBestt(vector<int> &arr){
    sort(arr.begin(), arr.end());

    for(int i=1;i<arr.size();i+=3){
        if(arr[i] != arr[i-1]) return arr[i-1];
    }
    return arr[arr.size()-1];

    // T.C. = O(n log n + n/3)
    // S.C. = O(1)
}

// Most optimal and practically not possible to think of in an interview:

int singleNumberOptimal(vector<int> &arr){
    int ones = 0, twos = 0;
    for(int i=0;i<arr.size();i++){
        ones = (ones ^ arr[i]) & (~twos);
        twos = (twos ^ arr[i]) & (~ones);
    }
    return ones;

    // T.C. = O(n)
    // S.C. = O(1)
}

