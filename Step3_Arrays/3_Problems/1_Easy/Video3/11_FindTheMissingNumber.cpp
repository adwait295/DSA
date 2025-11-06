#include<bits/stdc++.h>
using namespace std;

// Brute force solution: 
// Searching for each element(1 to n) in the array.

int findNumber1(int arr[], int n){
    for(int i=1;i<=n;i++)
    {
        int flag = 0;
        for(int j=0;j<n;j++)
        {
            if(arr[j] == i){
                flag++;
                break;
            }
        }
        if(flag == 0) return i;
    }
}

// T.C. = O(n^2), not "exactly" but "close to" because:
// 1. It may happen that some i which is less than n may be found to be absent in the array.
// 2. In the worst case of outer loop i.e. i=n, is not found, then the T.C. is close to n^2, 
// (still not exactly equal) because not every i(before i=n) will go from j=0 to j=n-1.

// We always tell every tiny detail to the interviewer so that our thought process is very
// clear to him and we drive the interview.

// S.C. = O(1)

// Better solution: Using hash array to mark the element present in the original array as 1.

int findNumber2(int arr[], int n){
    int hash[n+1] = {0};
    for(int i=0;i<n;i++)
    {
        hash[arr[i]] = 1;
    }

    for(int i=1;i<=n;i++)
    {
        if(hash[i] == 0) return i;
    }
}

// T.C. = O(2n)
// S.C. = O(n)

// There are two optimal solutions with one slightly better than the other.
// Optimal solution 1: Finding the sum.

int findNumber3(int arr[], int n){
    int sum0 = n * (n+1) / 2;
    int sum1 = 0;
    for(int i=0;i<n;i++)
    {
        sum1 = sum1 + arr[i];
    }
    return sum0-sum1;
}

// T.C. = O(n)
// S.C. = O(1)

// Optimal solution 2: XOR operation.

int findNumber4(int arr[], int n){
    int xor1 = 0, xor2 = 0;

    for(int i=1;i<=n;i++) xor1 = xor1 ^ i; // 1^2^3^4^5
    for(int i=0;i<n;i++) xor2 = xor2 ^ arr[i]; // if missing number = 3, xor2 = 0^1^2^4^5
    return xor1^xor2;
}

/* T.C. = O(2n), then how isn't the optimal solution 1 better?
   NO, we can make the T.C. = O(n) by doing this:
    for(int i=0;i<n;i++)
    {
        xor2 = xor2 ^ arr[i];
        xor1 = xor1 ^ (i+1);
    }

   S.C. = O(1) 

   How is it better than optimal solution 1?
   Because n is in order of 10^5, then sum0 becomes order of 10^10, which cannot be stored
   in int. We need long for that which takes slightly more space.

   But when n is in order of 10^5, xor1 still remains within range. 

   So solution 2 is slightly better.
*/

int main(){
    int size;
    cin >> size;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cin >> arr[i];
    }
    cout << "Missing element: " << findNumber4(arr,size) << endl;

    return 0;
}