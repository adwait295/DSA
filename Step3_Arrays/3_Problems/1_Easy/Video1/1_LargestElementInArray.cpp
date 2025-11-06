// Brute force solution - Sorting the array in ascending and accessing the last element.
// If we use Quick Sort, T.C. = O(n log n) & S.C. = O(1) ignoring the recursive stack space.

// In this case, we do not have a Better solution.

// In order to find the optimal solution, we need to optimize n log n.

#include<bits/stdc++.h>
using namespace std;

int largest_element(vector<int> &arr, int n){
    int largest = arr[0];
    for(int i=0;i<n;i++)
    {
        if(arr[i] > largest)
        largest = arr[i];
    }
    return largest;

    // T.C. = O(n) which is better than O(n log n).
}

int main(){
    vector<int> arr;
    int size;
    cin >> size;
    
    for(int i=1;i<=size;i++)
    {
        int element;
        cin >> element;
        arr.push_back(element);
    }

    cout << "Largest Element: " << largest_element(arr,size);
    return 0;
}

// We can also do it using arrays or any other data structure.
// But we have to do whatever format or condition the online compiler is asking us to
// do it in.