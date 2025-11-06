// Insertion Sort - takes an element and places it in the correct position

#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[],int n){
    for(int i=0;i<n;i++)
    {
        int j=i;
        while(j>0 && arr[j-1]>arr[j])
        {
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;

            j--;
            cout << "Runs \n";
        }
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];

    for(int i=0;i<n;i++) cin >> arr[i];

    insertion_sort(arr,n);

    for(int i=0;i<n;i++) cout << arr[i] << " ";

    return 0;
}

/*
Time complexity:

In the worst case (We want ascending, but the given array is in descending),
The inner loop runs for 0+1+2+......+(n-1)times
So T.C. = O(n^2) in the worst and average cases.

In the best case (The array is already sorted),
The inner loop runs for 0 times for every i because the a[j-1]>a[j] always gives false.
The outer loop runs for n times.
So T.C. = O(n) in the best case.
*/