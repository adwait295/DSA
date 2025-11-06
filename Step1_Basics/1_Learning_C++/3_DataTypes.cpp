#include<bits/stdc++.h>
using namespace std;

int main(){

    // int
    int x;
    cin>>x;
    x= 5;
    cout<<x<<endl;

    //long long
    long long y = 599999999;
    cout<<y<<endl;

    // float, double
    float m = 4.333;
    double n = 4;
    cout<<m<<endl<<n<<endl;

    // string
    string s1;
    string s2;
    cin>>s1>>s2;
    cout<<s1<<" "<<s2<<endl;

    //getline
    cin.ignore();
    string str;
    getline(cin, str);
    cout<<str<<endl;

    //cin.ignore();
    string str1;
    getline(cin, str1);
    cout<<str1<<endl;

    // char (All 256 characters of the English alphabet 
    // can be inputted using char datatype)
    char ch;
    char ch1 = 'g';
    cin >> ch;
    cout << ch << " " << ch1 << endl;

    // We can but we dont use string to store single 
    // characters because it consumes more space.

    return 0;
}