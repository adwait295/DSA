#include<bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool lemonadeChange(vector<int>& bills) {
        int change5 = 0, change10 = 0;
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5)
                change5++;
            else if (bills[i] == 10) {
                if (change5 >= 1) {
                    change10++;
                    change5--;
                } else
                    return false;
            } else {
                if (change10 >= 1 && change5 >= 1) {
                    change10--;
                    change5--;
                } else if (change10 == 0 && change5 >= 3) {
                    change5 -= 3;
                } else
                    return false;
            }
        }
        return true;
    }
};

int main() {
    vector<int> bills = {5, 5, 5, 10, 20};
    cout << "Queues of customers: ";
    for (int bill : bills) {
        cout << bill << " ";
    }
    cout << endl;
    Solution solution;
    bool ans = solution.lemonadeChange(bills);
    if (ans)
        cout << "It is possible to provide change for all customers." << endl;
    else
        cout << "It is not possible to provide change for all customers." << endl;
    return 0;
}