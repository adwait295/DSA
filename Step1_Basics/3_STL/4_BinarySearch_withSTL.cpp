/* We do Binary Search with C++ STL because it saves a lot of time in contests.

Q1. Check if X exists in the sorted array or not?
    
A[] = {1,4,5,8,9}
    
bool res = binary_search(a,a+n,3);   Hence res = false
where a is an iterator that points to position of 1 and a+n is an iterator that points to the position just after 9.
3 is the element to be searched for.

binary_search() is a C++ STL which internally does a binary search.

bool res = binary_search(a,a+n,4);   Hence res = true
*/

/*
lower_bound function: Behaves similarly to binary_search()
It returns an iterator which points to the position of the first occurence of the element being searched.

a[] = {1,4,5,6,9,9}

int ind = lower_bound(a,a+n,4) - a;   Hence ind = 1
We subtract 'a' because a is the iterator pointing to the 1st element, and lower_bound() returns an iterator pointing to first occurence of 4.
So when we subtract both positions, we get the index of the first occurence of the element.

int ind = lower_bound(a,a+n,7) - a;   Hence ind = 4
As 7 is not present in the array, the lower_bound() returns a pointer that points to the immediate greater element to 7.
i.e. 9 in the array.

int ind = lower_bound(a,a+n,10) - a;   Hence ind = 6
As 10 is not present in the array, it points to the immediate greater which is also not present in the array. 
So it points to a+n. 

lower_bound() returns an iterator. To get the index, we subtract by a which is also an iterator pointing the first element.

Using lower_bound() in vectors:
int ind = lower_bound(a.begin(),a.end(),x) - a.begin();
*/

/*
upper_bound function: also behaves similarly to binary_search()
It returns an iterator which points to the position of the immediate larger element to the element being searched for.
So, the iterator's previous index will be the last occurence of the element being searched (if the element is present in the array).

a[] = {1,4,5,6,9,9}

int ind = upper_bound(a,a+n,4) - a;  Hence ind = 2
// upper_bound() returns an iterator which points to 5.

int ind = upper_bound(a,a+n,7) - a;  Hence ind = 4

int ind = upper_bound(a,a+n,10) - a;  Hence ind = 6

But note that 7 and 10 are not present in the a[].

For vectors:
int ind = upper_bound(a.begin(),a.end(),x) - a.begin();
*/

// binary_search(), lower_bound() & upper_bound() have T.C. = O(log n).

/*
Questions:

Q1. Find the first occurrence of a X in a sorted array.
If it does not exist, print -1.
Try for X = 4, 0, 12

A[] = {1, 4, 4, 4, 4, 9, 9, 10, 11}

int ind = lower_bound(a, a+n, X) - a;

if(ind != n && a[ind] == X) // ind != n takes care of the edge case because if ind = n, then a[ind] will give error
    cout << ind;
else
    cout << -1;


Q2. Find the last occurrence of a X in a sorted array.
If it does not exist, print -1.
Try for X = 4,2,0

A[] = {1, 4, 4, 4, 4, 9, 9, 10, 11}

int ind = upper_bound(a, a+n, X) - a;
ind--;

if(ind >= 0 && a[ind] == X) cout << ind; // ind >= 0 takes care of the edge case i.e. ind = -1
else cout << -1;

Q3. Find the largest number smaller than X in a sorted array.
If no number exists print -1.
Try for X = 4,2,1,0

A[] = {1, 4, 4, 4, 4, 9, 9, 10, 11}

int ind = lower_bound(a, a+n, X) - a;
ind--;

if(ind>=0) cout << a[ind];
else cout << -1;

Q4. Find the smallest number greater than X in a sorted array. 
If no number exists print -1.
Try for X = 4,2,1,11

A[] = {1, 4, 4, 4, 4, 9, 9, 10, 11}

int ind = upper_bound(a, a+n, X) - a;

if(ind<n) cout << a[ind];
else cout << -1;

*/