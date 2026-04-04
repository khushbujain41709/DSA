// Leetcode 416
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> dp;
bool helper(vector<int>& nums, int target, int idx , int sum){
    int n = nums.size();
    if(idx == n){
        if(sum == target) return true; 
        else return false;
    }
    if(dp[idx][sum] != -1) return dp[idx][sum];
    if(sum == target) return dp[idx][sum] = true; // agar end tak aane se pehle sum target k equal ho jaye
    if(sum + nums[idx] > target) return dp[idx][sum] = helper(nums, target, idx + 1, sum);
    bool take = helper(nums, target, idx + 1, sum + nums[idx]);
    bool leave = helper(nums, target, idx + 1, sum);
    return dp[idx][sum] = take || leave;
}
bool canPartition(vector<int>& nums) {
    int target = 0;
    int n = nums.size();
    for(int i = 0; i< n; i++){
        target += nums[i];
    }
    if(target % 2 != 0) return false;
    target /= 2;
    dp.clear();
    // idx from 0 to n-1 and sum from 0 to target 
    dp.resize(n, vector<int> (target + 1, -1));
    return helper(nums, target, 0, 0);
}
// Using Subset sum equals to K from DP6
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> dp(k+1), curr(k+1);
    dp[0] = true;
    curr[0] = true;
    // dp size = k+1 so If arr[0] > k, then: dp[arr[0]] will go out of bounds
    if(arr[0] <= k){
        dp[arr[0]] = true;
    }
    for(int i = 1; i<n; i++){
        for(int j = 1; j<=k; j++){
            bool take = 0;
            if(j >= arr[i]){
                take = dp[j-arr[i]];
            } 
            bool notTake = dp[j];
            curr[j] = take || notTake;
        }
        dp = curr;
    }
    return dp[k];
}
bool canPartition(vector<int>& nums) {
    // if there exists a subset with sum -> s/2 then remaining subsets will definitely have s/2 sum.
    int n = nums.size();
    int s = 0;
    for(int i = 0; i<n; i++){
        s += nums[i];
    }
    if(s % 2 != 0) return false;
    return subsetSumToK(n, s/2, nums);
}
int main(){
    
    return 0;
}