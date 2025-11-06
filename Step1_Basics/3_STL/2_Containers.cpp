#include<bits/stdc++.h>
using namespace std;

// Containers can be vectors, queues, sets, maps and
// a lot of other things

/* Pairs:
- a part of utility library
*/

void explainPair(){
    pair<int,int>p = {1,2}; // to store two integers
    // data types can be anything and can be different
    cout<<p.first<<" "<<p.second; // accessing elements of p
    
    // nested property of pairs to store more than 2 elements
    pair<int,pair<int,int>>q = {1,{2,3}}; // 3 elements
    cout<<q.second.first;
    pair<pair<int,int>,pair<int,pair<int,int>>> x = {{1,2},{3,{4,5}}}; // 5 elements
    cout<<x.second.second.first;

    // pair array
    pair<int,double> arr[]= {{1,2.4},{3,4},{5,6.7}};
    cout<<arr[1].second;
}

// First container - Vectors

/* 
Arrays are constant in size i.e. their size cannot be modified.
Vector is a container which is dynamic in nature, so we can always increase the size of the vector whenever we wish to
The best place to use vectors is when we dont know the size of the data structure being used.
*/
    
void explainVector(){
    vector<int> v; // {}
    // any datatype
    // it creates an empty container 

    v.push_back(1); // {1}
    // inserts 1 into the container
    v.emplace_back(2); // {1,2}
    // similar to push_back
    // They dynamically increase the size of the vector.
    // Generically emplace_back is faster than push_back.

    // vector of a pair datatype
    vector<pair<int,int>> x;
    x.push_back({1,2});
    x.emplace_back(2,3); // {} is not required in this case - automatically assumes it to be a pair
    // This is how emplace_back is different from push_back in terms of syntax
    
    vector<int> v(5,100); // {100,100,100,100,100} 
    // declaration of a vector already filled with 5 instances of 100 with indexes 0,1,2,3,4 respectively
    // container of size 5 with 5 instances of 100

    vector<int> v(5); // {0,0,0,0,0} 
    // a container of size 5 with 5 instances of 0 or any garbage value - depends on the compiler

    vector<int> v1(5,20); // {20,20,20,20,20}
    vector<int> v2(v1); // v2 will be a copy of v1, not the same one
    // i.e. another container of 5 instances of 20

    // Even if we declare a vector with its size, i.e. predefining the size, we can still increase it afterwards
    // If we push 1 into v of size 5, its size becomes 6 and 1 is pushed into v
    
    // Accessing elements in a vector:
    // if v is {23,45,65,76,12}
    
    // Similar to array:
    cout<<v[0]<<" "<<v.at(0); // 23

    // Accessing elements using iterator:
    // Iterator points to the memory where the element is lying.
    // Iterators return pointers to positions in the vector
    // We use them to traverse the container
    // Iterators are like smart pointers

    vector<int>::iterator it = v.begin(); // points to the memory address of 23

    // In order to access the element in a memory location , we use *
    // *(v.begin()) = 23
    it++; // As the elements are in contagious memory locations, not it points to the memory location of 2nd element i.e. 45
    cout<<*(it)<<" "; // 45

    it = it+2;
    cout<<*(it)<<" "; //76

    // Other iterators:
    vector<int>::iterator it = v.end(); // it points to the memory location just after the last element i.e. 12
    it--;
    cout<<*(it)<<" "; // 12
    vector<int>::reverse_iterator it = v.rend(); //just knowledge - never used
    // reverses the vector and points to the memory address just after the last element i.e. just after 23
    vector<int>::reverse_iterator it = v.rbegin(); //just knowledge - never used
    // reverses the vector and points to the memory address of first element i.e. 12
    // If we do it++ now, then it will point to the memory location of 76

    cout<<v.back(); // prints the last element of the vector
    // v.back() is just a member function of vector, also v.front()
    // v.begin(), v.end(), v.rbegin(), v.rend() are iterators
    
    // Printing entire vector using iterator:
    for(vector<int>::iterator it = v.begin(); it!=v.end();it++)
    {
        cout<<*(it)<<" ";
    }
    // To avoid writing such a long data type, we can also use auto:
    // 'auto' automatically detects the data type of any variable according to the value assigned to the variable
    // e.g. auto a = 5; it means the data type of a is int
    // so whenever we are not sure of the data type or want to use shortcut, we use auto

    for(auto it = v.begin(); it != v.end(); it++) //short and easy syntax
    { //automatically assigns it to a vector iterator
        cout<<*(it)<<" ";
    }

    // Another way to print elements in the vector:
    // For-each loop:
    for(auto it:v) // it is of int data type as the elements of v are integers
    {
        cout<<it<<" ";
    }
    
    // Deletion of a single element in a vector:

    //{10,20,12,23}
    v.erase(v.begin()+1); // {10,12,23}
    // .erase(address of the element to be deleted) i.e. .erase(iterator)

    // Deletion of multiple elements in a vector:
    // {10,20,12,23,35}
    v.erase(v.begin()+2, v.begin()+4); // {10,20,35} 
    // [start,end)
     
    // Insert function:

    // A single element
    vector<int> v(2,100); // {100,100}
    v.insert(v.begin(),300); // {300,100,100};

    // Multiple elements
    v.insert(v.begin()+1,2,10); // {300,10,10,100,100}

    // A vector into a vector - rarely used
    vector<int>copy(2,50); // {50,50}
    v.insert(v.begin(), copy.begin(), copy.end()); // {50,50,300,10,10,100,100}
    
    // Other important functions in a vector:

    // {10,20}
    cout<<v.size(); // 2

    // {10,20}
    v.pop_back(); // {10}

    // v1 -> {10,20}
    // v2 -> {30,40}
    v1.swap(v2); // v1 -> {30,40} , v2 -> {10,20}

    v.clear(); // erases the entire vector 
    // {} - trims it down to an empty vector

    cout<<v.empty(); // vector is empty or not
    // returns False if v contains atleast 1 element
    // returns True if v contains 0 elements

}    

