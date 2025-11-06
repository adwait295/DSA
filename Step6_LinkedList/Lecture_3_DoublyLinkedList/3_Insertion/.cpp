// Inserting at something: Inserting 'before' that particular node (which was already in the LL). 

// Inserting before a node is slightly tougher than inserting after a node. 

// Your task is to insert 'after' the node by yourself. 

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public: 
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    public: 
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertArr2DLL(vector<int> &arr){
    if(arr.size() == 0) return NULL; // important.

    Node* head = new Node(arr[0]);
    Node* prev = head;

    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = prev->next; // or prev = temp
    }
    return head;
}

void print(Node* head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
}

Node* insertBeforeHead(Node* head, int value){
    Node* newHead = new Node(value, head, nullptr);
    head->back = newHead;

    return newHead;
}

Node* insertBeforeTail(Node* head, int value){
    // edge-case: If there is only one element in the DLL, then that node is the head as well as the tail of the LL.
    if(head->next == NULL) return insertBeforeHead(head, value);

    Node* tail = head;
    while(tail->next != nullptr) tail = tail->next;

    Node* prev = tail->back;
    Node* newNode = new Node(value, tail, prev);

    prev->next = newNode;
    tail->back = newNode;  

    return head;  
}

Node* insertAfterTail(Node* head, int value){
    if(head == NULL) return new Node(value);

    Node* tail = head;
    while(tail->next != NULL) tail = tail->next;

    Node* newTail = new Node(value, nullptr, tail);
    tail->next = newTail;

    return head;
}

Node* insertBeforeKthElement(Node* head, int k, int value){ // k is from 1 to n
    // The overall algorithm focuses on reaching the required node, and from there it's super simple and the same process has to be followed. 

    if(k == 1) return insertBeforeHead(head, value);

    Node* temp = head;
    int counter = 0;
    while(temp != NULL){
        counter++;
        if(counter == k) break;
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* newNode = new Node(value, temp, prev);
    prev->next = temp->back = newNode;

    return head;
}

void insertBeforeNode(Node* node, int value){
    // The given node is never the head of the LL because we don't want to change the head. 
    Node* prev = node->back;
    Node* newNode = new Node(value, node, prev);
    prev->next = node->back = newNode;
}

int main(){
    vector<int> arr = {34,54,55,22};
    Node* head = convertArr2DLL(arr);
    // head = insertBeforeHead(head, 10);
    // head = insertBeforeTail(head, 23);
    // head = insertBeforeKthElement(head, 2, 23);
    insertBeforeNode(head->next->next, 5);

    print(head);

    return 0;
}