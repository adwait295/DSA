#include<bits/stdc++.h>
using namespace std;

// Brute force solution: Sorting

/*
Merge sort:
T.C. = O(n log n) 
S.C. = O(n) for the temp array in merge sort. 
*/

// Obviously the interviewer won't be happy with the T.C. and S.C. and will ask us to 
// optimize it. 

// Better solution: My code:

void sortColors(vector<int>& nums) {
    int size = nums.size();
    int num0 = 0, num1 = 0, num2 = 0;
    for(int i=0;i<size;i++) // O(n)
    {
        if(nums[i] == 0) num0++;
        else if(nums[i] == 1) num1++;
        else num2++;
    }

    num1 = num0 + num1;
    num2 = num1 + num2;

    for(int i=0;i<num0;i++) nums[i] = 0; 
    for(int i=num0;i<num1;i++) nums[i] = 1;
    for(int i=num1;i<num2;i++) nums[i] = 2;

    // In total, the above 3 loops will take O(n) together.   
}

// T.C. = O(2n)
// S.C. = O(1)

// If the interviewer still says that he does not need O(2n), then we do:
// Optimal approach: DUTCH NATIONAL FLAG ALGORITHM 

void sortArray(vector<int>& arr, int n)
{
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high) { // O(n)
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]); // O(1)
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

// T.C. = O(n)
// S.C. = O(1)

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

    sortArray(arr,size);

    for(int i=0;i<size;i++) cout << arr[i] << " " ;

    return 0;
}