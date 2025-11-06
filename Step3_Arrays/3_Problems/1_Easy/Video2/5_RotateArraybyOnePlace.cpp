#include<bits/stdc++.h>
using namespace std;

// In very easy problems like these, we can directly write the optimal solution

void left_rotate_array(int arr[], int n){
    int first_element = arr[0];
    for(int i=0;i<n;i++)
    {
        if(i < n-1)
        arr[i] = arr[i+1];
        else
        arr[i] = first_element;
    }
}
int main(){
    int size;
    cin >> size;
    int arr[size];
    for(int i=0;i<size;i++) cin >> arr[i];
    left_rotate_array(arr,size);
    for(int i=0;i<size;i++) cout << arr[i] << " ";
    return 0;
}

// T.C. = O(n)
// S.C. = O(1)
/*
Whenever we talk about space complexity, we talk about the extra space that
we use in the algorithm.

When the interviewer asks what is the space used in the algorithm, we must
say that the space used is O(n) because we are using the arr in the algorithm
but that is the space which is already given to us. The extra space that
our algorithm is using is O(1) and hence the time complexity.

So in the interview, we should make it clear by describing it. 

This way every concept of us is crystal clear to the interviewer and 
impresses them. 
*/