#include<bits/stdc++.h>
using namespace std;

// Brute force solution:
vector<int> moveZeroes(vector<int> a, int n){
    vector<int> temp;
    for(int i=0;i<n;i++)
    {
        if(a[i] != 0){
            temp.push_back(a[i]);
        }
    }

    int non_zero = temp.size();
    for(int i=0;i<non_zero;i++)
    {
        a[i] = temp[i];
    }

    for(int i=non_zero;i<n;i++)
    {
        a[i] = 0;
    }
    
    return a;
}

// T.C. = O(n+x+n-x) = O(2n) where x is the number of zeroes.
// S.C. = O(x)
// x can be n in the worst case. In that case S.C. = O(n)

// There is no better solution in this case.

// Optimal solution:
vector<int> moveZeroes1(vector<int> a, int n){
    int j = -1;
    for(int i = 0; i < n; i++){
        if (a[i] == 0){
            j = i; // position of first 0
            break;
        }
    }

    // no zeroes, i.e. if all are non-zero elements:
    if(j == -1) return a;

    for(int i=j+1;i<n;i++){
        if(a[i] != 0){
            swap(a[i],a[j]);
            j++; // j is always pointing at the first 0 in the present array(not the original array).
        }
    }

    return a;
}

// T.C. = O(x + n-x) = O(n) where x is the position where first 0 was found
// S.C. = O(1) because no extra space was used. 
// We will tell the interviewer that we modified the array that was given
// to us because that was required.

// My optimal code:
// Just used two-pointer approach but in a different way.

void moveZeroes(vector<int>& nums){
    int n = nums.size();
    int count = 0;
    for(int i=0;i<n;i++)
    {
        if(nums[i] == 0)
        count++;
    }
        
    int a = 0;
    for(int i=0;i<n;i++)
    {
        if(nums[i] != 0)    
        {
            nums[a] = nums[i];
            a++;
        }
    }
    for(int i=n-count;i<n;i++)
    {
        nums[i] = 0;
    }
}

// T.C. = O(n+n+x) where x is the number of zeroes in the given array.
// S.C. = O(1).
// So the previous optimal solution is slightly better than my one.

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
    //arr = moveZeroes(arr,size);
    //arr = moveZeroes1(arr,size);
    moveZeroes(arr);
    for(int i=0;i<size;i++) cout << arr[i] << " ";

    return 0;

}

