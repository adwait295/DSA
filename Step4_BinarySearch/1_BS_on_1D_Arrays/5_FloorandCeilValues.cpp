#include<bits/stdc++.h>
using namespace std;

int floor(vector<int> &nums, int target){
    if (nums.size() == 0) return -1;

    int low = 0, high = nums.size() - 1;
    int answer = -1;
    while (low <= high){
        int mid = (low + high) / 2;

        if (nums[mid] <= target){
            answer = mid;
            low = mid + 1;
        } else high = mid - 1;
    }
    if(answer != -1) return nums[answer];
    return -1;
}

int ceil(vector<int> &nums, int target){
    if (nums.size() == 0) return -1;

    int low = 0, high = nums.size() - 1;
    int answer = nums.size();
    while (low <= high) {
        int mid = (low + high) / 2;

        if (nums[mid] >= target) {
            answer = mid;
            high = mid - 1;
        } 
        else low = mid + 1;
    }
    if(answer != nums.size()) return nums[answer];
    return -1;
}

vector<int> getFloorAndCeil(vector<int> nums, int x) {
    vector<int> ans;
    ans.push_back(floor(nums,x));
    ans.push_back(ceil(nums,x));

    return ans;
}


/*
A thing notable to be a doubt is: How is binary search able to get the smallest or the largest?

It does this by continuously eliminating sides and shrinking the search space. 

If we are trying to find the smallest, it keeps on eliminating the right side values from the search space until it finds the 
smallest. In that case, we keep on going towards left as the algorithm knows - if we have to find the smallest,
we need to go and check towards left and search for a value smaller than the present smallest value. 
So at every step, it keeps on eliminating the larger values i.e. the right side values.

Similarly if we are trying to find the largest, we keep on going towards right, eliminating the left values 
from the search space as we know, if there is a possibility of finding a larger value than the present largest 
value, it is surely on the right side, not the left side.

That's how binary search does it.
*/

// The key to master binary search is by taking a LOT of examples. A Lot of LONG examples, and doing dry runs.

// When we become expert at BS, we will notice that we don't need the 'answer' variable to store our answer;
// Either the 'low' or the 'high' index will be pointing to our answer. We will notice this when we become
// better and better. For now, we can take a 'answer' variable to store the answer.

// We can take examples and see: When we run out of search space, low or high, one of them will be pointing
// to our answer. Just have a notice at this.