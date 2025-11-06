// Delete the first occurence of a value in the LL.

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

Node* removeElement(Node* head, int value){
    
    if(head == NULL) return head; // standard edge-case.

    // Delete head:
    if(head->data == value){ 
        Node* temp = head;
        head = head->next; // We can just do this and return head to achieve what we want but it's always good practice to delete the garbage in C++.
        delete temp;
        return head;
    }

    // Delete any other element:

    Node* temp = head;
    Node* prev = nullptr; // or NULL.

    while(temp){ // or (temp != NULL)

        if(temp->data == value){
            prev->next = prev->next->next;
            delete temp;
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    return head;

    // If we are given a value that is not in the LL, we do nothing and return the head to the original LL.

    // T.C. = O(k)
}

int main(){
    vector<int> arr = {34,55,33,66};
    Node* head = convertArr2LL(arr);

    head = removeElement(head, 34);

    print(head);

    return 0;
}