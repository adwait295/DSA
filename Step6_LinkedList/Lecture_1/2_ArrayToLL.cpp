#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convertArr2LL(vector<int> &arr){ // return type is Node* because datatype of head is Node*. 
    Node* head = new Node(arr[0]); // since we have multiple constructors, even if we don't pass nullptr as second value, our second constructor will take care of that.

    /*
    What is happening?

    When we do new Node(arr[0]):

    Heap Memory
    ┌─────────────┐
    │ data = 12   │
    │ next = NULL │
    └─────────────┘
        ↑
    Address: 0x100
        ↑
    head (in stack)

    */

   /*
    | Component    | What it points to |
    | ------------- | ---------------- |
    | head          | first node        |
    | node1.next    | node2             |
    | node2.next    | node3             |
    | node3.next    | node4             |
    | node4.next    | NULL              |

    So there are 5 pointers: 4 internal pointers (inside 4 nodes) & 1 external pointer(head).

    head is a pointer to node1. So when we say head, we mean node1. So we consider node1 as head of the LL & node1.next or head.next points to node2. So head is a pointer to first node & head->next is a pointer to second node.
    (It is not '.', it is '->'. I have written just to make it easy to decipher)

   */
    
    // head is the pointer to the first location of the linked list. 
    Node* mover = head;

    for(int i=1;i<arr.size();i++){ // O(n)
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp; // or mover = mover->next; both are the same things.
    }
    return head;
}

int main(){
    vector<int> arr = {12, 5, 8, 7};
    Node* head = convertArr2LL(arr);
    cout << head->data;
}