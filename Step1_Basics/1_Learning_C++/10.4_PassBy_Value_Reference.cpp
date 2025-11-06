#include<bits/stdc++.h>
using namespace std;

// pass by value - get the copy
void doSomething(int num, string s) { // takes the copy and modifies it
    cout << num << endl;
    num += 5; //dealing with copy
    cout << num << endl;
    num += 5;
    cout << num << endl;
    s[0]='4'; //dealing with copy
    cout << s << endl;
    cout << "\n";
}

// pass by reference - get it from the address/get the original value
void doOtherthing(int &num, string &s){
    num += 10; //dealing with original
    cout << num << endl;

    s[0]='x'; //dealing with original
    cout << s << endl;

    cout << "\n";
}

void dolastthing(int arr[], int n){
    arr[0] +=100;
    cout << "Value inside function: " << arr[0] << endl;
}

int main() {
    int num = 10;
    string name = "Adwait";
    doSomething(num,name); // a copy goes, not the original number or string
    // the original number num and string name must be somewhere in the memory
    // that number and that string did not go. A copy of it went.
    
    doOtherthing(num,name); // it takes the address, it takes the original and sends it
    cout << num << endl;
    cout << name << endl;  


    // no change occurs to original values in pass by value
    // changes occur to original values in pass by reference
    
    // arrays are always generically passed by reference.
    // no need to use &
    // but apart from arrays, other things i.e. vectors,
    // maps, lists, everything, we have to use & to make
    // sure it is passed by reference
    
    cout << "\n";
    int n=5;
    int arr[n];
    for(int i=1;i<n;i++){
        cin >> arr[i];
    }
    dolastthing(arr,n);
    cout << "Value inside main(): " << arr[0] << endl;

    return 0;
}