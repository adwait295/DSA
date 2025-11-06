#include<bits/stdc++.h>
using namespace std;

// Brute force solution: Trying out all possible subarrays.

int subarr1(vector<int> &arr){
    int size = arr.size();
    int maxi = INT_MIN;
    for(int i=0;i<size;i++)
    {
        for(int j=i;j<size;j++)
        {
            int sum = 0;
            for(int k=i;k<=j;k++)
            {
                sum = sum + arr[k];
            }
            maxi = max(maxi, sum); 
        }
    }
    return maxi;
}

// T.C. = O(n^3), not exactly but close to. (near about)
// S.C. = O(1).

// Better solution: Observation of the pattern in brute force solution.

int subarr2(vector<int> &arr){
    int size = arr.size();
    int maxi = INT_MIN;
    for(int i=0;i<size;i++)
    {
        int sum = 0;
        for(int j=i;j<size;j++)
        {          
            sum = sum + arr[j];
            maxi = max(maxi, sum); 
        }
    }
    return maxi;
}

// T.C. = O(n^2), obviously not exactly but close to.
// S.C. = O(1).

// Optimal Solution: Kadane's Algorithm

vector<int> maxSubArray(vector<int>& nums){
    int size = nums.size();
    int maxi = INT_MIN; // If we take long long sum, then we take maxi = LONG_MIN.
    int sum = 0;
    int start = 0, ansStart = 0, ansEnd = 0; // used for printing the subarray with maximum sum
    for(int i=0;i<size;i++)
    {
        if(sum == 0) start = i;

        sum = sum + nums[i];
        if(sum > maxi){
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }

        if(sum < 0){ // Do not take any negatives into the future.  
            sum = 0;
        } 
    }
    if(maxi < 0){ 
        // In case we have the maximum subarray sum as -ve, we get to know that our array contains all negatives only.
        // So we return maxi = 0, with an empty subarray which is specified by {ansStart,ansEnd} = {-1,-1}
        maxi = 0;
        ansStart = -1;
        ansEnd = -1;

        // This condition is done if it is explicitly mentioned in the problem statement.
    }
    return {maxi,ansStart,ansEnd};
}

// T.C. = O(n)
// S.C. = O(1)

// Follow up: If there are multiple subarrays having the same sum as maxi, then how to display both maximum sum subarrays?

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
    vector<int> m = maxSubArray(arr);

    cout << "Maximum Sum: " << m[0] << endl;

    cout << "The index range of the maximum subarray is: [" << m[1] << ", " << m[2] << "]" << endl;

    cout << "And the subarray is: " << endl;

    if(m[1] == -1 && m[2] == -1){
        cout << "Empty subarray." << endl;
    }
    else{
        for(int i=m[1];i<=m[2];i++) cout << arr[i] << " " ;
    }
    
    return 0;
}