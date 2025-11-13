#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i=1;i<arr.size();i++){
        Node* newNode = new Node(arr[i]);
        temp->next = newNode;
        temp = newNode;
    }
    return head;
}

void print(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

/*
What is recursion, why it is used or how do we use it?

Generally we are given a large problem statement which we cannot solve at once. So what we do is we break down the large problem statement to a smaller problem and then again break it into a smaller problem and then again. This breaking down stops the moment we can solve the smaller problem at hand. Then we try to give the answer back to it's bigger problem which uses our answer to find out it's answer and in return does the same and returns back it's answer to it's bigger problem and so on. It goes on till we solve the main large problem statement we were given at first. 

So basically we break it down to small, smaller, smaller and smallest and eventually extract the answers and solve it.
*/

/*
Here we are given a LL and our task is to reverse it using recursion.

Let's say we have 4 nodes and we want to reverse it. 
So in order to reverse an LL with 4 nodes, we first try to reverse the LL with one node, then two nodes, then three nodes, then four nodes and then n nodes. 

The base case is the smallest problem we are trying to solve.
*/

// After we have called the sub-problems, the pointers will be changed after each one gets solved because they are in-memory nodes. 

// We call the sub-problem and the sub-problem solves itself and returns a newHead after doing the necessary changes to the LL passed to it. 

// So we call reverse(4 nodes), then reverse(3 nodes), then reverse(2 nodes), and then reverse(1 node) and come back with answers from each smaller previous step and use it to find the answer in the present big step and pass the answer to the bigger problem step.

Node* reverse(Node* head){
    if(head == NULL || head->next == NULL) return head;

    Node* newHead = reverse(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = nullptr;

    return newHead;

    // T.C. = O(n) because we are doing n steps i.e. n recursion calls. 
    // S.C. = O(n), which is the recursive stack space of the calls we are doing. 
}