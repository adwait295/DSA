#include<bits/stdc++.h>
using namespace std;

// What is Dynamic Programming? 
// Remembering the Past.

int maxProfit(vector<int>& prices){
    int size = prices.size();
    int minm = INT_MAX, maxm = INT_MIN, profit = 0;
    for(int i=0;i<size;i++)
    {
        if(prices[i] < minm) minm = prices[i];
        // We are remembering the minimum throughout the process, in every step
        // As there is remembering of the past, it comes under Dynamic Programming.
        if(prices[i] >= minm) maxm = prices[i];
        profit = max(profit, maxm-minm);
    }
    return profit;
}

// T.C. = O(n)
// S.C. = O(1)

int main(){
    int size;
    cin >> size;
    vector<int> arr;
    for(int i=1;i<=size;i++)
    {
        int n;
        cin >> n;
        arr.push_back(n);
    }
    cout << "Maximum profit: " << maxProfit(arr);

    return 0;
}