// Leetcode 1005
#include<bits/stdc++.h>
using namespace std;
int largestSumAfterKNegations(vector<int>& nums, int k) {
    int n = nums.size();
    int sum = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i<n; i++){
        pq.push(nums[i]);
        sum += nums[i];
    }
    while(k --){
        int x = pq.top();
        pq.pop();
        if(x == 0){ // smallest element is zero and all others elements are positive numbers
            return sum;
        }
        else{
            sum -= x;
            pq.push(-x);
            sum += (-x);
        }
    }
    return sum;
}
int main(){
    
    return 0;
}