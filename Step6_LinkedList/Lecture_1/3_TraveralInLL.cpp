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

int main(){
    vector<int> arr = {4, 45, 2, 22};
    Node* head = convertArr2LL(arr);
    
    // Traversal code: // O(n)
    Node* temp = head;
    while(temp){ // or while(temp != nullptr)
        // when a pointer (like Node* temp) is assigned nullptr, it is considered false (or equivalent to 0) in conditional expressions.
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}