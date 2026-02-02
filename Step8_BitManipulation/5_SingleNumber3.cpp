#include<bits/stdc++.h>
using namespace std;

// Brute force solution: Using hashmap

// Better solution (My solution):

vector<int> singleNumber(vector<int> &nums){
    vector<int> ans;
    sort(nums.begin(), nums.end()); // O(n log n)
    int size = nums.size();
    int element = nums[0], count = 0;
    for(int i=0;i<size;i++){ // O(n)
        if(element == nums[i]) count++;
        else{
            if(count != 2) ans.push_back(element);
            element = nums[i];
            count = 1;
        }
    }
    if(count != 2) ans.push_back(element);
    return ans;

    // T.C. = O(n log n + n)
    // S.C. = O(2), just for returning the answer. 
}

// Optimal solution:

vector<int> singleNum(vector<int> &nums){
    int XOR = 0;
	for(int i=0;i<nums.size();i++) XOR ^= nums[i]; // O(n)
	int rightMostDiffBitSetNum = (XOR & (XOR-1)) ^ XOR;
	int xor1 = 0, xor2 = 0;
	for(int i=0;i<nums.size();i++){ // O(n)
		if(nums[i] & rightMostDiffBitSetNum) xor1 ^= nums[i];
		else xor2 ^= nums[i];
	}
	if(xor1 > xor2) return {xor2, xor1};
	else return {xor1, xor2};

    // T.C. = O(2n)
    // S.C. = O(1)
}