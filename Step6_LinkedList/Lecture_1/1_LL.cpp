#include<bits/stdc++.h>
using namespace std;

// This is how we define a struct:
// struct Node{body}

// But instead of 'struct', we use 'class' to have object oriented programming.
// Both are written in the same way, just words used are different.
// The difference b/w struct and class is that struct does not offer us object oriented programming concepts like abstraction, encapsulation, inheritance unlike class.

// So whenever you are taking a self-defined object, always take a class. 

// In the upcoming lectures in graph series, we have a Disjoint set data structure and we have used self-defined object. We have defined it as class not struct over there, which has helped us significantly. 

class Node{

    public:
    int data;
    Node* next;

    public: // We are defining the constructor to be public as well.
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    // In a lot of declarations, we will find there are multiple constructors.

    public: 
    Node(int data1){
        data = data1;
        next = nullptr;
    }

    // Why multiple constructors?
    // Because what if I don't want to pass a null pointer again and again. 
    // We just pass Node* y = new Node(arr[0]); and it automatically assumes the next to be null pointer i.e. nullptr.

    // so we can have multiple constructors. A constructor is nothing but a special member function which is used to initialize the objects. 
    // Here int data & Node* next are the objects of the class Node i.e. in the sense a self-defined object. 
};

int main(){
    vector<int> arr = {2, 5, 8, 7};
    Node* y = new Node(arr[0], nullptr); // technically always use this. 

    // The new keyword directly gives us a pointer to the memory location and then we can store it. 

    /*
    But what if we define it like this:
    Node y = Node(arr[0], nullptr);

    Here, we are technically creating an object where arr[0] & nullptr, these two things are there.

    So if we now do cout << y, it will give us an error because y is an object. 
    We can either take its data:
    cout << y.data; // it prints 2.

    or we can take its next:
    cout << y.next; // it prints 0x0 which is basically the null pointer.


    But when we do: Node* y = new Node(arr[0], nullptr);
    we cannot do cout << y.value or cout << y.next, it will give us an error. But we can do:

    cout << y->data; // it will give us 2.
    cout << y->next; // it will give us 0.

    to get those respective results.
    */
    cout << y;
}

/*
In Java, there is no concept of pointers. So we don't use *.

In order to access the class object, we use 'this'. So for that object, it can directly initialize the values; and instead of nullptr, it will be null.

We cannot define public because it is already by default public so no need to define it. 

class Node {
    int data;
    Node next;

    Node(int data1, Node next1) {
        this.data = data1;
        this.next = next1; // 'this' is used to access the object.
    }

    Node(int data1) {
        this.data = data1;
        this.next = null;
    }
}

public class LinkedList {
    public static void main(String[] args) {
        int[] arr = {2, 5, 6, 8};
        Node y = new Node(arr[3]); // because we have a constructor where we don't need to pass the value of next.

        System.out.print(y.data); // gives 8
    }
}

*/

// C++ has struct as well as class. Java has only class. 