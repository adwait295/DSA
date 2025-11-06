#include<bits/stdc++.h>
using namespace std;

// Finding number of times an element occurs in an array

int count(int n, int arr[],int x){ // Brute force approach
    int cnt = 0;
    for(int i=0;i<x;i++)
    {
        if(arr[i] == n)
        cnt = cnt + 1;
    }
    return cnt;
}

int main(){
    int n;
    cin >> n;
    int x;
    cin >> x;

    int arr[x];
    for(int i=0;i<x;i++)
    {
        cin >> arr[i];
    }

    cout << count(n,arr,x);
}

/*
What's wrong with this approach?

The time complexity for every single number search is O(n)
So for Q number searches, the T.C. = O(Q*n)
if Q = 10^5 and n = 10^5 , then T.C = O(10^10)
As we know 10^8 operations take 1 sec , so 
10^10 operations will take 100 sec, which isn't wanted

Hence comes the concept of hashing.

*/