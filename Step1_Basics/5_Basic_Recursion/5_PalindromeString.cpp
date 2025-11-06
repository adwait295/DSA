#include<bits/stdc++.h>
using namespace std;

bool Palindrome(int i, string &s){ // Functional Recursion
    
    // Single Pointer method:
    if(i >= s.size()/2)
    return true;

    // Instead of reversing the string, we can check the corresponding elements from first and last are same or not
    if(s[i] != s[s.size()-i-1])
    return false;

    return Palindrome(i+1,s); // If we write simply Palindrome(i+1,s) without return in this line, still it works perfectly. How??

    // T.C. = O(n/2)
    // S.C. = O(n/2) Auxillary Stack Space
}

int main(){
 
    string s; // We can also do with character array
    cin >> s;

    if(Palindrome(0,s) == true)
    cout << "Palindrome" << endl;
    else
    cout << "Not a Palindrome" << endl;

    return 0;

}