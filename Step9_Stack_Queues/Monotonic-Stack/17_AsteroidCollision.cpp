#include<bits/stdc++.h>
using namespace std;

// Additional info (for Lists):
// List in C++ does not inherently store everything in a LIFO (Last-In, First-Out) manner; it's a doubly linked list allowing insertions and deletions at both ends (front and back) and in the middle, making it flexible for FIFO (Queues) or LIFO (Stacks) operations when you use its specific functions like push_back/pop_back or push_front/pop_front.

// Using vectors (we could have also used lists) for this problem:
// This is a question of Monotonic Stack. We could have used a stack. But as it stores in LIFO manner, so while returning a vector we would have to first push the elements from the stack to the 'ans' vector and then reverse it and then return which would take additional time. So we used vector instead in which all the required operations of stack can be done without the additional step in the end.


// Optimal solution:

vector<int> asteroidCollision(vector<int> &asteroids){
    vector<int> ans;
    int size = asteroids.size();
    for(int i=0;i<size;i++){ 
        if(asteroids[i] > 0) ans.push_back(asteroids[i]);
        else{
            while(!ans.empty() && ans.back() > 0 && ans.back() < abs(asteroids[i])) ans.pop_back();
            if(!ans.empty() && ans.back() == abs(asteroids[i])) ans.pop_back();
            else if (ans.empty() || ans.back() < 0) ans.push_back(asteroids[i]);
        }
    }
    return ans;
}

// T.C. = O(2n)
// It looks like the T.C. would be O(n^2). But when we look closely, we find out that the inner while loop runs for a total of n times throughout the journey of the outer for loop from 1 to n. And hence the total is n+n.

// S.C. = O(n)