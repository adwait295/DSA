/*
Q. Problem statement
You are given a Doubly linked list, where every node in the linked list contains two pointers ‘next’ and ‘prev’ which point to the next node and previous node in the list respectively. All nodes have some positive integer value associated with them. Your task is to insert an integer value ‘VAL’ in the linked list at a given position ‘K’.

Note:

The position given will always be less than or equal to the length of the linked list.
Assume that the Indexing for the linked list starts from 0.
EXAMPLE:
Input :
‘K’ = 3, ‘VAL’ = 4
list = [1, 2, 3]
Output: [1, 2, 3, 4]

The ‘VAL’ = 4, is inserted at end of the above doubly linked list.
*/

/*
Constraints :
1 <= 'T' <= 10
1 <= Length of the list <= 10^4
0 <= ‘K’ <= Length of the list, where ‘K’ is 0-indexed.
1 <= 'VAL' <= 10^5

Time Limit: 1 sec
*/

#include <bits/stdc++.h> 
/************************************************************

    Following is the linkedList class structure:

    class Node {
    public:
        int data;
        Node *next;
        Node *prev;

        Node(int val) {
            this->data = val;
            next = NULL;
            prev = NULL;
        }
        ~Node() {
            if(next != NULL || prev != NULL){
                delete next;
            }
        }
};

************************************************************/
class Node {
    public:
        int data;
        Node *next;
        Node *prev;

        Node(int val) {
            this->data = val;
            next = NULL;
            prev = NULL;
        }
        ~Node() {
            if(next != NULL || prev != NULL){
                delete next;
            }
        }
};

Node* insert(int k, int value, Node *head) {
    // Before head:
    if(k == 0){
        Node* newHead = new Node(value);
        newHead->next = head;
        newHead->prev = nullptr;

        head->prev = newHead;
        return newHead;
    }

    Node* temp = head;
    int counter = 1;
    while(temp->next){
        if(counter == k) break;
        counter++;
        temp = temp->next;
    }
    // After the tail:
    if(temp->next == nullptr){
        Node* newTail = new Node(value);
        newTail->next = nullptr;
        newTail->prev = temp;

        temp->next = newTail;

        return head;
    }

    Node* front = temp->next;
    Node* newNode = new Node(value);
    newNode->next = front;
    newNode->prev = temp;

    front->prev = temp->next = newNode;

    return head;
}

