#include<bits/stdc++.h>
using namespace std;

int main(){
    string s = "Adwait"; //characters at every index of the string array
    int len = s.size(); // or s.length()
    s[0] = '4';
    cout << s[0]; // "" cannot be used here because
    // string is an array of CHARACTERS
    cout << s[len-1];
    return 0;
}