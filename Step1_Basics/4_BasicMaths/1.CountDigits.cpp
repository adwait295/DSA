#include<bits/stdc++.h>
using namespace std;

int count(int n){ // Brute force approach
    int cnt = 0;
    while(n>0)
    {
        int lastDigit = n % 10;
        cnt++;
        n = n / 10;
    }
    return cnt;

    // Time complexity is O(log10 n) as at every step, n is being divided by 10 and the while loop is running for log10(n) number of times
    // If n = n/2, then T.C. would be O(log2 n)
    // So when there is division operation, O(log n) comes into picture
}

int count1(int n){ // Optimal approach
    int cnt = (int)(log10(n)+1);
    return cnt;
    // T.C. = O(1)
}

int main(){
    int t;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        int n;
        cin >> n;
        cout << count(n) << endl;
    }
    return 0;
}