// Always in LL problems, you start thinking of the edge cases and then build on it. Never ever try to think of the algorithm. 

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

Node* removeKthElement(Node* head, int k){ // k is from 1 to n(size of LL)
    
    if(head == NULL) return head; // standard edge-case.

    // Delete head:
    if(k == 1){ 
        Node* temp = head;
        head = head->next; // We can just do this and return head to achieve what we want but it's always good practice to delete the garbage in C++.
        delete temp;
        return head;
    }

    // Delete any other element:

    int counter = 0;
    Node* temp = head;
    Node* prev = nullptr; // or NULL.

    while(temp){ // or (temp != NULL)
        counter++;

        if(counter == k){
            prev->next = prev->next->next;
            delete temp;
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    return head;

    // If we are given any k which is greater than the length of the LL, we do nothing and simply return the head to the original LL as it was initially.

    // T.C. = O(k)
}

int main(){
    vector<int> arr = {34,55,33,66};
    Node* head = convertArr2LL(arr);

    head = removeKthElement(head, 1);

    print(head);

    return 0;
}