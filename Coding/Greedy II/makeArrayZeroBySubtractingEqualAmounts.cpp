// Leetcode 2357
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int minimumOperations(vector<int>& nums) {
    int n = nums.size();
    int count = 0;
    while(true){
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i<n; i++){
            if(nums[i] != 0){
                pq.push(nums[i]);
            }
        }
        if(pq.empty()) return count;
        int minn = pq.top();
        for(int i = 0; i<n; i++){
            if(nums[i] != 0){
                nums[i] -= minn;
            }
        }
        count++;
    }
    return count;
}
int main(){
    
    return 0;
}