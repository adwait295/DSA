#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int i = 1;
    while(i<=5){
        cout<<"Adwait " << i << endl;
        i=i+1;
    }

    /*Whenever we are writing code in industry or maybe
    solving a problem, a lot of times the condition might
    be user dependent or we might have such use-cases.
    So we always want one thing i.e. we want our line of
    code to be executed minimum once
    
    So we write a do-while loop
    */
   cout<<"\n";
   i=45;
   do{
    cout<<"Adwait "<< i <<endl; //this line will get 
    //executed irrespective of the condition we are giving
    i+=1;
   }while(i<=1);
   cout << i;

    return 0;
}