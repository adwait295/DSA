// Selection sort - Select minimums and swap

#include<bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n){
    for(int i=0;i<n-1;i++)
    {
        int min = i;
        for(int j=i;j<n;j++)
        {
            if(arr[j] < arr[min]) 
            min = j;
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];

    for(int i=0;i<n;i++) cin >> arr[i];

    selection_sort(arr,n);

    for(int i=0;i<n;i++) cout << arr[i] << " ";

    return 0;
}

/*
T.C.:
Inner loop of selection_sort runs for:
n+(n-1)+(n-2)+..........+2 times 
which is nearly equal to n(n-1)/2.

so T.C. = O((n^2+n)/2) = O(n^2)
and this is the best, average and worst case T.C.
*/