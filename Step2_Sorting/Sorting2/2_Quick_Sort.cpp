/*
Quick Sort:
1. Pick a pivot & place it in its correct place in the sorted array.
2. Smaller on the left & larger on the right.
*/ 

// Like in merge sort, instead of making two separate arrays, here too we will use pointers like low and high
// to explain from which index to which index are the first & second hypothetical arrays.

#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i<j){
        while(arr[i] <= pivot && i < high){ // i<high is the boundary condition
            // We choose to keep the element equal to the pivot on its left side by using <=
            // We can keep it in the right side as well but we have to decide beforehand which side we want to keep it.
            // As we write <= in this while loop, we will write > in the next while loop.
            i++;
        }

        while(arr[j] > pivot && j > low){ // j>low is the boundary condition
            // If we want to keep equal element on right side, we can write >= here and < in the previous while loop
            j--;
        }

        if(i < j){
            swap(arr[i],arr[j]);
        }
    }

    swap(arr[low],arr[j]);
    return j;
}

void quickSort(vector<int> &arr, int low, int high){
    if(low < high){ // If low = high, then it is a single element array/vector.
        int partition_index = partition(arr,low,high);
        quickSort(arr,low,partition_index-1);
        quickSort(arr,partition_index+1,high);
    }
}

int main(){
    vector<int> arr;
    int n;
    cin >> n;

    for(int i=1;i<=n;i++){
        int element;
        cin >> element;
        arr.push_back(element);
    }

    quickSort(arr,0,arr.size()-1);

    for(auto it:arr){
        cout << it << " ";
    }

    return 0;
}

// T.C. = O(n log n) 
// log n because of dividing & n because of partition().

// S.C. = O(1), not taking the recursive stack space into account.