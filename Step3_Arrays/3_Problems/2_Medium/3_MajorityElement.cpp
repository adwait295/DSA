#include<bits/stdc++.h>
using namespace std;

// Brute force solution:

int majElement1(vector<int> &arr){
    int size = arr.size();
    for(int i=0;i<size;i++)
    {
        int cnt = 0;
        for(int j=0;j<size;j++)
        {
            if(arr[j] == arr[i]) cnt++;
        }
        if(cnt > (size/2)) return arr[i];
    }
    return -1;
}

// T.C. = O(n^2)
// S.C. = O(1)

// Better Solution: Hashing

int majElement2(vector<int> &arr){
    int size = arr.size();
    map<int, int> hashmap;
    for(int i=0;i<size;i++) // O(n)
    {
        hashmap[arr[i]] ++; // O(log n)
        if(hashmap[arr[i]] > (size/2)) return i;
    }
    return -1;
    /*
    We could also do this (after we have kept the frequencies in the hashmap) to get the above:
    for(auto it: hashmap)
    {
        if(it.second > (size/2)) return it.first;
    }
    */
}

// T.C. = O(n log n)
// S.C. = O(n) , this worst case only happens when the array has all unique elements.

// Optimal solution: Moore's Voting Algorithm

int majElement3(vector<int> &arr){
    int size = arr.size();

    // 1. Moore's voting algorithm:
    int el = 0;
    int cnt = 0;

    for(int i=0;i<size;i++) // O(n)
    {
        if(cnt == 0) el = arr[i];
        if(arr[i] == el) cnt++;
        else cnt--;
    }

    // 2. Verifying: 
    // This step won't be required if the problem statement states that there always 
    // exists a majority element in the given array. 
    // We only do this to check if the array might not have a majority element at all.

    // Because if it has, then it will always be 'el'.
    // If 'el' isn't the majority element after verifying, then array has no majority element.
    int count = 0;
    for(int i=0;i<size;i++) // O(n)
    {
        if(arr[i] == el) count++;
    }

    if(count > (size/2))
    return el;

    return -1;
}

//T.C. = O(2n)
//S.C. = O(1)

int main(){
    int size;
    cin >> size;
    vector<int> arr;
    for(int i=1;i<=size;i++)
    {
        int n;
        cin >> n;
        arr.push_back(n);
    }

    cout << "Majority Element: " << majElement3(arr) << endl;

    return 0;
}



