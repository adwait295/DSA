#include<bits/stdc++.h>
using namespace std;

int maxScore(vector<int>& cardPoints , int k){
    int sum = 0, maxSum = 0, size = cardPoints.size();

   for(int i=0;i<k;i++) sum += cardPoints[i];
   maxSum = sum;


   int leftIndex = k-1, rightIndex = size - 1;
   while(rightIndex >= size - k){
    sum += cardPoints[rightIndex];
    rightIndex --;
    sum -= cardPoints[leftIndex];
    leftIndex --;
    maxSum = max(maxSum, sum);
   } 
   return maxSum;
}