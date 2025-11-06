// Remove duplicates in-place from "Sorted" Array.

// We have to put the 'n' unique elements of the array in the first 'n' places in 
// the same array (important) and rest all places/indexes can contain whatever they want.

// Once we have modified the given array, we tell them the number of unique elements.

#include<bits/stdc++.h>
using namespace std;

// Brute force approach:
// As we think about unique elements, the data structure which comes to our mind
// is a Set. 
// Sets store only unique elements and in sorted order.

int Brute_Force_Solution(int arr[], int n){
    set<int> st;
    for(int i=0;i<n;i++) // O(n)
    {
        st.insert(arr[i]); // insert() takes O(log n) for every insertion.
        // S.C. = O(n). Worst case - When all elements are unique
        // stores all the unique elements & in sorted way
    }
    // So total is O(n log n)

    // Modifying the original array:
    int index = 0;
    for(auto it:st) // O(n)
    // auto becomes int here because st contains integers.
    {
        arr[index] = it;
        index++; // the last/final value of index will obviously be the total number of unique elements.
    }

    return index;

    // Total T.C. = O(n log n + n)
    // Total S.C. = O(n)
}

// In order to optimize the brute soln, we have to apply a 2-pointer approach.
// The two pointers are i & j.
// The first unique element will obviously be at first index.
// So we initialize i=0
// i is used to keep the index of the present unique element.
// j goes ahead and compares the other next elements with a[i] to check if there are other unique elements or not.
// if yes, it increases i and stores the unique element there.
// At the end i+1 will be the total number of unique elements.

int Optimal_Solution(int arr[], int n){
    int i = 0;
    for(int j=0;j<n;j++)
    {
        if(arr[j] != arr[i]){
            arr[i+1] = arr[j];
            i++;
        }
    }

    return i+1;
}

int main(){
    int size;
    cin >> size;
    int arr[size];

    for(int i=0;i<size;i++)
    {
        cin >> arr[i];
    }

    cout << "Number of unique elements: " << Optimal_Solution(arr,size) << endl;

    return 0;
}