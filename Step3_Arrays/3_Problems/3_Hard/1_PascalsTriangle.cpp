#include<bits/stdc++.h>
using namespace std;

/*
There can be 3 variations to this question:

1. Given row(R) & column(C) number, return the element at that position in the Pascal's triangle.
2. Print the nth row of the Pascal's triangle.
3. Given n, print the entire Pascal's triangle till row 'n'.
*/

// Variation 1:

int nCr(int n, int r){
    long long res = 1; // in nCr & similar situations, we prefer to take long long in order to prevent overflow.
    for(int i=0;i<r;i++)
    {
        res = res * (n-i);
        res = res / (i+1);
    }
    return res;

    // T.C. for finding nCr : O(r)
    // S.C. = O(1)
}

// We just pass the value to the nCr() i.e. nCr(R-1,C-1) and we get our element.

// Variation 2:

/*
Brute force: 
We know that a particular element whose position is given, can be found by nCr formula.
So we can use that, keep the row number constant and increase the value of column number from 1 to row number
and call nCr() again and again to give the element at each position. We do this because we can notice that
the number of columns is equal to the row number i.e. 1st row has one element, 2nd has two and so on.

Nth row -> N elements and hence N columns.

for(int c=1;c<=n;c++)
{
    cout << nCr(n-1,c-1);
}

T.C. = O(n*r) where r = c-1 in every iteration & because nCr() has a T.C. of O(r).

So the interviewer will not be happy by this T.C. 
He will say, why using the formula repeatedly, can you do it in a better way?

Refer notes.

Pseudo code:

ans = 1
print(ans)
for(i=1;i<n;i++)
{
    ans = ans * (n-i)
    ans = ans / i

    print(ans)
}

where n is the row number(1-based indexing) and i is the column number(0-based indexing).

T.C. = O(n) where n is the number of rows
S.C. = O(1)
*/

// Variation 3:

// Brute force solution:

vector<vector<int>> pascalTriangle(int n) {
    vector<vector<int>> ans;

    //Store the entire pascal's triangle:
    for (int row = 1; row <= n; row++) { // 1-based indexing               O(n)
        vector<int> tempLst;
        for (int col = 1; col <= row; col++) { // 1-based indexing         O(n) 
            tempLst.push_back(nCr(row - 1, col - 1));                   // O(r)
        }
        ans.push_back(tempLst);
    }
    return ans;

    // T.C. = near about O(n*n*r), i.e. O(n^3), not exactly obviously but going towards it.
    // S.C. = O(1); we are just using space to store the answer.
}

// Optimal solution:
// We will use better solution of variant 2 to generate all the rows row-wise.
// T.C. = O(n) * O(n) = O(n^2).

vector<int> generateRow(int row) {
    long long ans = 1; // first column
    vector<int> ansRow;
    ansRow.push_back(1);

    for(int col = 1; col < row; col++) { // 0-based indexing starting from column 1.
        ans = ans * (row - col);
        ans = ans / (col);
        ansRow.push_back(ans);
    }

    return ansRow;
}

vector<vector<int>> pascalTriangle(int N) {
    vector<vector<int>> ans;
    for(int i = 1; i <= N; i++) { // 1-based indexing
        ans.push_back(generateRow(i));
    }
    return ans;
}

/*
In an interview, always maintain code readability. The same solution could also have been written
like this:

vector<vector<int>> pascalTriangle(int N) {
    vector<vector<int>> ans;
    for(int i = 1; i <= N; i++) {
        long long ansVal = 1;
        vector<int> ansRow;
        ansRow.push_back(1);

        for(int col = 1; col < i; col++) {
            ansVal = ansVal * (i - col);
            ansVal = ansVal / col;
            ansRow.push_back(ansVal);
        }

        ans.push_back(ansRow);
    }
    return ans;
}

without using a separate function for generating the rows. But this way, our code becomes long 
and difficult to comprehend even if it gives the same correct answer. 

So always take care to make the code simple, easy to understand, break it into readable functions if the code
seems to get longer so that when someone reads, he can know from even by overally looking at the code that 
this is what we are trying do in our algorithm. 

Interviews are not all about solving problems. Its about presenting them properly too. It is very important.

If we maintain everything while solving the problem, then only we will be able to qualify in the interview.
*/


// My solution:

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> answer;
    answer.push_back({1});

    if(numRows == 1) return answer;

    vector<int> power1 = {1, 1};
    answer.push_back(power1);

    for (int i = 2; i < numRows; i++) {
        int m = 0, n = 1;
        vector<int> power2;
        while (n < power1.size()) {
            int sum = power1[m] + power1[n];
            power2.push_back(sum);
            m++, n++;
        }
        power1 = power2;
        power1.insert(power1.begin(), 1);
        power1.push_back(1);
        answer.push_back(power1);
    }
    return answer;
}