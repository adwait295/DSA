// There is no brute, better and optimal comparisions in this problem. 
// We can directly write the best solution.

#include<bits/stdc++.h>
using namespace std;

int is_Sorted(vector<int> &arr, int n){
    for(int i=1;i<n;i++)
    {
        if(arr[i] >= arr[i-1]){} // For non-descending. e.g. {1,2,2,3,5,5}
        else return false;        
    }
    return true;

    // T.C. = O(n)
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

    int check_Sort = is_Sorted(arr,size);

    if(check_Sort == 0)
    cout << "Array is not sorted" << endl;
    else cout << "Array is sorted" << endl;

    return 0;
}