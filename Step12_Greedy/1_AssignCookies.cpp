#include<bits/stdc++.h>
using namespace std;

// Brute force solution (My solution):

int findMaximumCookieStudents(vector<int>& Student, vector<int>& Cookie){
    int count = 0;
    for(int i=0;i<Student.size();i++){
        int min = INT_MAX, k = -1;
        for(int j=0;j<Cookie.size();j++){
            if(Cookie[j] >= Student[i] && Cookie[j] < min){
                min = Cookie[j];
                k = j;
            }
        }
        if(k != -1){
            Cookie[k] = 0;
            count++;
        }
    }
    return count;

    // T.C. = O(N * M), where N and M are sizes of Student & Cookie respectively.
    // S.C. = O(1)
}

// Optimal Solution:

int findMaximumCookieStudents(vector<int>& Student, vector<int>& Cookie){
    sort(Student.begin(), Student.end());
    sort(Cookie.begin(), Cookie.end());

    int student = 0, cookie = 0;
    while(student < Student.size() && cookie < Cookie.size()){
        if(Cookie[cookie] >= Student[student]){
            student++;
            cookie++;
        }
        else cookie++;
    }
    return student;

    // T.C. = O(N logN + M logM + min(N, M)), where N & M are sizes of Student and Cookie respectively.
    // S.C. = O(1)
}