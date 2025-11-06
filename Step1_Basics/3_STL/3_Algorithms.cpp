#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,int> p1, pair<int,int> p2){ // two adjacent elements of the array are passed
    // Forget about the main array and now just think of two elements at a time.
    // pair p1 lies before pair p2 in the array
    if(p1.second < p2.second){ // already sorted
        return true; // they are in the correct order
    }
    else if (p1.second == p2.second){
        if(p1.second > p2.second) return true;
    }
    return false; // they are not in the correct order
    // so by returning false, it says to swap them


    /*
    Can also be written as:
    if(p1.second < p2.second) return true;
    if(p1.second > p2.second) return false;

    if(p1.first > p2.first) return true;
    return false

    // This can be written as a function executes only one return statement
    */

   // Always analyse everything in terms of two elements of the array and write the comparator
   // Don't think about the entire array

}

void learnAlgo(){
    
    // To sort an array of size n
    int n; int a[n]; 
    // {1,5,3,2}
    sort(a,a+n); // a is the first iterator i.e. begin() iterator and a+n is the end() iterator. [start,end)
    // {1,2,3,5}

    // To sort a vector:
    vector<int> v;
    sort(v.begin(),v.end());

    // So to sort arrays and vectors, we need not write lines of code for bubble/selection/insertion/merge/any sort
    // We directly use sort()

    // Sorting only the part which we want to:
    // {1,3,5,2}
    sort(a+2,a+4); // {1,3,2,5} - the last two elements are sorted

    // To sort in descending order:
    sort(a,a+n,greater<int>());
    // greater<int>() is an in-built comparator 

    // To sort in our own customizable ways we want to,
    // we write our own comparators
    
    // For e.g.:
    pair<int,int> a[] = {{1,2},{2,1},{4,1}};
    // I want to sort it according to increasing second element 
    // If second element is same, 
    // sort it according to the first element, but in descending
    sort(a,a+n,comp); // comp is a self-written comparator
    // comparator is nothing but a boolean function
    // {{4,1},{2,1},{1,2}}

    int num = 7; // 111
    int cnt = __builtin_popcount(num); 
    // count the number of '1' bits i.e. number of set bits in the 32 bit integer
    // cnt = 3 here
    // if num = 6, then cnt = 2 as 6 is 110

    // For long long integers:
    long long num = 165786578687;
    int cnt = __builtin_popcountll(num);

    // To print all the next permutations (dictionary-wise) of a string:
    string s = "123";

    // if s = "213" then the next permutations will be 231, 312, 321
    // the do-while loop below will print 213, 231, 312, 321 only
    // so if we want to print all the permutations of a string, we need to keep it in sorted ascending order (dictionary-wise)
    // To do that, we can obviously use :
    sort(s.begin(), s.end()); // so whatever order s is , it becomes "123" after this statement

    do{
        cout << s << endl;
        // s = 123, 132, 213, 231, 312, 321 in order one after another
        // after 321, the value of s becomes null i.e. no more permutations hence returns a false
    }while(next_permutation(s.begin(),s.end()));

    // To find the maximum element in an array:
    int max = *max_element(a,a+n); // (start iterator, end iterator)
    // max_element gives the address of the largest element 
    // similarly we can use min_element()   
}

int main(){
    return 0;
}