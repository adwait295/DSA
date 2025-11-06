// Hashing - prestoring something and fetching when required

// Number hashing can be done using arrays.

// Creating hash array or frequency array 
// with size = max element that can occur in the main array + 1
// and assigning each element as 0 initially
// i.e. count of each element = 0 at first

// Prestoring:
// precalculating the number of times each element
// occurs in the main array and storing the frequencies
// in the corresponding indexes in the hash array

// Fetching:
// the number of times a number i occurs in the main array
// by just doing hash array[i] which already stores the
// frequency of each number in the main array

#include<bits/stdc++.h>
using namespace std;

int a[int(1e7)]; // example of global declaration of integer array
// or simply int a[10000000];

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    // Precomputation: Lets assume the max element that can be stored in the main array = 12
    int hash[13] = {0};
    for(int i=0;i<n;i++)
    {
        hash[arr[i]] += 1;
    }

    int Q; // Number of number searches i.e. Q
    cin >> Q;
    while(Q--)
    {
        int x;
        cin >> x; // Entering each number to be searched in the array
        // Fetching:
        cout << hash[x] << endl;
    }

    return 0;
}

/*
What if size of array needs to be (or in the order of) 1e9 or 10^9?

No it can't be. The max size of int array inside main()
can be 10^6 and the max size of int array globally can be 
10^7.

For boolean array, the max size is 10^7 inside main() and
10^8 globally.

If we try to declare an integer array of size 10^7 inside main(), it will 
throw us a segmentation fault.

While declaring anything globally we don't need to give
initial value as 0 as anything declared globally is 
automatically initialized to 0 instead of any garbage 
values.
*/

