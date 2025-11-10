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

// Brute force solution/Extreme naive solution: 
// Using stack (LIFO) to reverse the data stored in the nodes.
Node* brute(Node* head){

    if(head == NULL || head->next == NULL) return head;

    Node* temp = head;
    stack<int> st;
    // Step 1: Pushing the data of the DLL into the stack.
    while(temp){ // O(n)
        st.push(temp->data);
        temp = temp->next;
    }
    // Step 2: Get everything out of the stack (and replace the data).
    temp = head;
    while(temp){ // O(n)
        // We stop when we reach the end of DLL or when the stack gets empty.
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    
    return head;

    // T.C. = O(2n) because of the two passes (traversals). 
    // S.C. = O(n) due to the external stack data structure to store the data of the nodes.
}

// This way we reverse the DLL, but only using (in terms of) data. 
// But this is a two-pass solution. The interviewer will not be happy with this and ask us to write a one-pass solution i.e. O(n) solution.

// So we have to find a way to reverse the DLL in a single traversal.

// Better & optimal solution: Swapping the links (pointers) of a node. 
// So our task is to reverse the links of all nodes in a single traversal.

Node* better(Node* head){
    // First solve for one node, and then it will be easy to solve for every node in the entire LL.
    if(head == NULL || head->next == NULL) return head;

    Node* prev = NULL;
    Node* current = head;
    while(current){ // O(n)
        // Swapping:
        prev = current->back;
        current->back = current->next;
        current->next = prev;

        // Traversal:
        current = current->back; 
        // We are traversing forwards after reversing the pointers 'next' & 'back'; so to move forward we use current->back instead of current->next.
    }
    return prev->back; // 'prev' will end up at the second last node of the initial DLL. But we have to return the new head which is the last node of the initial DLL. So we return prev->back because obviously the pointers are reversed.

    // T.C. = O(n)
    // S.C. = O(1); no extra space is used.
}

/* 
Remember: 
If you are going in for an interview, do not write these four lines and do a dry run:

    prev = current->back;
    current->back = current->next;
    current->next = prev;
    current = current->back;

No. Tell them the thought process. You considered one node, then you considered swapping of nodes, then you thought about the third variable and then you ended up on those four lines of code. You cannot just say that "Hey, these are the four lines". "How did you think about these lines?" - That is important and that is what the interviewer will look for. So make sure you tell them about the thought process and the intuition. 
*/

int main(){
    vector<int> arr = {34, 54, 65, 64};
    Node* head = convertArr2DLL(arr);

    // head = brute(head);
    head = better(head);

    print(head);

    return 0;
}

