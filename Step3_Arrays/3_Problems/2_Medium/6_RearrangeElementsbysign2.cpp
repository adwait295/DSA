#include<bits/stdc++.h>
using namespace std;

/*
In the second variety, we are not sure that the number of positive integers is equal to the number of negative
integers. One can be more than the other. But the rules remain the same. We arrange them alternately until
one of them is over. After that the remaining positive or negative elements are placed in order.

For e.g. [-1,2,3,5,-5,6,7]           Output: [2,-1,3,-5,5,6,7]
*/

// This is a very good follow-up question because in this variety, we cannot use the optimal solution of the 
// previous variety. Because, the optimal solution will work only when number of positive integers is 
// equal to the number of negative integers. 

// So when variety changes, we start to think there is some other solution. We forget to fall back to the
// brute force solution because we are not confident of our initial solution.

// So we fall back to the brute force solution:

vector<int> alternateNumbers(vector<int> &a){
    vector<int> pos, neg;
    int size = a.size();
    for(int i=0;i<size;i++)
    {
        if(a[i] > 0) pos.push_back(a[i]);
        else neg.push_back(a[i]);
    }

    int posSize = pos.size();
    int negSize = neg.size();

    if(posSize > negSize){
        for(int i=0;i<negSize;i++)
        {
            a[2*i] = pos[i];
            a[2*i + 1] = neg[i];
        }
        int index = negSize * 2;
        for(int i=negSize;i<posSize;i++)
        {
            a[index] = pos[i];
            index ++;
        }
    }
    else{ // covers the equality condition as well, i.e. posSize = negSize
        for(int i=0;i<posSize;i++)
        {
            a[2*i] = pos[i];
            a[2*i + 1] = neg[i];
        }
        int index = posSize * 2;
        for(int i=posSize;i<negSize;i++) // if posSize = negSize, then this loop will not work and we have the variety 1 answer as well.
        {
            a[index] = neg[i];
            index ++;
        }
    }
    return a;
}

/*
T.C. = O(n) + O(min(posSize,negSize)) + O(leftovers)

In the worst case, either all are negative or all are positive.  then O(n) + O(0) + O(n) = O(2n).
In the best case, posSize = negSize. then O(n) + O(n/2) + O(0) = O(3n/2).

So the T.C. = O(2n).

S.C. = O(n)
*/

int main(){
    int size;
    cin >> size;
    vector<int> a;
    for(int i=1;i<=size;i++)
    {
        int n;
        cin >> n;
        a.push_back(n);
    }

    vector<int> answer = alternateNumbers(a);

    cout << "Rearranged Array: " << endl;

    for(int i=0;i<size;i++) cout << answer[i] << " ";

    cout << '\n';

    return 0;
}

// Can you modify the optimal solution of previous variety and make your own version solution for this variety?
// Think about it. Try it. Even if the T.C. is a bit more, give it a try.