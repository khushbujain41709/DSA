// Leetcode 3637
#include<iostream>
#include<vector>
using namespace std;
bool isInc(vector<int>& nums, int i, int j){
    for(int idx = i; idx<j; idx++){
        if(nums[idx] >= nums[idx+1]){
            return false;
        }
    }
    return true;
}
bool isDec(vector<int>& nums, int i, int j){
    if(i == 0 || j == nums.size() - 1){ 
        // first element increasing sequence mei hona chahiye
        // last element bhi increasing sequence mei hona chahiye
        return false;
    }
    for(int idx = i; idx<j; idx++){
        if(nums[idx] <= nums[idx+1]){
            return false;
        }
    }
    return true;
}
bool isTrionic(vector<int>& nums) {
    int n = nums.size();
    int p = n-1; // as nums = [1,2,3] then after iteration p = n-1
    int q = 0; // as nums = [5,4,3,2] then after iteration q = 0;
    for(int i = 0; i<n-1; i++){
        if(p == n-1 && nums[i] >= nums[i+1]){
            p = i;
        }
    }
    for(int i = p; i<n-1; i++){
        if(q == 0 && nums[i] <= nums[i+1]){
            q = i;
        }
    }
    if(p < q){
        if(!isInc(nums, 0, p)){
            return false;
        }
        if(!isDec(nums, p, q)){
            return false;
        }
        if(!isInc(nums, q, n-1)){
            return false;
        }
    }
    else return false; // when p >= q
    return true;
}
int main(){
    
    return 0;
}