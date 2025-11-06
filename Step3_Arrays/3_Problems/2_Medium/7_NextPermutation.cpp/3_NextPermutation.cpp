#include<bits/stdc++.h>
using namespace std;

/*
Brute force solution:
1. Generate all possible permutations in sorted order.
2. Linear search the given permutation. (if it is found at ith index)
3. Print the next permutation (i+1th index)
4. If i+1 = n then print i=0 i.e. the first permutation in the sorted order
*/

// T.C. = O(n factorial * n) which is of extremely high order and that's why we move to better & optimal soln.

/*
Remember whenever you are in an interview, never ever deep dive into a brute force solution. 
Always tell it from a very higher(overall) level, i.e. the overall steps you will do for the brute soln.

We should not start writing the code because that will end up wasting your time.

Once you have told the steps from a very higher level, tell the interviewer the time complexity 
the brute force solution will take.

Here, tell the T.C. is of very high order, so that is why I will try to optimize it. 
*/

// There does not exist a better solution but in C++, we can use the C++ STL to get the next permutation:

vector<int> nextGreaterPermutation(vector<int> &A){
    next_permutation(A.begin(),A.end());
    return A;
}

// It is highly recommended to say about this STL because the interviewer will get an idea that we have a 
// knowledge about STL as well.

// Now the interviewer will ask us, Can you please code that in-built next_permutation STL?
// We know there is an STL, but can you please implement it?

// Optimal solution:

vector<int> nextPermutation(vector<int> &a){
    int size = a.size();

    // Step 1: Find breakpoint.
    int breakpoint = -1;
    for(int i=size-2;i>=0;i--) // O(n)
    {
        if(a[i] < a[i+1]){
            breakpoint = i;
            break;
        }
    }

    // If breakpoint is still -1, that means it is completely in descending order 
    // i.e. it is the last permutation (edge case).
    if(breakpoint == -1){
        reverse(a.begin(),a.end());
        return a;
    }  

    // Step 2: Swap the breakpoint element with the just-greater element
    for(int i=size-1;i>breakpoint;i--) // O(n)
    {
        if(a[i] > a[breakpoint]){
            swap(a[breakpoint], a[i]);
            break;
        }
    }

    // Step 3: Make the right side as small as possible.
    reverse(a.begin() + breakpoint + 1, a.end()); // O(n)

    return a;
    
}

// T.C. = O(3n)
// S.C. = O(1), we are just modifying the given array and returning it.

// If the interviewer asks to include the modified original array in the extra space used, then S.C. = O(n).

int main(){
    int size;
    cin >> size;
    vector<int> arr;
    for(int i=1;i<=size;i++)
    {
        int n;
        cin >> n;
        arr.push_back(n);
    }

    vector<int> next_Permutation = nextPermutation(arr);

    for(auto it: next_Permutation)
    {
        cout << it << " ";
    }

    return 0;
}