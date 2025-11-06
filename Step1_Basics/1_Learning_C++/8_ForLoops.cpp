#include<bits/stdc++.h>
using namespace std;

int main(){

    int i;
    for(i=1; i<=5; i++){
        cout<<"Adwait"<< endl;
    }
    cout << i; //scope of i is possible here because we
    //declared it outside for loop.
    //if we had declared it inside for loop then we couldn't
    //have printed the value of i outside the for loop
    return 0;
}