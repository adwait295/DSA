#include <bits/stdc++.h>
using namespace std;

// Brute force solution:

long double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size();
    vector<int> howMany(n - 1, 0);

    for (int gasStations = 1; gasStations <= k; gasStations++) { // O(k)
        long double maxSection = -1;
        int maxInd = -1; 

        // Whichever section has the maximum sectionLength, we insert an element in that section
        // to decrease the sectionLength:
        // number of subsections = number of elements in that section + 1.
        // sectionLength = diff / number of subsections.

        for (int i = 0; i < n - 1; i++) { // O(n)
            long double diff = arr[i + 1] - arr[i];
            long double sectionLength = diff / (long double)(howMany[i] + 1);
            // Without type casting, we will get the wrong answer.
            if (sectionLength > maxSection) {
                maxSection = sectionLength;
                maxInd = i;
            }
        }

        howMany[maxInd]++;
    }

    // So everytime we insert an element, we always try to decrease the maximum sectionLength at that point
    // of time till we run out of number of elements provided for insertion.

    // Finally after inserting all the k elements, we find out the maximum sectionLength, 
    // which is now the minimum of all the maximum values possible:

    long double maxAns = -1;
    for (int i = 0; i < n - 1; i++) { // O(n)
        long double diff = arr[i + 1] - arr[i];
        long double sectionLength = diff / (long double)(howMany[i] + 1);
        maxAns = max(maxAns, sectionLength);
    }

    return maxAns;

    // T.C. = O(n*k + n) which will give us TLE because we can see that it is quadratic T.C.
    // because of n*k which is quadratic in nature.
}

int main() {
    vector<int> arr = {1, 13, 17, 23};
    int k = 5;
    cout << fixed << setprecision(6) << minimiseMaxDistance(arr, k) << endl;
    return 0;
}

// ChatGPT has used fixed and setprecision(6) to keep it till 6 decimal places. Why?

/*
When we write "cout << value;" :

by default, 'cout' may:

Print in default precision (6 digits total, not necessarily after decimal).

Switch to scientific notation if numbers are too large/small.

Sometimes give output like 0.5 or 0.500000, depending on the compiler/runtime.
*/

/*
When you write:

cout << fixed;


It forces output in fixed-point notation, meaning:

No scientific notation.

The number of digits shown after the decimal point is controlled only by setprecision().

e.g.

double x = 123.456789;
cout << fixed << x;
→ Output: 123.456789 (full precision, until you limit with setprecision).
*/

/*
setprecision(n)

This controls how many digits after the decimal point to print (when used with fixed).

Example:

double x = 123.456789;
cout << fixed << setprecision(2) << x;


→ Output: 123.46 (rounded to 2 decimal places).
*/

/*
Without fixed, setprecision(n) controls total number of significant digits (which can be confusing).

Why ChatGPT added fixed << setprecision(6) in your code?

Because our function returns a long double (fractional value), and the problem statement cares about precision (e.g., output 0.500000 instead of just 0.5).
It ensures you always print the result with 6 digits after the decimal point.
*/

// Better solution:

/*
We cannot make the O(k) part better because our whole idea is based on filling k gas stations one by one.

so we will try to optimize the part where we are finding the maximum sectionLength i.e. the O(n) part.

When we think about optimizing O(n), either O(log n) or O(1) comes to our mind as optimization because
obviously O(n/2) is not an improvement. 

As we can't find maximum in O(1), so that is out of question. 

Can we do it in log n time complexity?

So we will use Priority Queue (PQ).

PQ: always stores maximum value at the top. 

Internally it is implemented using heap data structure. 
Each time we push something i.e. use push(), it takes log n time complexity. 
top() takes O(1).

So overally PQ gives us the maximum using O(log n). We will try to use that.
*/

long double better(vector<int> &arr, int k){
    int size = arr.size();
    vector<int> howMany(size-1,0);
    priority_queue<pair<long double, int>> pq;

    for(int i=0;i<(size-1);i++){ // O(n)
        // pushing the initial section lengths along with their respective indices into PQ.
        pq.push({arr[i+1]-arr[i], i}); // O(log n)
    }

    for(int gasStations=1;gasStations<=k;gasStations++){ // O(k)
        auto top = pq.top();
        pq.pop(); // We first remove the maximum sectionLength along with its index.
        int sectionIndex = top.second;
        howMany[sectionIndex]++; // insertion

        // Then modify the sectionLength after insertion:

        long double initialDifference = arr[sectionIndex+1] - arr[sectionIndex];
        long double newSectionLength = initialDifference / (long double) (howMany[sectionIndex] + 1);

        // Then insert it back again after modification:

        pq.push({newSectionLength,sectionIndex}); // O(log n)
    }

    return pq.top().first;
}

// T.C. = O(n log n) + O(k log n) = O((n+k)*log n), so it is accepted.
// S.C. = O(n-1) because we are storing section length & section index for each section and as there are
// n elements in arr, there will be n-1 sections.

// In an interview, some interviewers will be happy with this solution.
// But some might not be happy and ask us to reduce the space complexity. 

// This is where the optimal solution comes in.

// Optimal solution: Binary Search. 
// The question is asking us to minimize the maximum distance b/w any two gas stations. 
// And we know whenever there is (min)max or (max)min, we can apply BS.


int numberOfGasStationsRequired(long double dist, vector<int> &arr) {
    int cnt = 0;
    for(int i = 1; i<arr.size();i++) { // O(n)
        int numberInBetween = ((arr[i] - arr[i-1]) / dist); // integer division i.e. floor value.
        if((arr[i] - arr[i-1]) / dist == numberInBetween * dist) { // if properly divisible.
            numberInBetween--;
        }
        cnt += numberInBetween;
    }
    return cnt;
}

long double minimiseMaxDistance(vector<int> &arr, int k){
    int n = arr.size();
    long double low = 0;
    long double high = 0;
    for(int i = 0;i<n-1;i++) { // O(n)
        high = max(high, (long double)(arr[i+1] - arr[i]));
    }

    long double diff = 1e-6; // as it is mentioned in the problem statement that answers within 10^-6 
    // of the actual answer will be accepted. i.e. upto 6 decimal places it should be same.
    while(high - low > diff) { // O(log n)
        long double mid = (low + high) / (2.0);
        int cnt = numberOfGasStationsRequired(mid, arr); // O(n)
        if(cnt > k) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    return high;
}

// so this is the standard procedure of doing BS on anything which has long double. 

// T.C. = O(n log n + n)
// S.C. = O(1)

