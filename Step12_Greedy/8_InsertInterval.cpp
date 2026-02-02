#include<bits/stdc++.h>
using namespace std;

// My solution: A different & edgy approach.

vector<vector<int>> insertNewInterval(vector<vector<int>>& Intervals, vector<int>& newInterval) {
    int size = Intervals.size(), index = -1;

    for (int i = 0; i < size; i++){
        if (Intervals[i][0] > newInterval[0]){
            Intervals.insert(Intervals.begin() + i, newInterval);
            index = i;
            break;
        }    
    }
    if(index == -1){
        Intervals.push_back(newInterval);
        index = size;
    }
    size++;
    // for (auto it : Intervals) cout << it[0] << " " << it[1] << endl;
    for(int i=index;i<size;i++){
        if(i != 0 && Intervals[i][0] <= Intervals[i-1][1]){
            Intervals[i-1][1] = max(Intervals[i][1], Intervals[i-1][1]);
            Intervals.erase(Intervals.begin()+i);
            size--;
            i--;
        }
        else if(((i+1) != size) && Intervals[i][1] >= Intervals[i+1][0]){
            Intervals[i][1] = max(Intervals[i][1], Intervals[i+1][1]);
            Intervals.erase(Intervals.begin()+i+1);
            size--;
        }
        else break;
    }
    return Intervals;

    // T.C. = O(n)
    // S.C. = O(1)
}

// Striver's solution : A simpler & clearer approach with the same idea.

vector<vector<int>> insertNewInterval(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
    vector<vector<int>> res; 

    int i = 0; 
    int n = intervals.size(); 
        
    while(i < n && intervals[i][1] < newInterval[0]){
        res.push_back(intervals[i]); 
        i = i + 1; 
    }

    while(i < n && intervals[i][0] <= newInterval[1]){
        newInterval[0] = min(newInterval[0], intervals[i][0]); 
        newInterval[1] = max(newInterval[1], intervals[i][1]); 
        i = i + 1; 
    }
        
    res.push_back(newInterval); 
            
    while(i < n){
        res.push_back(intervals[i]); 
        i = i + 1; 
    }
        
    return res; 

    // T.C. = O(n)
    // S.C. = O(1), res is used just to return the answer vector. 
}