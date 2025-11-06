#include <bits/stdc++.h>
using namespace std;

// For the brute and better version of brute, check Q14 of easy section.

// Optimal solution: 

int findAllSubarraysWithGivenSum(vector<int> &arr, int k) {
    map<int, int> mpp;
    mpp[0] = 1; // O(log n)
    int preSum = 0, cnt = 0;

    for (int i = 0; i < arr.size(); i++) { // O(n)
        preSum += arr[i];
        int remove = preSum - k;
        cnt += mpp[remove]; // O(log n)
        mpp[preSum] += 1; // O(log n)
    }

    return cnt;
}

// T.C. = O(n log n) when we use maps. O(n) in the best/avg cases and O(n^2) in worst if we use unordered maps.
// S.C. = O(n) because in the worst case, there can be n different prefix sums stored inside the hashmap.

int main() {
    vector<int> arr = {1,2,3,-3,1,1,1,4,2,-3};
    int k = 3;

    cout << findAllSubarraysWithGivenSum(arr, k) << endl;
    return 0;
}


/*


e.g. 1: The code I have written from Striver.

cnt = mpp[remove];   // direct access
mpp[preSum] += 1;

Uses operator[] directly.

Problem: if remove does not exist, mpp[remove] inserts it with value 0.

That means your map will contain a lot of "unnecessary" keys (all missing preSum - k values you ever queried).

Time complexity is still O(n log n), but space complexity can blow up a bit.




e.g. 2: The code I have written in Leetcode.

if(preSumMap.find(preSum-k) != preSumMap.end()){
    count += preSumMap[preSum-k];
}
First uses find() → checks if the key exists.

Only if it exists, it accesses with operator[].

Advantage: does not insert unnecessary keys.

Space usage is tighter (only stores actually-seen prefix sums).




✅ Which is better?
LeetCode version is better in practice because:

Less unnecessary memory usage.

Cleaner map (only relevant prefix sums are stored).

Striver's version still works (accepted solution), just may store extra keys that never got used.
*/