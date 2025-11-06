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

Node* insertTail(Node* head, int value){
    if(head == NULL) return new Node(value);

    Node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    // In LL traversal, we used to go till (temp != NULL), but here we are going till (temp->next != NULL) because we want to end up at the last element in the original LL.

    Node* newNode = new Node(value);
    temp->next = newNode;

    return head;
}

int main(){
    vector<int> arr = {34, 24, 56, 52};
    Node* head = convertArr2LL(arr);
    head = insertTail(head, 100);

    print(head);

    return 0;
}