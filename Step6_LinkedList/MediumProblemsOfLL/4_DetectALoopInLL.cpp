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

// Brute force solution: Taking a map data structure and marking the nodes already visited as '1'.

bool brute(Node* head){
    unordered_map<Node*, int> mpp; // We can obviously also take ordered maps.
    Node* temp = head;
    while(temp){ // O(n)
        if(mpp.find(temp) != mpp.end()) // O(1)
            return true;
        mpp[temp] = 1; // O(1)
        temp = temp->next;
    }
    return false;

    // T.C. = O(n * (2*1)) in case of unordered maps & O(n * (2*log n)) in case of ordered maps.
    // S.C. = O(n) due to the map data structure. 
}

// The interviewer will not be happy with the extra space we are using and will ask us to optimize it. 

// Optimal solution: Tortoise & Hare Algorithm OR Slow & Fast Pointer Algorithm.
// Floyd's Cycle Detection Algorithm.

// If the 'slow' & 'fast' pointers meet at any point i.e. both the pointers happen to stand at the same node at any junction, then there is a loop and that is why the meet happened. 

// But why will they meet (collide) and not cross over ?

/*
Intuition: Once both 'slow' and 'fast' enter the loop, let's say the distance between fast and slow (not b/w slow and fast) is 'd'. So from there, in each iteration, the slow moves ahead by 1 and the fast moves ahead in the same direction by 2 and hence the distance b/w fast and slow decreases by 1 in every iteration. So there will obviously come an iteration where the d will become 0.

After d iterations, the distance b/w fast and slow becomes 0. 

# As the difference between 'number of steps fast moves' & 'number of steps slow moves' is 1 and we know that 1 is a factor of every number i.e. d % 1 = 0, so there will surely come a time when d becomes 0. The d is bound to reach 0.

And that's why the we move the fast pointer by 2 and slow pointer by 1 in the 'Slow & Fast pointer algorithm'.

Had the fast pointer moved by 3 (or any other higher number) and slow pointer by 1, then the difference might or might not be the factor of d (as we don't know what d is) and hence there would be a case of cross-over (slow & fast would cross each other).

So we always keep the difference as 1 between the 'slow' & 'fast' pointers.
*/

bool optimal(Node* head){
    Node* slow = head;
    Node* fast = head;
    // odd condition - fast->next != nullptr, even condition - fast != nullptr
    while(fast != nullptr && fast->next != nullptr){
        // The order of the conditions in the while loop cannot be changed because if the 'fast' is already at nullptr (after the last node) and we check fast->next from there, then it will give us error. 
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) return true; // condition for the existence of loop.
    }
    // If we have a linear LL, then the control will come out of the while loop without returning true whenever either of the conditions become false and hence we know there is no loop. 
    return false;

    // T.C. = O(n)
    // S.C. = O(1)
}

int main(){
    vector<int> arr = {34, 54, 66, 53};
    Node* head = convertArr2LL(arr);

    if(brute(head)) cout << "There is a loop" << endl;
    else cout << "No loop" << endl;

    print(head);

    return 0;
}