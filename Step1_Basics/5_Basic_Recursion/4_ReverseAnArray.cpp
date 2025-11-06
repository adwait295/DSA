#include<bits/stdc++.h>
using namespace std;

void reverseArray(int i, int arr[], int n){ // Functional Recursion
    
    // Single Pointer method:

    if (i >= n/2) return;
    swap(arr[i],arr[n-i-1]);
    reverseArray(i+1,arr,n);

    /*
    OR
    Double pointer method:

    We can take reverseArray(int i, int arr[], int l)
    and return when (i>=l) and swap (arr[i],arr[l]) 
    and call reverseArray(i+1,arr,l-1).
    From main(), we can call reverseArray(0,arr,n-1).
    */
}

int main(){
    int n;
    cin >> n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    reverseArray(0,arr,n); // Arrays are always passed by reference, so it's okay.

    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }

    return 0;

}