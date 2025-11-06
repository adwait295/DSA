#include<bits/stdc++.h>
using namespace std;
/*
Take the day no and print the corresponding day
for 1 print Monday,
for 2 print Tuesday and so on for 7 print Sunday.
*/
int main(){

    int day;
    cin >> day;

    switch(day){
        case 1:
            cout<<"Monday";
            break;
        case 2:
            cout<<"Tuesday";
            break;
        case 3:
            cout<<"Wednesday";
            break;
        case 4:
            cout<<"Thursday";
            break;
        case 5:
            cout<<"Friday";
            break;
        case 6:
            cout<<"Saturday";
            break;
        case 7:
            cout<<"Sunday";
            break;
        default:
            cout<<"Invalid day input";
            break;
        cout<<"Check if the control is coming here";    
    }
    cout<<"\ncheck";
    return 0;

    //break statement takes you out of all the conditional
    //statements above it. 
    //cases are conditional statements as well as the switch
    //statement. so it takes the control out of both of them
    //and prints check after coming out.
}