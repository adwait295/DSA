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

Node* removeTail(Node* head){
    // Basically we have to delete the last node and make the second last node as the new last node.

    // Edge case:

    // If there is only one node in the LL (head->next == NULL), then we delete that one node and return NULL i.e. there is no LL left after deletion
    if(head == NULL || head->next == NULL) return NULL;

    // If there are more than 1 node, then the 'second last node' concept is applicable:

    Node* temp = head;

    // While we are not at the second last node, keep traversing:
    while(temp->next->next != NULL) temp = temp->next;

    free(temp->next); // deleting the last node.

    temp->next = nullptr; // making the 'next' of second last node as nullptr and hence it becomes our new last node.

    return head;
}

int main(){
    vector<int> arr = {23, 34, 11, 56};
    Node* head = convertArr2LL(arr);
    head = removeTail(head);

    print(head);

    return 0;
}