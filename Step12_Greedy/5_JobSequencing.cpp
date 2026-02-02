#include<bits/stdc++.h>
using namespace std;

class Solution{  
  public: 
    
    // This bool 'comp' function should be static because sort() expects comp to either of the three: a free function or a static function or a lambda function. Study more and dive deep into about it.
    bool static comp(vector<int> &a,vector<int> &b){ // Comparator
      if(a[2] > b[2]) return true;
      return false;
    }

    vector<int> JobScheduling(vector<vector<int>>& Jobs) { 
      sort(Jobs.begin(), Jobs.end(), comp);
      // for(auto it: Jobs) cout << it[2] << endl;

      int maxDeadline = -1, count = 0, totalProfit = 0;

      for(int i=0;i<Jobs.size();i++) maxDeadline = max(maxDeadline, Jobs[i][1]);
      // cout << maxDeadline << endl;

      vector<int> hash(maxDeadline, -1);
      
      for(int i=0;i<Jobs.size();i++){ // O(n)
        for(int j=Jobs[i][1]-1;j>=0;j--){ // O(maxDeadline) -> This can be optimized to O(1) by using DSU (Disjoint Set Union) instead of looping, while studying graphs; But it is not required in an interview for this question. 
          if(hash[j] == -1){
            totalProfit += Jobs[i][2];
            count++;
            hash[j] = Jobs[i][2];
            break;
          }
        }
      }
      return {count, totalProfit};
    } 

    // T.C. = O(n log n + n^2)
    // S.C. = O(n)
};