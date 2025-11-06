// Insert an element at the head of the LL.

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

    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void print(Node* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* insertHead(Node* head, int value){ // O(1)
    // return new Node(value, head);

    // Or:

    Node* temp = new Node(value, head); // we have defined the constructor initially.
    return temp; // 'temp' is our new 'head'.

    // if there is no LL inititally, i.e. head = nullptr, then a node is created with next = nullptr obviously. so the edge case of (head == NULL) is also covered in the above code.
}

int main(){
    vector<int> arr = {34, 24, 56, 52};
    Node* head = convertArr2LL(arr);
    head = insertHead(head, 100);

    // or without using the insertHead(), we can do it directly by:
    // head = new Node(100, head); // using constructor directly.
    print(head);

    return 0;
}