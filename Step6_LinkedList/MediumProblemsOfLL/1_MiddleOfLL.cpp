#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

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
    Node* temp = head;
    for(int i=1;i<arr.size();i++){
        Node* newNode = new Node(arr[i]);
        temp->next = newNode;
        temp = newNode;
    }
    return head;
}

void print(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Brute force solution: Two-pass solution.

Node* brute(Node* head){
    Node* temp = head;
    int length = 0;
    while(temp){ // O(n)
        length++;
        temp = temp->next;
    }
    int mid = (length/2) + 1;
    temp = head;
    while(temp){ // O(n/2)
        mid = mid - 1;
        if(mid == 0) break;
        temp = temp->next;
    }
    return temp;

    // T.C. = O(n + n/2)
    // S.C = O(1)
}

// Optimal solution: Tortoise & Hare Algorithm (concept of slow & fast pointers)

Node* optimal(Node* head){
    Node* fast = head;
    Node* slow = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow; 
}

int main(){
    vector<int> arr = {33, 54, 65, 22, 89};
    Node* head = convertArr2LL(arr);
    
    head = optimal(head);

    print(head);

    return 0;
}

