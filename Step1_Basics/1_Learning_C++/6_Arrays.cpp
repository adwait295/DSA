#include<bits/stdc++.h>
using namespace std;
int main(){

    //int a,b,c,d;
    //cin >> a >> b >> c >> d;
    //cout << a << b << c << d;

    int arr[4]; //data types should be constant
    //if we give floating inputs in between, it will trim
    //and take the integer part only
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];

    //array elements are stored in consecutive memory 
    //addresses but we are not sure of the exact location
    // of the first array element (any randomized location)
    //we just know all elements are stored consecutively
    cout << arr[3] <<endl;

    arr[3] += 6;
    arr[2] = 18;

    cout << arr[3] << endl << arr[2] <<endl;
    //for the locations of the array not assigned
    //they will be assigning themselves some garbage values
    //every time we print even the same non-assigned element
    //it will print a random new garbage value(-ve/+ve)

    int arr1[2][4];
    arr1[1][0] = 5;
    cout<<arr1[1][0]<<endl;
    cout<<arr1[1][1];
    return 0;
}