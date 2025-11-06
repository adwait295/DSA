// Bubble Sort - push the max to the last by adjacent swapping

// For every single complete round of swaps, the largest element of the array considered goes to the last and is sorted
// i.e. in the 4th round of swaps, the 4th largest number goes to the last of the array considered, i.e. to the 4th position from the last

#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int n){
    for(int i=0;i<n-1;i++)
    {
        int didSwap = 0;
        for(int j=0;j<n-i;j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                didSwap++;
            }
        }
        if(didSwap == 0) // For optimization 
        break; // If not a single swap happens after a complete round of checks, then the array is already sorted.
        
        cout << "Checking how many times the outer loop runs \n";
    }

    /*
    OR
    for(int i=n-1;i>=1;i--)
    {
        for(int j=0;j<i;j++) if j<=i, then runtime error because we are trying to access an index which is not there in the array
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1]; j+1 becomes out of array if we take j<=i in condition
                arr[j+1] = temp;
            }
        }
    }
    Runtime error because we are accessing an index which is not present
    */
}

int main(){
    int n;
    cin >> n;
    int arr[n];

    for(int i=0;i<n;i++) cin >> arr[i];

    bubble_sort(arr,n);

    for(int i=0;i<n;i++) cout << arr[i] << " ";

    return 0;
}

/*
Time complexity: Similar to Selection Sort
n+(n-1)+(n-2).......+2times

so T.C. = O(n^2)
This is the worst case and average case time complexity.

In a round of checks, if we notice that there is not a single swap,
then we know that the array has already been sorted. So we don't need to proceed further. 

We do optimization of the code for that case to come out of the code whenever we realize the array has already been sorted

Best case: If the array is already sorted from the beginning
Hence in the best case the code will run only n times.
i.e. after the first round of checks only, we will realise that the array is already sorted.
So in best case, the outer loop will run only one time and break. So the cout never executes in the best case.

so T.C. = O(n) in the best case.
*/ 
