#include<bits/stdc++.h>
using namespace std;

int linearSearch(vector<int>& nums, int target){
    int size = nums.size();
    for(int i=0;i<size;i++)
    {
        if(nums[i] == target) return i;
    }
    return -1;
}

int main(){
    int size;
    cin >> size;
    vector<int> arr;
    for(int i=1;i<=size;i++)
    {
        int n;
        cin >> n;
        arr.push_back(n);
    } 
    int target;
    cin >> target;
    cout << linearSearch(arr,target) << endl;

    return 0;
}