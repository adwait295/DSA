#include<bits/stdc++.h>
using namespace std;

// We have to return only the unique triplets. Our solution set must not contain duplicate triplets.
// In order to avoid duplicate triplets, we will sort them and store in the 'set' data structure
// which will store only unique triplets obviously.

// Brute force solution: Extreme naive solution - Generating all the triplets. 

vector<vector<int>> insert(vector<int> &nums, int n){
    set<vector<int>> st;
    for(int i=0;i<n;i++){ // O(n)
        for(int j=i+1;j<n;j++){ // O(n)
            for(int k=j+1;k<n;k++){ // O(n)
                if(nums[i] + nums[j] + nums[k] == 0){
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end()); // O(3 log 3) which is as good as constant.
                    st.insert(temp); // O(log m) where m is the number of elements present in the set. 
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end()); // 'ans' vector will store everything from the set's 
    // starting point to the set's ending point. 
    return ans;
}

// T.C. = O(n^3) * O(log (number of unique triplets))
// We can use the unordered_set to avoid the O(log m) during insertion. 
// S.C. = 2 * O(number of unique triplets) - one for the set<vector<int>> and another for the vector<vector<int>>.

// Better solution: 

// What is better than n^3? We can try making it n^2. How? By getting rid of the third loop. 
// And that is where the thought process starts for the better solution.

vector<vector<int>> insert1(vector<int> &nums, int n){
    set<vector<int>> st;

    for(int i=0;i<n;i++){
        set<int> hashset;
        for(int j=i+1;j<n;j++){
            int third = -(nums[i] + nums[j]);
            if(hashset.find(third) != hashset.end()){
                vector<int> temp = {nums[i], nums[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(nums[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans; 
}

/* T.C. :

O(n^2) * [2*O(log m) + O(log k)], where 
n is number of elements in the given array. 
m is the number of elements in the hashset at the time of finding (O(log m)) or insertion (O(log m)). 
k is the number of unique triplets in the st during insertion.

But in tight bound form, 
since m <= n, and k <= n^3, the worst case time complexity is:
O(n^2. (2*log n + log n^3)) = O(n^2 5*log n) = O(n^2 log n)

so yes, my detailed breakdown is correct but usually simplified to O(n^2 log n) in the worst case.

// To find the tight bound form:

General rule of thumb:

1. Express runtime in terms of all parameters.
2. Bound each parameter (𝑚,𝑘) in terms of the input size 𝑛
3.Replace constants and simplify to the dominant term.

i.e. we just had to find the maximum values (worst-case bounds) that m and k could reach. 

*/

// S.C. = O(n) (for hashset) + 2*(O(number of unique triplets)) (one for the 'st' and other for the 'ans').

// This external data structure 'st' is something the interviewer might not like. He might be okay with
// the time complexity because n^2 is somewhere he might have expected and we have got it nearly but he
// might ask us to get rid of the external data structure and this is where the optimal soln comes in.

// Optimal solution: Straight-forward two-pointer approach

vector<vector<int>> triplet3(vector<int> &nums, int n){
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end()); // O(n log n)
    for(int i=0;i<n;i++){ // O(n)
        if(i != 0 && nums[i] == nums[i-1]) continue;

        int j = i + 1;
        int k = n - 1;
        while(j < k){ // O(n)
            int sum = nums[i] + nums[j] + nums[k];
            if(sum < 0){
                j++;
                while(j < k && nums[j-1] == nums[j]) j++;
            }
            else if (sum > 0){
                k--;
                while(k > j && nums[k+1] == nums[k]) k--;
            }
            else{
                vector<int> temp = {nums[i], nums[j], nums[k]};
                ans.push_back(temp);
                j++, k--;
                while(j < k && nums[j-1] == nums[j]) j++;
                while(k > j && nums[k+1] == nums[k]) k--;  
            }
        }
    }
}

// T.C. = O(n^2) + O(n log n):

// The while loop together with all the inner while loops - they all work together to traverse all the values
// from i+1 to n-1, and hence the outer while loop has resultant total time complexity as O(n).

// S.C. = O(number of unique triplets) to return the answer. 
// 'temp' vector uses just O(3) S.C. i.e. constant, so we do not count that. 