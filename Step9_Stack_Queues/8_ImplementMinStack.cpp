#include<bits/stdc++.h>
using namespace std;

class MinStack {
   private:
    stack<pair<int, int>> st;

   public:
    MinStack() {}

    void push(int value) {
      if(st.empty()) st.push({value, value});
      else st.push({value, min(getMin(), value)});
    }

    void pop() {
      st.pop();
    }

    int top() {
      return st.top().first;
    }

    int getMin() {
      return st.top().second;
    }
};

class MinStack{
    private:
    stack<int> st;
    int mini;

    public:
    MinStack(){}

    void push(int val){
        if(st.empty()){
            st.push(val);
            mini = val;
            return;
        }
        if(val > mini) st.push(val);
        else{
            st.push(2*val - mini);
            mini = val;
        }
    }

    void pop(){
        if(st.empty()) return;

        if(st.top() > mini) st.pop();
        else{
            int elem = st.top();
            st.pop();
            mini = 2*mini - elem;
        }
    }

    int top(){
        if(st.empty()) return -1;
        if(st.top() < mini) return mini;
        else return st.top();
    }

    int getMin(){
        return mini;
    }
};