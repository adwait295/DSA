#include<bits/stdc++.h>
using namespace std;

// Brute force solution is always the extreme naive solution:

vector<int> leader0(vector<int> &nums){
    vector<int> leader;
    int size = nums.size();
    for(int i=0;i<size;i++)
    {
        bool lead = true;
        for(int j=i+1;j<size;j++)
        {
            if(nums[j] > nums[i]){
                lead = false;
                break;
            }
        }
        if(lead == true) leader.push_back(nums[i]);
    }
    return leader;
}

// T.C. = O(n^2), not exactly but close to.
// S.C. : We are not using any extra space for solving the problem, we are just using a vector 'leader' to 
// store the answer. If the interviewer says that the answer is counted as extra space, then:
// S.C. = O(leader.size()) which is O(n), as in the worst case, the entire array is in descending order.
// otherwise S.C. = O(1).

// We do not have a better solution, so we move to the optimal solution.

// Optimal solution, my Solution:

vector<int> leaders(vector<int>& nums){
    vector<int> leader;
    int size = nums.size();
    int max = nums[size-1];
    leader.push_back(max);
    for(int i=size-2;i>=0;i--) // O(n)
    {
        if(nums[i] > max){
        max = nums[i];
        leader.push_back(max);
        }
    }
    reverse(leader.begin(),leader.end()); // O(n)
    // If the leaders are asked in a sorted order, we can do sort(leader.begin(),leader.end()); // O(n log n)
    return leader;
}

// S.C. = O(n) just for storing the answer. Worst case is when the given array is in descending order.

int main(){
    int size;
    cin >> size;
    vector<int> a(size,0);
    for(int i=0;i<size;i++) cin >> a[i];

    vector<int> answer = leaders(a);

    int size1 = answer.size();

    for(int i=0;i<size1;i++) cout << answer[i] << " ";

    return 0;
}