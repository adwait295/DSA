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

// Brute force solution & my solution: Using stack data structure.

bool isPalindrome(Node* head) {

    if(head == nullptr || head->next == nullptr) return true; // edge-case.

    stack<int> st;
    Node* temp = head;
    // Step 1: // O(n)
    while(temp){
        st.push(temp->data);
        temp = temp->next;
    }
    // Step 2: // O(n)
    temp = head; // Never ever alter the head because we never know when or where we might require to use it in the future.
    while(temp){
        int val = st.top();
        if(temp->data != val) return false;
        temp = temp->next;
        st.pop(); 
    }
    // The moment our 'temp' reaches NULL or our stack gets empty, all comparisions are done and dusted and we have not yet returned false (because it turned out to be a palindrome), so we return true.  
    return true;

    // T.C. = O(2n)
    // S.C. = O(n)
}

// This is where our interviewer won't be happy with the extra space that we are using and ask us to optimize it. 

// So we have to use an algorithm which restricts us to the given LL and we don't use any external data structure in our algorithm. 

// Optimal solution:

/*
Our algorithm:

We want to compare:
the first & the last
the second & the second last 
the third & the third last 
and so on. 

but when we are at the last node(the tail), we cannot traverse backwards and compare. So we need to reverse the links of the second half of the LL so that we can traverse backwards in the second half and traverse forwards in the first half and compare each element with its mirror element. 

For that we need to figure out the middle of the LL (Tortoise & Hare algorithm). We will change the conditions a bit so that in case of even number of nodes, we stop at the first middle node, not second which we did in the previous problem. 

Then we reverse the second half using recursion. 

Once we are done comparing and before we return true/false, we make sure to change the reversed part of the LL back to what it was at the beginning.

Parts of our algorithm:
1. Finding the middle.
2. Reversing the second half.
3. Comparing.
4. Reversing the second half again to what it was at the beginning. 
*/

Node* reverse(Node* head){
    if(head == nullptr || head->next == nullptr) return head;

    Node* newHead = reverse(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = nullptr;

    return newHead;
}

bool Palindrome(Node* head){

    if(head == nullptr || head->next == nullptr) return true; // edge-case.

    // Part 1: O(n/2)
    Node* slow = head;
    Node* fast = head;
    while(fast->next != nullptr && fast->next->next != nullptr){
        // The order can't be reversed. fast->next has to be checked first and then only fast->next->next can be checked. Otherwise we will get error in some test cases.
        slow = slow->next;
        fast = fast->next->next;
    }

    // Part 2: O(n/2)
    Node* newHead = reverse(slow->next);
    // After reversing, 'slow' is still connected to 'slow->next'. We don't touch it because we have to again reverse the second half of LL back to what it was after we are done solving the problem. 
    // Refer copy or TUF notes. 
    
    // Part 3: O(n/2)
    Node* temp1 = head;
    Node* temp2 = newHead;
    while(temp2 != nullptr){ 
        // We don't write 'temp1 != nullptr' condition in while loop because in case of odd number of nodes, when temp2 will be nullptr, temp1 will be at the middle node of the LL and not nullptr. (Try an example and check yourself)
        if(temp1->data != temp2->data){
            reverse(newHead); // Part 4: O(n/2)
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    reverse(newHead); // Part 4: O(n/2)
    return true;

    // reverse(newHead) is very very important for interviews because people don't want you to alter the given data. So if you've done something, make it back to the original configuration.

    // T.C. = O(2n)
    // S.C. = O(1), we have not taken into account the recursive stack space.
    // If we want, we can reverse the linked list using the iterative method and not the recursive method. 
}

int main(){
    vector<int> arr = {1, 2, 4, 5, 3, 2, 1};
    Node* head = convertArr2LL(arr);

    bool isPalindrome = Palindrome(head);
    if(isPalindrome) cout << "Yes the LL is palindrome." << endl;
    else cout << "No the LL is not palindrome." << endl;

    print(head);

    return 0;
}