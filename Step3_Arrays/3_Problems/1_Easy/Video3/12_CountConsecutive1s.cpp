#include<bits/stdc++.h>
using namespace std;

// As the optimal solution is pretty straightforward, we skip directly to the optimal solution

int maxConsecutiveOnes(vector<int> &nums){
    int maxi = 0;
    int count = 0;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i] == 1){
            count++;
            maxi = max(maxi, count);
        }
        else count = 0;
    }
    return maxi;
}

// T.C. = O(n)
// S.C. = O(1)

int main(){
    int size;
    cin >> size;
    vector<int> nums;
    for(int i=1;i<=size;i++)
    {
        int n;
        cin >> n;
        nums.push_back(n);
    }

    cout << "Maximum Consecutive Ones: " << maxConsecutiveOnes(nums) << endl;

    return 0;
}