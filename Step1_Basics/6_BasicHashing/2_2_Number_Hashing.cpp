// For n above 10^7, we cannot use 
// integer arrays even globally for number hashing.
// So array hashing cannot be done beyond n = 10^7
// So we use maps or unordered maps in C++ STL.

// map<int,int> is a key-number,value-frequency pair here. (key,value) is (number,frequency)

/*
When we used arrays, we had to store frequencies 
of even those elements which were not in the main array
i.e. the frequencies from element 0 to the maximum element 
in the main array
*/

/*
But in maps, we only store key-value pairs of those elements
which are actually present in the main array, so it reduces
memory. Moreover we can also store the numbers of any order
such as 10^18 by just doing map<long, int> so there is no
limit unlike arrays whose limit was 10^6 inside main()
and 10^7 globally.
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
        // Precomputation can directly be done here 
        // to avoid extra lines of code.
        // But, it does not affect T.C. as n+n=2n & O(2n) is equivalent to O(n).
        // By writing mpp[arr[i]]++ inside this loop 
        // and defining the map before the loop 
    }

    // Pre-compute:
    map<int,int>mpp; // Depending upon the size of numbers, we can take map<long,int> or map<long long,int> or whatever required.
    // e.g. if we want to take a value as big as 10^9 , we can take map<long,int>.
    for(int i=0;i<n;i++)
    {
        mpp[arr[i]]++;
        // If a key is not already present in the map
        // it knows that mpp[that key] is 0. so,
        // it makes the key and incres the value to 1
        // when it first appears in the main array.

        // If a key is already present, it just increases its value by 1.
    }

    // Maps store the keys in sorted order
    // To show this, we can iterate in the map and show it:
    for(auto it:mpp)
    {
        cout << it.first << "->" << it.second << endl;
    }

    int Q;
    cin >> Q;
    while(Q--)
    {
        int number;
        cin >> number;
        // fetch:
        cout << mpp[number] << endl;
        // If a key is not present in the map,
        // mpp[that key] = 0, not undefined.
    }
    return 0;
}