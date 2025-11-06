// Inserting an element before the value x (which is present in the LL for sure).

// Think about all the cases.

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

Node* insertBeforeValue(Node* head, int element, int value){
    if(head == NULL){ // If there is no value, then we cannot find anything and hence we don't know where to insert.
        cout << "Value not found" << endl;
        return NULL;
    }   

    if(head->data == value) return new Node(element, head);

    Node* temp = head;
    bool found = false;
    while(temp->next != NULL){
        if(temp->next->data == value){
            Node* newNode = new Node(element, temp->next);
            temp->next = newNode;
            found = 1;
            break;
        }
        temp = temp->next;
    }
    if(found == 0) cout << "Value not found" << endl;
    return head;
}

int main(){
    vector<int> arr = {34,56,65,43};
    Node* head = convertArr2LL(arr);
    head = insertBeforeValue(head, 100, 43); // try 90.

    print(head);

    return 0;
}