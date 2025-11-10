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

// Brute force algorithm: Using stack data structure. 

Node* reverseList(Node* head) {
    Node* temp = head;
    stack<int> st;
    while(temp){
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;

    // T.C. = O(2n)
    // S.C. = O(n) because we are storing all the elements into the stack.
}

// This way we reversed the LL 'in terms of data'. 

// The interviewer will not be happy with the extra space we are using and will ask us to optimize it. 

// Optimal solution: Playing with the links instead (reversing them). 

Node* reversedLinkedList(Node* head){
    Node* temp = head;
    Node* prev = nullptr;
    while(temp){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev; // because at the end of the while loop, 'prev' will be standing at the last node of the initial LL which is our new head of the reversed LL. 

    // T.C. = O(n)
    // S.C. = O(1)
}

int main(){
    vector<int> arr = {35, 65, 66, 89};
    Node* head = convertArr2LL(arr);

    // head = reverseList(head);
    head = reversedLinkedList(head);

    print(head);

    return 0;
}