// Same issue: In Brute force approach
// For Q search queries, the T.C. = O(Q*n), where n is the size of the string

// Character Hashing can also be done with the help of arrays.

// Assuming that all characters in the string are lowercase only,
// the hash array will contain 26 elements starting from index 0 till 25
// The indexes can be linked to a-z by ASCII characters
// ch - 'a' i.e. ch - 97 as subtraction is only possible between numbers
// ASCII value of ch - ASCII value of 'a'

// If we have uppercase and special characters too, then as we know
// there are only 256 characters in total in ASCII.
// so we can directly define a hash array of size 256 and store
// the frequencies of any character that appears in the string
// and we need not even subtract the ASCII values now which we did in the previous case of only lowercase characters 
// because every character will be at its index position same as its ASCII value
// i.e. a at 97 , A at 65, etc.

// int x = 'a'; here it won't give a syntax error, rather it will do type casting.
// x = 97

#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    // Pre compute:
    int hash[26] = {0};

    // if we dont know for sure that all are lowercase letters
    // then we take hash[256] = {0}

    for(int i=0;i<s.size();i++)
    {
        hash[s[i]-'a'] ++; // as hash needs an integer as its index, so s[i] is automatically casted to its ASCII value
        // hash[s[i]] when hash[256] is taken
    }

    int Q;
    cin >> Q;
    while(Q--)
    {
        char c;
        cin >> c;
        // Fetch:
        cout << hash[c-'a'] << endl; 
        // hash[c] when hash[256] is taken
    }
    return 0;
}

// ch-'a' for only lowercase: hash[26]
// ch-'A' for only uppercase: hash[26]
// For all characters: hash[256] and no subtraction

// As there are only 256 characters possible which is well within the size of int array indexes possible
// we do not have any problem of limits as we did in number hashing.
// So always prefer arrays for character hashing.


// Maps can also be used for character hashing.
// mpp<char,int>
// mpp[s[i]] does not get converted into corresponding 
// ASCII value because character keys are stored in mpp