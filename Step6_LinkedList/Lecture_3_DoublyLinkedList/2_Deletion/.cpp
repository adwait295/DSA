// Basically we delete an element from LL after we complete it's 'segregation'.

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public: 
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    public: 
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertArr2DLL(vector<int> &arr){
    if(arr.size() == 0) return NULL; // important.

    Node* head = new Node(arr[0]);
    Node* prev = head;

    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = prev->next; // or prev = temp
    }
    return head;
}

void print(Node* head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
}

Node* deleteHead(Node* head){
    if(head == NULL || head->next == NULL) return NULL; // or nullptr.

    Node* prev = head;
    
    head = head->next;
    head->back = nullptr;

    // Segregation:
    prev->next = nullptr;
    // once the previous node is segregated, i.e. it has no connections to anyone, we can delete it.
    delete prev;

    return head;
}

Node* deleteTail(Node* head){
    if(head == NULL || head->next == NULL) return NULL; // or nullptr.

    Node* tail = head;
    while(tail->next) tail = tail->next; // or (tail->next != NULL)

    Node* prev = tail->back; // 'prev' is our new tail of LL. 

    // Segregation:
    prev->next = nullptr;
    tail->back = nullptr;

    // Deletion:
    delete tail;

    return head;
}

Node* deleteKthElement(Node* head, int k){ // k is from 1 to n.
    // Edge cases: 
    // 1. LL is empty.
    // 2. k = 1, back is not there. (deleting head)
    // 3. k = n, next is not there. (deleting tail)
    // 4. if DLL has only one element, neither back nor next is there.

    if(head == NULL) return NULL; // standard edge-case. // case 1.

    // First step is reaching the kth node:
    Node* kNode = head;
    int counter = 0;
    while(kNode != NULL){
        counter++;
        if(counter == k) break;
        kNode = kNode->next;
    }
    // Now we have reached the kth node.

    if(k > counter || k < 1){ // important.
        cout << "Give k value between 1 to n (size of LL)" << endl;
        return head;
    }

    Node* prev = kNode->back;
    Node* front = kNode->next;

    if(prev == NULL && front == NULL){ // case 4
        delete kNode;
        return NULL;
    }
    else if(prev == NULL) return deleteHead(head); // case 2
    else if(front == NULL) return deleteTail(head); // case 3
    
    prev->next = front;
    front->back = prev;
    kNode->next = nullptr;
    kNode->back = nullptr;
    delete kNode;

    return head;
}

// removing a given node in a DLL: 

/*
Constraint:
It is given that the node given to be deleted can never be 'head'.
Why?
Because we need 'head' to give a particular node to delete from the LL while invoking the function. Without the 'head', there will be no way of mentioning which node to delete.
In a LL : {34, 54, 65, 64}
34 is the head.
head->next = node containing data as 54.
head->next->next = node containing data as 65.
head->next->next->next = node containing data as 64.
Without head, there is no way to pass the node to the function.

If we pass 'head' to be deleted to the function, then the 'head' will have to be moved; we have to take the new head to 54. So we will have to write more and more conditions and that's why THIS QUESTION will never ask us to delete the head of the DLL.

We are given a node 'temp' to delete. It will have a 'prev' & 'front'.
We just have to link 'prev' & 'front' and then unlink the 'temp' from the LL.

Only one edge-case is what if the 'temp' is the tail? In that case, there will be no 'front'.
*/

void deleteNode(Node* temp){
    Node* prev = temp->back;
    Node* front = temp->next;

    if(front == NULL){
        prev->next = nullptr;
        temp->back = nullptr;

        free(temp);

        return; // since it is a void function.
    }
    prev->next = front;
    front->back = prev;

    temp->next = temp->back = nullptr;

    free(temp);
}

int main(){
    vector<int> arr = {34, 54, 65, 64};
    Node* head = convertArr2DLL(arr);
    // head = deleteHead(head);
    // head = deleteTail(head);
    // head = deleteKthElement(head, 3);
    deleteNode(head->next->next->next);

    print(head);

    return 0;
}