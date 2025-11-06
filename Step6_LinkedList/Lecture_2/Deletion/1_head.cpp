// head points to the start of the linked list. 

// We always write functions to achieve something with linked lists.

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

Node* deleteHead(Node* head){ // this function returns a new head

    if(head == NULL) return head; // edge case
    // if head points to nullptr, that means there is no LL (no node present)

    Node* temp = head; // temp is another pointer referring to the same node as head (no copy made).
    head = head->next;
    delete temp; // or free(temp); in order to free the part of the heap memory.

    // In java the 'delete temp;' statement is not required because we don't have to manually free that space; because in java we have something as garbage collector. The temp is somewhere in the heap memory. Whenever the garbage collector will run and will see that there is no reference to the temp, it will delete it automatically. It might not be an immediate operation, it might happen sometime in the future. But we don't need to worry. Java takes care of it whenever there is a memory issue. 

    // But in C++, we have to do it manually. 

    return head;
}

int main() {
    vector<int> arr = {12, 5, 8, 7};
    Node* head = convertArr2LL(arr);
    head = deleteHead(head);
    print(head);
}
