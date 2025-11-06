#include<bits/stdc++.h>
using namespace std;

// Brute force solution:
void left_rotate(int arr[], int n, int k){
    // rotating by 1 place k number of times.

    for(int i=1;i<=k;i++)
    {
        int first_element = arr[0];
        for(int i=0;i<n;i++)
        {
            if(i < n-1)
            arr[i] = arr[i+1];
            else
            arr[i] = first_element;
        }
    }
}

// T.C.= O(n*k)
// S.C.= O(1)

// Better solution:

void left_rotate_array_k(int arr[], int n, int k){
    k = k % n;
    vector<int> temp;
    for(int i=0;i<k;i++) temp.push_back(arr[i]);
    for(int i=0;i<n-k;i++) arr[i] = arr[i+k];
    for(int i=n-k;i<n;i++) arr[i] = temp[i-(n-k)];
}

/*
When the interviewer asks the time complexity, we don't directly say O(n).
Instead we do this:
T.C. = O(k) + O(n-k) + O(k) = O(n+k).
Even if we know, it is O(n) eventually, we always say O(n+k) by showing how.

S.C. = O(k) and then we say this is the extra space we have used in the 
algorithm because we took a temp vector.
*/

void right_rotate_array_k(int arr[], int n, int k){ 
    k = k % n;
    vector<int> temp; // We cannot take Variable Length Arrays(VLAs) in C++.
    // So we take a temp vector.
    for(int i=n-k;i<n;i++) temp.push_back(arr[i]);
    for(int i=n-k-1;i>=0;i--) arr[i+k] = arr[i]; // tricky part
    // Think why we do not use:
    // for(int i=0;i<n-k;i++) arr[i+k] = arr[i]; instead ??
    for(int i=0;i<k;i++) arr[i] = temp[i];
}

// Optimal solution:
// Always observe very carefully every detail to find out the optimal solution.
void left_rotate1(int arr[],int n, int k){
    // Reversing from 1st to kth index:
    reverse(arr,arr+k); // O(k)
    // arr and arr+k are iterators obviously.
    // Reversing from k+1th to last index:
    reverse(arr+k,arr+n); // O(n-k)
    // Reversing from 1st to last index
    reverse(arr,arr+n); //O(n)
}

// T.C. = O(k) + O(n-k) + O(n) = O(2n) which is slightly more than better solution. No issue.
// But S.C. = O(1). 
// So we eliminated the problem.

int main(){
    int size;
    cin >> size;
    int arr[size];
    int k;
    cin >> k;
    for(int i=0;i<size;i++) cin >> arr[i];
    //left_rotate_array_k(arr,size,k);
    //right_rotate_array_k(arr,size,k);
    left_rotate(arr,size,k);
    for(int i=0;i<size;i++) cout << arr[i] << " ";
    return 0;
}