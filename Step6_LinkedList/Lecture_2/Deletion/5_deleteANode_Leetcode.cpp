// Definition for singly-linked list:

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    // LeetCode’s method (copy–bypass) vs Proper deletion (traverse–unlink–delete).

    // Fake deletion: works only when the given 'node' is not the last node in the LL, i.e. not a tail node.
    void deleteNode(ListNode* node) {
        node->val = node->next->val;   // copy data from next node
        node->next = node->next->next; // skip the next node
    }
};

// This LeetCode problem (Delete Node in a Linked List) is an exceptional case, not a model for good coding practice.

/*
What LeetCode forces you to do

They don’t give you the head of the linked list — they give only a pointer to the node you need to delete.

That means you can’t traverse from the beginning to find and delete it properly.

So you’re forced to fake deletion by:

node->val = node->next->val;
node->next = node->next->next;


(and ideally delete temp if you had access to it)

This works because you’re copying over the next node’s data and bypassing it — visually, it looks deleted.

*/

/*
But in real code (or interviews beyond this problem),
You should never do this unless it’s absolutely necessary.
Proper deletion should look like this:

Node* deleteNode(Node* head, int value) {
    if (head == nullptr) return nullptr;

    // if head itself is to be deleted
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp; // free memory
        return head;
    }

    Node* curr = head;
    while (curr->next && curr->next->data != value) {
        curr = curr->next;
    }

    if (curr->next) {
        Node* temp = curr->next;
        curr->next = curr->next->next;
        delete temp; // cleanly delete
    }

    return head;
}

This way:

You start from the head.

You find the node before the one to be deleted.

You unlink it properly.

You delete temp to free heap memory.
*/