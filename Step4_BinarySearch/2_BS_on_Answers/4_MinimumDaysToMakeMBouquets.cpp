#include<bits/stdc++.h>
using namespace std;

/*
e.g. [7,7,7,7,13,11,12,7] m=2, k=3

if we take:
days = 7 -> Not Possible
days = 9 -> Not Possible
days = 11 -> Not Possible
days = 12 -> Possible
days = 13 -> Possible

So days from 1 to 11 -> Not possible
and days from 12 to any larger value -> Possible 

From 1 to 11, it is ❌❌❌❌. And from 12, it is ✅✅✅✅✅✅. From this pattern we can guess its BS.
Min value is 12, so 12 is our answer.

In these type of questions, where min/max is required and range is known, we can apply BS on answers.

The most important part is determining the range:

As anything below days=7, no flowers will bloom, so the days below 7 are useless to us. So low = 7.
As anything above days = 13, all flowers will bloom and return us the same answer as 13, so high = 13.

We know we decided low and high based on the obvious intuition that 7 is the smallest element of the array
and 13 is the largest.

So finally our range is also decided i.e. 7 to 13.


e.g. [1,10,3,10,2] m=3, k=2

As m*k = 6, i.e. number of flowers we require to make 3 bouquets of 2 flowers each = 6, 
but we only have 5 flowers in our garden -> so making the bouquets is impossible as:

m*k > size of array

so we return -1.
*/

// How do we approach this problem?
// Always remember, whenever we are solving a problem, the first approach should be HOW CAN I SOLVE THIS IN
// SOME WAY? Then after that, we can always think of optimizations.

int possible(vector<int>& arr, int NthDay, int m, int k){ // O(n)
    int count = 0, noOfBouquets = 0;
    for (int i = 0; i < arr.size(); i++){
        if (arr[i] <= NthDay) count++;
        else{
            noOfBouquets += count / k;
            count = 0;
        }
    }
    noOfBouquets += count / k; // useful when array is not ending with a non-bloomed flower:
    // e.g. = [2,3,4,1,1,2,6,3,2,3] NthDay = 4, k=3, m=3
    // after the loop, count will be 3 but noOfBouquets will be 2.
    // So we need to check the last set of bloomed flowers are checked or not.
    // By this statement, noOfBouquets becomes 3 which we require.

    if (noOfBouquets >= m)
        return 1;
    else
        return 0;
}

// Brute force solution

int minimumDays1(vector<int> &arr, int m, int k){
    int mini = *min_element(arr.begin(), arr.end()); // O(n)
    int maxi = *max_element(arr.begin(), arr.end()); // O(n)

    if(1LL * m * k > arr.size()) return -1;

    for(int i=mini;i<=maxi;i++){ // O(maxi - mini + 1)
        if(possible(arr,i,m,k) == 1) return i; // O(n)
    }
}

// T.C. = O(2n) + O((maxi-mini+1) * n)

// So it's very important to understand the brute force, because the moment we understand the brute force,
// it's super simple to optimize it.

// My optimal solution:

int minDays(vector<int>& bloomDay, int m, int k) {
    int low = INT_MAX, high = INT_MIN;
    for(int i=0;i<bloomDay.size();i++){ // O(n)
        if(bloomDay[i] < low) low = bloomDay[i];
        if(bloomDay[i] > high) high = bloomDay[i];
    }
    long long noOfTotalFlowersReqd = 1LL * m * k;
    if(noOfTotalFlowersReqd > bloomDay.size()) return -1; // edge case

    while(low <= high){ // O(maxi - mini + 1)
        int  mid = (0LL + low + high) / 2;
        if(possible(bloomDay, mid, m, k) == 1) high = mid - 1; // O(n)
        else low = mid + 1;
    }

    return low;
}

// T.C. = O(n) + O(log (maxi-mini+1) * n)

// Striver's optimal solution:

bool possible1(vector<int> &arr, int day, int m, int k) {
    int cnt = 0;
    int noOfB = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] <= day) {
            cnt++;
        }
        else {
            noOfB += (cnt / k);
            cnt = 0;
        }
    }
    noOfB += (cnt / k);
    return noOfB >= m;
}

int roseGarden(vector<int> &arr, int r, int b) {
    long long val = r * 1LL * b * 1LL;
    if(val > arr.size()) return -1;
    
    int mini = INT_MAX, maxi = INT_MIN;
    for(int i = 0; i < arr.size(); i++) { // O(n)
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }
    
    int low = mini, high = maxi;
    while(low <= high) { // O(maxi - mini + 1)
        int mid = (low + high) / 2;
        if(possible1(arr, mid, r, b)) { // O(n)
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

// T.C. = O(n) + O(log (maxi-mini+1) * n)
// S.C. = O(1)

/*
What the fuck is that 1LL and 0LL? 

0LL → integer literal 0 of type long long, used to safely promote additions into long long.

1LL → integer literal 1 of type long long, used to safely promote multiplications into long long.

In C++, the arithmetic (+, *, etc.) is done before assignment in the 'type' of the operands.

So if both operands are int, the operation happens in int (can overflow) even if the result is stored in
long long.

Using 0LL or 1LL forces at least one operand to be long long, so the entire operation is promoted to 
long long first, before assignment.

e.g. Overflow case:

int a = 2'000'000'000;
int b = 2'000'000'000;

// multiplication done in int → overflow
long long prod = a * b;     
// addition done in int → overflow
long long sum  = a + b;     


Now, safe promotion of above e.g. with 0LL and 1LL:

int a = 2'000'000'000;
int b = 2'000'000'000;

// 1LL promotes to long long → multiplication safe
long long prod = 1LL * a * b;  

// 0LL promotes to long long → addition safe
long long sum  = 0LL + a + b;  

a * b or a + b is evaluated before assignment, so if both are int, overflow happens.

1LL / 0LL ensures promotion to long long before the operation.
*/

/*
if we do not wish to use 0LL above in the binary search 'mid' calculation, we can use:

int mid = low + (high - low) / 2;   // ✅ safe, stays in int

*/
