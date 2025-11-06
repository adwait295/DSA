#include<bits/stdc++.h>
using namespace std;

// Write a program that takes an input of age
// and prints if you are an adult or not.

int main(){

    int age;
    cin >> age;
    
    if(age>=18){
        cout << "You are an Adult"<<endl;
    }
    else{
        cout<<"You are not an Adult"<<endl;
    }

    // if and else if statements are independent of 
    // else statement. else statement is not mandatory
    // else if statement is dependent on if statement

    return 0;
}