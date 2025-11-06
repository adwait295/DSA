#include<bits/stdc++.h>
using namespace std;

// Brute force : Linear Search :)

vector<int> Occurences(vector<int> &nums, int target){
    int first = -1, last = -1;
    for(int i=0;i<nums.size();i++){
        if(nums[i] == target){
            if(first == -1) first = i; // since the array is sorted, we won't have any problem writing this.
            last = i;
        }
    }
    return {first,last};

    // T.C. = O(n)
}
// What is better than O(n)? Yes it's O(log n) and as we know wherever the search space is sorted,
// we can use binary search to search for an element.

// My code:

int firstOccurence(vector<int> &nums, int target){

    if(nums.size() == 0) return -1;

    int lb = lower_bound(nums.begin(),nums.end(),target) - nums.begin();

    if(lb == nums.size() || nums[lb] != target) return -1;
    else return lb;
}

int lastOccurence(vector<int> &nums, int target){

    if(nums.size() == 0) return -1;

    int low = 0, high = nums.size() - 1;
    int answer = -1; // We can take answer = nums.size() as well here. It won't make a difference. 
    while(low <= high){
        int mid = (low + high) / 2;

        if(nums[mid] <= target){
            answer = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    if(answer != -1 && nums[answer] == target) return answer; 
    // If we take answer = nums.size() in the beginning, then we will check here if answer != nums.size()
    else return -1;
}

/*
Another way of finding last occurence:

int lastOccurence(vector<int> &nums, int target){

    if(nums.size() == 0) return -1;

    int ub = upper_bound(nums.begin(),nums.end(),target) - nums.begin();

    if(ub-1 == -1 || nums[ub-1] != target) return -1;
    else return ub - 1;
}
*/


vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> found = {-1,-1};

    found[0] = firstOccurence(nums,target);
    found[1] = lastOccurence(nums,target);

    return found;
}

// Striver's code:

int lowerBound(vector<int> arr, int target, int size){
    int low = 0, high = size - 1;
    int answer = size;

    while(low <= high){
        int mid = (low + high) / 2;

        if(arr[mid] >= target){ // maybe an answer
            answer = mid; 
            high = mid - 1; // look for smaller index on the left as we have to find the smallest.
        }
        else low = mid + 1; // look for right
    }
    return answer;
}

int upperBound(vector<int> arr, int target, int size){
    int low = 0, high = size - 1;
    int answer = size;

    while(low <= high){
        int mid = (low + high) / 2;

        if(arr[mid] > target){ // maybe an answer
            answer = mid;
            high = mid - 1; // look for smaller index on the left
        }
        else low = mid + 1; // look for right
    }
    return answer;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k) {
    int lb = lowerBound(arr, n, k);
    if(lb == n || arr[lb] != k) return {-1, -1}; // edge-case
    return {lb, upperBound(arr, n, k) - 1};
}

// T.C. = O(log n) + O(log n) 
// S.C. = O(1)


/*
But a lot of times, the interviewer might ask us that: Hey I don't want you to use some lowerBound or
upperBound concepts. Please write a simple binary search that does it for me. I don't want you to go through
the lower_bound() & upper_bound().

A lot of interviewers might have no problem with our approach as well. It all depends on the interviewer.
*/

// So we will be writing a binary search from scratch. Obviously in a single binary search, we cannot find 
// the first and last occurence together. So we will write a binary search for each of them accordingly:

int firstOccurrence1(vector<int> &arr, int n, int k) {
    int low = 0, high = n - 1;
    int first = -1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] == k) {
            first = mid;
            high = mid - 1;
        }
        else if(arr[mid] < k) low = mid + 1;
        else high = mid - 1;
    }
    return first;
}

int lastOccurrence1(vector<int> &arr, int n, int k) {
    int low = 0, high = n - 1;
    int last = -1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] == k) {
            last = mid;
            low = mid + 1;
        }
        else if(arr[mid] < k) low = mid + 1;
        else high = mid - 1;
    }
    return last;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k) {
    int first = firstOccurrence1(arr, n, k);
    if(first == -1) return {-1, -1}; // This one line can save us an unnecessary O(log n) extra T.C. 
    int last = lastOccurrence1(arr, n, k);
    return {first, last};
}


/*
Always check for the firstOccurence first. Don't call both firstOccurence() and lastOccurence() blindly.
Because if there isn't a first occurence, there will never be a last occurence. So save the extra O(log n)
time complexity in that case.

These minor things might help us in an interview because it shows our awareness as to how and when
can we find even a slightest of chance to keep the time less. 
*/
