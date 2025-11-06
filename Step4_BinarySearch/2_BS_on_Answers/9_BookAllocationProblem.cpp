#include<bits/stdc++.h>
using namespace std;

// This is an extremely hard question when it comes to binary search.

// Allocate the books to 'm' students such that the maximum number of pages assigned to any student is the
// minimum.

/*
Conditions to keep in mind:

1. Each student gets atleast one book.
2. Each book should be allocated to only one student.
3. Book allocation should be in a contiguous manner.
*/

// When to return -1? When is it not possible to allocate n books to m students?
// Obviously when the number of students is greater than the number of books, i.e. m > size of array.
// Because each of the students will be unable to get atleast one book.

// How do we solve this?
// We know that whenever we have a question like this (max)min or (min)max, binary search will be applied.
// But we won't go directly to binary search.

// Brute force solution:

// Deciding the range:

// We will start from 1 and go on till we find the first value which can be a maximum in a particular 
// arrangement in the allocation of books. The first value we get will be our answer because that is the
// lowest.

// start: What can be "in the worst case" - our minimum possible maximum?
// i.e. when every student is allocated only one book (m=n), what can be the maximum?
// i.e. the maximum element of the array is the minimum possible maximum, and it happens when m=n.

// Because, do we need to start from 1 and go on? No. Why? 
// Because to allocate all the n books, our maximum must start from the maxElement of the array.
// e.g. [25,46,28,49,24], m=4 our maximum must start from 49 obviously, because if we take maximum = 28 in a
// particular arrangement, then the books with pages 48 and 49 cannot be allocated which is the violation of
// required conditions. So our starting point of check should be from maximum = 49 here so that all the 
// books can be allocated.

// But when we take maximum = 49, number of students come out to be 5 which is >m, so it isn't possible.
// So we check maximum = 50 and so on.
// The moment we get number of students = 4, we get our (max)min.

// end: What can be "in the worst case" - our maximum possible maximum?
// i.e. when all the books are allocated to only one student (m=1), what can be the maximum?
// i.e. the sum of all pages of all books is the maximum possible maximum, and it happens when m=1.

// So our range is [max element, sum of all element] in the pages[].

/*
So always think in this way. Take cases, dry run them, find answers, analyse the pattern & try to find the 
range from the patterns. There will always be a pattern so that we can figure out the range. Even when it's
difficult to find it, I am sure I will find a way.
*/

int count(vector<int> &arr, int maxPages){ // O(n)
    int studentCount = 1, pagesCount = 0;
    for(int i=0;i<arr.size();i++){
        if(pagesCount + arr[i] <= maxPages) pagesCount += arr[i]; // given to the present student
        else{
            studentCount++;
            pagesCount = arr[i]; // given to the next student
        }
    }
    return studentCount;
}

int brute(vector<int> &arr, int m){
    int lowestMax = *max_element(arr.begin(),arr.end()); // O(n)
    int highestMax = accumulate(arr.begin(),arr.end(),0); // O(n)

    for(int maxPages = lowestMax; maxPages <= highestMax; maxPages++){ // O(sum - max + 1)
        int studentCount = count(arr,maxPages); // O(n)
        if(studentCount == m) return maxPages;
    }
    return -1; // dummy condition.
}

// T.C. = O(2n) + O(sum-max+1)*O(n).

// Obviously the interviewer won't be happy with this and ask us to optimize it.
// This is when we will move to our fav: Binary Search!

// Why do we think of BS? 
// The first reason is that Linear Search did not make the interviewer happy. So it didn't work out.
// The second and the best obvious reason is (max)min or (min)max.

// Optimal solution: Binary Search

int optimal(vector<int> &arr, int m){
    if(m > arr.size()) return -1;

    int lowestMax = *max_element(arr.begin(),arr.end()); // O(n)
    int highestMax = accumulate(arr.begin(),arr.end(),0); // O(n)

    while(lowestMax <= highestMax){
        int mid = (lowestMax + highestMax) / 2;
        int studentCount = count(arr,mid);
        if(studentCount > m) lowestMax = mid + 1; // When studentCount > m, it is ❌❌❌.
        else highestMax = mid - 1; // When studenCount <= m it is ✅✅✅✅.
    }
    return lowestMax; // opposite polarity.
}

// T.C. = O(2n) + O(log (sum-max+1)) * O(n).
// S.C. = O(1).