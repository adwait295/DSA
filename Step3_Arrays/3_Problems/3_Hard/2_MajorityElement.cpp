#include<bits/stdc++.h>
using namespace std;

// As the majority elements occur >n/3 times, there will be at max two majority elements.
// How? 
// n/3 divides the array into 3 equal halves. But if majority element takes more than one equal half,
// then there will not be enough space to keep the 3rd majority element so a 3rd majority element is 
// not possible.

// SO there can always be at max - 2 majority elements occuring >n/3 times in an array.

// Brute force solution:

vector<int> majorityElement1(vector<int> &nums){
    vector<int> ans;
    for(int i=0;i<nums.size();i++){ // O(n)
        if(ans.size() == 0 || ans[0] != nums[i]){
            int count = 0;
            for(int j=0;j<nums.size();j++){ // O(n)
                if(nums[j] == nums[i]) count++;
            }
            if(count > nums.size()/3) ans.push_back(nums[i]);
        }
        if(ans.size() == 2) break;
    }
    return ans;
}

// T.C. = O(n^2)
// S.C. = O(1) as the 'ans' vector is storing at max of 2 majority elements i.e. O(2) and we don't use any 
// extra space in our algorithm, just to store our answer and return it.

// Better solution:

// My solution:

vector<int> majorityElement2(vector<int>& nums) {
    vector<int> ans;
    unordered_map<int,int> mpp;

    int size = nums.size();

    int x = floor(size/3); // or just size/3 is sufficient obviously.

    for(int i=0;i<nums.size();i++){ // O(n)
        if(mpp.find(nums[i]) != mpp.end()) mpp[nums[i]]++;
        else mpp[nums[i]] = 1;
    }

    for(auto it: mpp){ // O(n) when all the elements in nums are unique
        if(it.second > x) ans.push_back(it.first);
    }

    return ans;
}

// T.C. = O(2n)
// S.C. = O(n) when all the elements in nums are unique and there are no majority elements.

// Striver's solution: better than my solution

vector<int> majorityElement3(vector<int> &nums){
    vector<int> ans;
    unordered_map<int,int> mpp; // O(1) for all operations, O(n) in a blue moon case.

    int minOccurence = nums.size() / 3 + 1;

    for(int i=0;i<nums.size();i++){ // O(n)
        mpp[nums[i]]++;
        if(mpp[nums[i]] == minOccurence) ans.push_back(nums[i]);

        if(ans.size() == 2) break;
    }
    sort(ans.begin(),ans.end()); // O(2 log 2) which is very less & as good as O(1) i.e. constant.
    // This statement is only written if it is asked in the question to return the 'ans' in the sorted order.
    return ans;
}

// T.C. = O(n)
// S.C. = O(n) when all the elements in the given array are unique and there are no majority elements.

// Optimal solution: Moore's voting algorithm (updated and modified)

vector<int> majorityElement(vector<int>& nums){
    int cnt1 = 0, cnt2 = 0;
    int el1 = INT_MIN, el2 = INT_MIN;

    for(int i=0;i<nums.size();i++){ // O(n)
        if(cnt1 == 0 && nums[i] != el2){
            cnt1 = 1;
            el1 = nums[i];
        }
        else if(cnt2 == 0 && nums[i] != el1){
            cnt2 = 1;
            el2 = nums[i];
        }
        else if(nums[i] == el1) cnt1++;
        else if(nums[i] == el2) cnt2++;
        else{
            cnt1--, cnt2--;
        }
    
    }
    vector<int> ans;

    // Manual check:
    cnt1 = 0, cnt2 = 0;
    int minOccurence = nums.size() / 3 + 1;
    for(int i=0;i<nums.size();i++){ // O(n)
        if(nums[i] == el1) cnt1++;
        if(nums[i] == el2) cnt2++;
    }
    if(cnt1 >= minOccurence) ans.push_back(el1);
    if(cnt2 >= minOccurence) ans.push_back(el2);

    return ans;
}

// T.C. = O(2n)
// S.C. = O(1), we are using 4 extra variables which is as good as constant. 