void explainList(){
    // The only difference between list and vector is :
    // Lists give us front operations as well

    list<int> ls;
    ls.push_back(2); // {2}
    ls.emplace_back(4); // {2,4}

    // Front operations:
    ls.push_front(5); // {5,2,4}
    ls.emplace_front(); // {2,4}

    // In vectors we used insert() which takes a lot of time and is very costly
    // For vectors, the internal operation is a singly linked list

    // For lists, the internal operation is a doubly linked list
    // So push_front() is very cheap in terms of time complexity to a insert() in a vector

    // rest functions are same as vector
    // begin ,end, rbegin, rend, clear, insert, size, swap
}

void explainDeque(){
    deque<int> dq;
    dq.push_back(1);      // {1}
    dq.emplace_back(2);   // {1, 2}
    dq.push_front(4);     // {4, 1, 2}
    dq.emplace_front(3);  // {3, 4, 1, 2}

    dq.pop_back();        // {3, 4, 1}
    dq.pop_front();       // {4, 1}

    dq.back();            // returns 1
    dq.front();           // returns 4

    // rest functions same as vector
    // begin, end, rbegin, rend, clear, insert, size, swap
}

void explainStack(){
    // Last In First Out (LIFO)
    stack<int> st;
    st.push(1);      // {1}
    st.push(2);      // {2, 1}
    st.push(3);      // {3, 2, 1}
    st.push(3);      // {3, 3, 2, 1}
    st.emplace(5);   // {5, 3, 3, 2, 1}

    cout << st.top();    // prints 5 // no deletion
    // ** st[2] is invalid ** i.e. indexing is invalid in a stack

    st.pop();        // stack looks like {3, 3, 2, 1}

    cout << st.top();    // prints 3

    cout << st.size();   // prints 4

    cout << st.empty();  // prints 0 (false) or 1 (true)

    stack<int> st1, st2;
    st1.swap(st2);

    // In stack, all the operations i.e. push(), pop(), top() are O(1) operations
    // All operations take constant time
}

void explainQueue() {
    // similar to stack
    // First In First Out (FIFO)
    queue<int> q;
    q.push(1);      // {1}
    q.push(2);      // {1, 2}
    q.emplace(4);   // {1, 2, 4}

    q.back() += 5;  // now back becomes 4 + 5 = 9 → {1, 2, 9}
    cout << q.back();     // prints 9

    // Queue is {1, 2, 9}
    cout << q.front();    // prints 1

    q.pop();              // removes front → {2, 9}

    cout << q.front();    // prints 2

    // size, swap, empty are same as stack
    // All the operations are happening in constant time i.e. O(1)
}

void explainPQ() {
    // Priority - The largest element stays at the top:
    // can be any data type - int, double, char, string
    // In case of string, the lexicographically larger string comes at the top
    // lexicographically - dictionary wise
    
    // Max Heap
    priority_queue<int> pq; 

    // Not a linear data structure
    // A tree data structure

    pq.push(5);      // {5}
    pq.push(2);      // {5, 2}
    pq.push(8);      // {8, 5, 2}
    pq.emplace(10);  // {10, 8, 5, 2}

    cout << pq.top();    // prints 10

    pq.pop();            // now {8, 5, 2}

    cout << pq.top();    // prints 8
    
    // push, pop and top are main functions
    // size, swap, empty functions same as others

    // Minimum Heap
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(5);      // {5}
    pq.push(2);      // {2, 5}
    pq.push(8);      // {2, 5, 8}
    pq.emplace(10);  // {2, 5, 8, 10}

    cout << pq.top();    // prints 2


    // push(), pop() - O(log n)
    // top() - O(1)
}

