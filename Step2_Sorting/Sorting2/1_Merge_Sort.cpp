// Merge Sort: Divide & Merge (Hypothetically)

#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high) { // take care to pass everything by reference
    vector<int> temp;
    // [low..mid]         1st Hypothetical Array
    // [mid+1..high]      2nd Hypothetical Array
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }

    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=low;i<=high;i++){ 
        // copying the elements from temp vector to original arr vector
        // As the arr vector is passed by reference, any change that occurs here will reflect in the original
        arr[i] = temp[i-low];
    }
}

void mergeSort(vector<int> &arr, int low, int high) {
    if (low == high) return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main(){
    vector<int> arr;
    int size;
    cin >> size;

    for(int i=1;i<=size;i++){
        int n;
        cin >> n;
        arr.push_back(n);
    }

    mergeSort(arr,0,size-1);

    for(auto it:arr){
        cout << it << " ";
    }

    return 0;
}

/*
T.C. of mergeSort() = O(n log2 n) in the best, average and worst cases.
T.C. of merge() = O(n)

S.C. of mergeSort() or merge() = O(n) because temp will store n elements max.
*/

