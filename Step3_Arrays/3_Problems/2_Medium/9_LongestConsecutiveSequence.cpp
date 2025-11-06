#include<bits/stdc++.h>
using namespace std;

// Brute force solution:

bool linearSearch(vector<int> a, int element){
    for(int i=0;i<a.size();i++) // O(n)
    {
        if(a[i] == element) return true;
    }
    return false;

    // T.C. = O(n) for every linear search
}

int sequence0(vector<int> &a){
    int size = a.size();
    int maxCount = 1;
    for(int i=0;i<size;i++) // O(n)
    {
        int x = a[i];
        int count = 1;
        while(linearSearch(a,x+1) == true){ // O(n). It can be O(2n), O(3n), O(4n)... depending upon how many linear 
        // searches take place for one element.
        // For e.g. [1,2,3,4,5,6] will have O(5n),O(4n),O(3n),O(2n),O(n),O(0) for 1,2,3,4,5,6  respectively.
            x++;
            count++;
            // To check how many times the loop is running along with value of count at each step:
            // cout << count << " ";  
            // cout << "Yes" << endl;
        }
        maxCount = max(maxCount,count);
    }
    return maxCount;
}

/*
T.C. is O(n^2), not exactly but greater than it.
For e.g. if a = [1,2,3,4], then the 'x++' statement runs for total of 3n + 2n + n + 0 times = 6n times.
In this e.g. n = 4 , therefore 6n = 24, but n^2 is 16. But we cannot say it is n^3 as n^3 = 64 and that
is not the case here.
e.g. a = [1,2,3,4,5,6] then T.C. = O(15n) = O(90) but n^2 = 36 and n^3 = 216.

Usually for O(n^2), it should be like O(6n) when n=6, O(4n) when n=4, etc. But here it is exceeding that.
But we cannot say it n^3, because the answer is not close to it. So we take it as O(n^2).
*/ 
// S.C. = O(1)

// Better solution: Sorting

int longestSuccessiveElements(vector<int>& nums) {
    if (nums.size() == 0) return 0; // Edge case

    sort(nums.begin(), nums.end()); // O(n log n)
    int n = nums.size();
    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1;

    for (int i = 0; i < n; i++) { // O(n)
        if(nums[i] == lastSmaller) continue;
        else if (nums[i] - 1 == lastSmaller) {
            cnt += 1;
            lastSmaller = nums[i];
        }
        else{
            cnt = 1;
            lastSmaller = nums[i];
        }
        longest = max(longest, cnt);
    }
    return longest;
}

// T.C. = O(n log n + n)
// S.C. = O(1)

// The interviewer might not like that we are distorting the original array by sorting it. 
// So he can ask to not do that, or get rid of the n log n stuff. So we move to the optimal solution

// Optimal solution: We use an unordered set. Sets only store unique elements.

// Solution instinct: “Only start counting if there’s no number right before me.”

int longestSuccessiveElements1(vector<int> &a){
    int n = a.size();
    if (n == 0) return 0; // edge case

    int longest = 1;
    unordered_set<int> st; // Assuming there are no collisions.

    for (int i = 0; i < n; i++) { // O(n)
        st.insert(a[i]); // O(1) 
    }
    // find(), insert() take O(1) in the best/average cases and O(n) in the worst case.

    for (auto it : st) { // O(n)
        if (st.find(it - 1) == st.end()) { // we go inside only when 'it' is starting point of a sequence.
            int cnt = 1;
            int x = it;

            while (st.find(x + 1) != st.end()) { // O(n)
                x = x + 1;
                cnt++;
            }

            longest = max(longest, cnt);
        }
    }
    return longest;
}

/*
T.C. = O(n) (for insertion) + O(2n) = O(3n), not exactly but close to.
This is a very good example to analyse and go into deep understanding level of time complexity.
Analyse why it is O(2n) and not O(n^2)? Very interesting.

Lets take an e.g. = [102,100,3,101,1,2,0]

102 visited once -> only outer for loop = 1
100 visited once for outer for loop and inner while loop runs 2 times as it is first element of the sequence {100,101,102}. So 1+2=3
3 visited once -> only outer for loop = 1
101 visited once -> only outer for loop = 1
1 visited once -> only outer for loop = 1
2 visited once -> only outer for loop = 1
0 visited once for outer for loop and inner while loop runs 3 times for sequence {0,1,2,3} = 1+3=4

So total iterations = 1+3+1+1+1+1+4 = 12. close to 7 but a little greater, closer to 14
but very less than 7^2=49.

In the worst case, it will still remain less than 2n but close to it. 

So it is O(2n) because of the if condition inside for loop.
*/

// S.C. = O(n)
// If the set takes O(n), then the T.C. = O(n^2) for this solution and hence
// the brute solution is better than this because it has O(1) S.C. 


// My solution:

int sequence(vector<int> &a){
    int size = a.size();
    // unordered_map<int,int> mpp; - gives wrong answer because the data structure has to be sorted for my 
    // algorithm to work.
    map<int,int> mpp;

    int maxi = INT_MIN, mini = INT_MAX;

    for(int i=0;i<size;i++){ // O(n)
        mpp[a[i]]++; // O(log n)
        maxi = max(maxi,a[i]);
        mini = min(mini,a[i]);
    }

    if(size == 0) return 0;
    
    int maxCount = 1, count = 1;
    for(auto it: mpp) // O(n)
    {
        if(mpp.find(it.first) != mpp.end() && mpp.find((it).first + 1) != mpp.end()) { // O(log n + log n)
            count++;
            maxCount = max(maxCount,count);
        }
        else count = 1;
    }

    return maxCount;
}

// T.C. = O(n log n + 2n log n) = O(3n log n)
// S.C. = O(n)

int main(){
    int size;
    cin >> size;
    vector<int> a(size,0);
    for(int i=0;i<size;i++) cin >> a[i];

    cout << "Longest Consecutive Sequence length: " << sequence(a) << "\n";

    return 0;
}