void explainSet(){
    // stores everything in sorted order
    // stores only unique elements
    // not a linear container - a tree is maintained

    set<int> st;
    st.insert(1);     // {1}
    st.emplace(2);    // {1, 2}
    st.insert(2);     // still {1, 2}
    st.insert(4);     // {1, 2, 4}
    st.insert(3);     // {1, 2, 3, 4}

    // insert() and emplace() work in a similar fashion

    // Functionality of insert in vector
    // can also be used, that only increases efficiency

    // begin(), end(), rbegin(), rend(), size(),
    // empty(), and swap() are same as those of above

    // {1, 2, 3, 4, 5}
    auto it = st.find(3); // returns an iterator which points to the address of 3

    // {1, 2, 3, 4, 5}
    auto it = st.find(6);
    // If an element is not in the set, it will always return an iterator which points to just the next memory location after the last element of the set
    // i.e. it will return st.end()

    // {1, 4, 5}
    st.erase(5);    // .erase(element)  
    // erases 5 — takes logarithmic time

    int cnt = st.count(1);
    // If 1 exists, cnt=1, else cnt=0

    // {1,2,3,4,5}
    auto it = st.find(3);
    st.erase(it);  // .erase(iterator)   
    // erases 3 — takes constant time

    // Deletion of multiple elements:
    // {1, 2, 3, 4, 5}
    auto it1 = st.find(2);
    auto it2 = st.find(4);
    st.erase(it1, it2);  // after erase: {1, 4, 5} — [first, last)
    
    // size, empty, swap, begin, everything is similar to vector
    // lower_bound() and upper_bound() functions work in the same way
    // as in vector

    // This is the syntax:
    auto it = st.lower_bound(2);
    auto it = st.upper_bound(3);

    // In set, everything happens in O(log n)
}

void explainMultiSet() {
    // Everything is same as set
    // but stores duplicate elements also

    multiset<int> ms;
    ms.insert(1);           // {1}
    ms.insert(1);           // {1, 1}
    ms.insert(1);           // {1, 1, 1}

    ms.erase(1);            // all 1's erased 
    // When we say - delete element, it deletes all the occurences of that element

    int cnt = ms.count(1);  // counts number of 1's

    // only a single one erased
    ms.erase(ms.find(1));
    // When we say, delete the element in the iterator, it only deletes only the one element which the iterator points to

/*

ms.erase(ms.find(1), ms.find(1)+2); - wrong use

C++ set and multiset use bidirectional iterators,
not random-access iterators.
This means:

You can use ++it or --it

❌ You cannot do it + 2 
(that only works for vectors, arrays, etc.)

*/

    ms.erase(ms.find(1), std::next(ms.find(1), 2)); // correct use
    // std::next(it, n) advances the iterator it by n steps
    // To use std::next(), #include<iterator> needs to be written which is already included in #include<bits/stdc++.h>


    // rest all function same as set
}

void explainUSet() {
    unordered_set<int> st;

    // everything is similar to set, i.e.
    // it will have unique elements but it does not store in sorted order
    // it has randomized order

    // In most of the cases, the time complexity is O(1)

    // All the operations are similar to set
    // but only lower_bound and upper_bound functions do not work
    // it does not store in any particular order 
    // it has a better complexity than set in most cases,
    // except some when collision happens when the time complexity becomes O(n) - worst case, which happens once in a blue moon
}

void explainMap() {

    // Map is a container which stores everything in the 
    // form of: {key,value} pair
    // The keys are unique, values may not be.
    // The keys are in sorted order
    // The keys and values can be of any datatype (int, double, pair, etc)
    
    map<int, int> mpp; // key and value are integers
    map<int, pair<int, int>> mpp1; // key is integer, value is pair
    map<pair<int, int>, int> mpp2; // key is pair, value is integer

    mpp[1] = 2; // 1 is key, 2 is value, element is {1,2}
    mpp.emplace(3, 1); // 3 is key, 1 is value, element is {3,1}
    mpp.insert({2, 4}); // 2 is key, 4 is value, element is {2,4}
    mpp2[{2, 3}] = 10; // {2,3} is key, 10 is value, element is {{2,3},10}

    // As the keys are stored in sorted order:
    // So mpp will contain {1,2} then {2,4} then {3,1}
    // can be called sorted key order

    for (auto it : mpp) { // here 'it' becomes a pair data type
        // elements of mpp are stored in a pair
        cout << it.first << " " << it.second << endl; 
        // it.first is key and it.second is value
    }
    // We can also start from begin() iterator and go till just before the end() iterator to print the elements

    cout << mpp[1]; // 2
    cout << mpp[5]; // 0 or null

    auto it = mpp.find(3); // returns an iterator to the pair {3,1}
    cout<< (*it).second; // *it = {3,1}
    cout<< it->second; 
    // both are the same thing 
    // to access the value part of pair, the arrow operator '->' can be used
    
    auto it = mpp.find(5);
    // points to mpp.end()

    // This is the syntax:
    auto it = mpp.lower_bound(2);
    auto it = mpp.upper_bound(3);

    // erase, swap, size, empty are same as above
    // all operations are O(log n)
}

void explainMultiMap(){
    // everything same as map,
    // but multimap can store duplicate keys.
    // everything is in sorted order
    // for e.g. {1,2} is stored then {1,3}
     
    // only mpp[key] cannot be used here
}

void explainUnorderedMap(){
    // same as the difference between set and unordered set
    // i.e. it will not store in sorted order
    // randomized order but unique keys
    // all operations are O(1)
    // In worst case, once a blue moon, the time complexity is O(n)
}






