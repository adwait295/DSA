// Inserting at kth position; k can be anything from 1 to n+1, where n is the size of LL. If it exceeds this range, we can print some message.
// k = 1 means insert at the 'head'.

// Whenever you get a LL problem, always try to think case by case.

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

Node* insertKthElement(Node* head, int value, int k){

    // Case 1: Inserting at head.
    if(head == NULL){ // standard edge-case.
        if(k == 1) return new Node(value);
        else return head; // or return NULL.
    }

    if(k == 1) return new Node(value, head);

    // Case 2: Inserting at k=2 to k=n+1: We have to stop at previous element.
    int counter = 0;
    Node* temp = head;
    while(temp){ // When k > n+1, it automatically goes out of the while loop, so that case is covered too.
        counter++;
        if(counter == (k-1)){ // stops at previous element.
            Node* newNode = new Node(value);
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
    // T.C. = O(n), in the worst case obviously.
}

int main(){
    vector<int> arr = {34, 24, 56, 52};
    Node* head = convertArr2LL(arr);
    head = insertKthElement(head, 100, 4); // try 6.

    print(head);

    return 0;
}