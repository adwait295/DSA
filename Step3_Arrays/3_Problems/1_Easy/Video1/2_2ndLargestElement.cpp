#include<bits/stdc++.h>
using namespace std;

/*
Brute Force approach:
1. Sorting the array first: O(n log n)
2. The second last element may not be the second largest in case it is equal to the 
   largest. e.g. a[] = {1,2,5,5,6,7,7,7}. So:
   for(int i=n-2;i>=0;i--)  --------------------O(n)
   {
        if(arr[i] != arr[n-1]){
        second_largest = arr[i];
        break;
        }
        second_largest = -1; // Edge case - When there is no second largest i.e. a[] = {7,7,7,7,7}
   }

So the total T.C. of Brute force approach is O(n log n + n).   
*/

// Better Solution: O(2n) approach
int better_solution(int arr[], int n){
    int largest = arr[0];
    for(int i=0;i<n;i++) // O(n)
    {
        if(arr[i] > largest)
        largest = arr[i];
    }

    int second_largest = -1; // If all the elements of the array are positive
    // If there are negative elements too, then we take second_largest = INT_MIN
    for(int i=0;i<n;i++) // O(n)
    {
        if(arr[i] > second_largest && arr[i] != largest)
        second_largest = arr[i];
    }

    return second_largest;

    // Total T.C. = O(2n) = O(n)
    // We know that the T.C. is O(n) but we should not tell this in an interview.
    // We should say that the first pass takes O(n) & the second pass takes O(n).
    // So the algorithm is running two passes. O(n+n) = O(2n),
    // getting largest in the first pass and second largest in the second pass.
    // So this is O(2n) approach.
}

int second_largest_optimal(int arr[], int n){
    int largest = arr[0];
    int slargest = -1; // All elements are non-negative.
    // As it has been mentioned in the Question that the given array has 'N' unique
    // non-negative integers and minimum length of array is 2, so we will surely find the largest and the second largest.
    for(int i=0;i<n;i++)
    {
        if(arr[i] > largest){
            slargest = largest; // the previous largest goes to the slargest
            largest = arr[i]; // then the largest is updated.
        }
        else if(arr[i] < largest && arr[i] > slargest){
            slargest = arr[i]; 
            // In case we have found the largest but not the second largest.
        }
    }
    return slargest;

    // Time complexity:
    // It takes only one pass and T.C. = O(n).
}

int second_smallest_optimal(int arr[], int n){
    int smallest = arr[0];
    int ssmallest = INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(arr[i] < smallest){
            ssmallest = smallest;
            smallest = arr[i];
        }
        else if(arr[i] != smallest && arr[i] < ssmallest)
        ssmallest = arr[i];
    }
    return ssmallest;

    // Time complexity:
    // It takes only one pass and T.C. = O(n).
}

int main(){
    int size;
    cin >> size;
    int arr[size];

    for(int i=0;i<size;i++)
    {
        cin >> arr[i];
    }

    cout << "2nd Largest: " << second_largest_optimal(arr,size) << endl;
    cout << "2nd Smallest: " << second_smallest_optimal(arr,size) << endl;

    return 0;
}

// The better solution has T.C. = O(2n)
// The optimal solution has T.C. = O(n)

// So the optimal solution is the best solution.