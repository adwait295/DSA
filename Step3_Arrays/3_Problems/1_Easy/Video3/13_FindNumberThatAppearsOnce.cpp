#include<bits/stdc++.h>
using namespace std;

// Brute force solution: Performing Linear Search for every element and counting the frequency

int findNumber1(int arr[], int n){
    for(int i=0;i<n;i++)
    {
        int num = arr[i];
        int count = 0;
        for(int j=0;j<n;j++)
        {
            if(arr[j] == num) count++;
        }
        if(count == 1) return num;
    }
}

// T.C. = O(n^2)
// S.C. = O(1)

/* Better solution: Hashing
   We have to analyse which data structure to use for hashing.
   If we use hash array, then the size of hash array will be maximum element in the original
   array + 1.
   int maxi = arr[0];
   for(int i=0;i<n;i++) maxi = max(maxi,arr[i]); ---------O(n)
   int hash[maxi+1] = {0};
   for(int i=0;i<n;i++) hash[arr[i]]++; --------------O(n)
   
   for(int i=0;i<n;i++) -----------------------------O(n)
   {
        if(hash[arr[i]] == 1) return arr[i];
   }
   OR
   for(int i=0;i<maxi+1;i++) ------------------------O(maxi+1)
   {
        if(hash[i] == 1) return i;
   }

   So whichever of the two: O(n) or O(maxi+1) is lesser, we will take it because better
   time complexity.
   If we assume here that n < maxi+1, then T.C. = O(3n).

   S.C. = O(maxi + 1)

   But can the hash array be used every time?
   Can the hash array be used for negatives? Probably yes, probably no.
   Can the hash array be used for large numbers like 10^12? No, we cannot hash it because it
   will take a lot of unnecessary space. 

   Thats where we use a map data structure with 'long long' data type as the key & the value
   can be int. We can use maps instead of arrays directly even for smaller numbers for better
   space usage.

   for(int i=0;i<n;i++) mpp[arr[i]]++; ----------O(n log m) in case of maps.
   where n is the size of arr & m is the size of mpp.

   If we use unordered maps, T.C. = O(n) in the best/avg case.
   We know that the worst case T.C. = O(n^2) but that happens in a blue moon.
   So depending upon the situation, we can decide what to use: maps or unordered maps.

   for(auto it:mpp) --------------------------O(n/2 + 1)
   {
        if(it.second == 1) return it.first;
   }
   Why O(n/2 + 1)?
   Because the arr stores every element twice except one.
   For e.g. if size of arr is 7, then it will contain 3 elements that appear twice and one 
   element which appears once.

   So total T.C. = O(n log m) + O(n/2 + 1) = O(n log (n/2 + 1)) + O(n/2 + 1).

   S.C. = O(n/2 + 1) for a map.
*/

// When we tell these many things to the interviewer, he will be impressed for sure. 

// Optimal solution: XOR operation.

int findNumber2(int arr[], int n){
    int xorr = 0;
    for(int i=0;i<n;i++) xorr = xorr ^ arr[i];
    return xorr;
}

// T.C. = O(n)
// S.C. = O(1)

int main(){
    int size;
    cin >> size;
    int arr[size];

    for(int i=0;i<size;i++) cin >> arr[i];

    cout << "Number that appears once: " << findNumber2(arr,size) << endl;

    return 0;
}