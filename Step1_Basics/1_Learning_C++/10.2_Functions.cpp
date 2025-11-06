#include<bits/stdc++.h>
using namespace std;

// Take two numbers and print their sum

int sum(int num1, int num2) { //any number of parameters can be taken and multiple datatypes can be used
    int num3 = num1 + num2;
    return num3;
}

/*The return type of a function can be anything.
i.e. a function can return integer, double, long long,
string, array (1D,2D,anything), vector, list,
can be anything*/

int main() {
    int num1, num2;
    cin >> num1 >> num2;
    int res = sum(num1, num2);
    cout << res;
    return 0;
}