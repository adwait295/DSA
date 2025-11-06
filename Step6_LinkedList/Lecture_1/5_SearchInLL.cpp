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

int checkIfPresent(Node* head, int value){
    Node* temp = head;
    while(temp){
        if(temp->data == value) return 1;
        temp = temp->next;
    }
    return 0;

    // Worst case: O(n)
    // Best case: O(1) when the search element is in the head of the LL
    // Avg case: O(n/2)
}

int main(){
    vector<int> arr = {4, 45, 2, 22};
    Node* head = convertArr2LL(arr);
    
    int result = checkIfPresent(head, 5);
    if(result == 1) cout << "Present";
    else cout << "NOT present";

    return 0;
}