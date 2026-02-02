#include<bits/stdc++.h>
using namespace std;

// My solution
class ArrayStack1 {
    public: 
    int arr[100];
    int top1;
public:
    ArrayStack1() {
        top1 = -1;
    }
    
    void push(int x) {
        if(top1 == 99) return;
        else{
            arr[++top1] = x;
        }
    }
    
    int pop() {
        if(top1 == -1) return -1;
        return arr[top1--];
    }
    
    int top() {
        if(top1 == -1) return -1;
        return arr[top1];
    }
    
    bool isEmpty() {
        if(top1 == -1) return true;
        return false;
    }
};

// Editorial solution:

class ArrayStack{

    private:
    int* stackArray;
    int capacity;
    int topIndex;

    public:

    ArrayStack(int size = 100){
        capacity = size;
        stackArray = new int[capacity];
        topIndex = -1;
    }

    ~ArrayStack(){
        delete[] stackArray;
    }

    void push(int x){
        if(topIndex >= capacity-1){
            cout << "Stack is full" << endl;
            return;
        }
        stackArray[++topIndex] = x;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1; 
        }
        return stackArray[topIndex--];
    }

    int top() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1; 
        }
        return stackArray[topIndex];
    }

    bool isEmpty() {
        return topIndex == -1;
    }
};

int main() {
    ArrayStack stack;
    vector<string> commands = {"ArrayStack", "push", "push", "top", "pop", "isEmpty"};
    vector<vector<int>> inputs = {{}, {5}, {10}, {}, {}, {}};

    for (size_t i = 0; i < commands.size(); ++i) {
        if (commands[i] == "push") {
            stack.push(inputs[i][0]);
            cout << "null ";
        } else if (commands[i] == "pop") {
            cout << stack.pop() << " ";
        } else if (commands[i] == "top") {
            cout << stack.top() << " ";
        } else if (commands[i] == "isEmpty") {
            cout << (stack.isEmpty() ? "true" : "false") << " ";
        } else if (commands[i] == "ArrayStack") {
            cout << "null ";
        }
    }

    return 0;
}