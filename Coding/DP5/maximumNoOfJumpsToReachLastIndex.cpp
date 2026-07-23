// Leetcode 2770 
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int helper(vector<int>& nums, vector<int>& dp, int target, int idx){
        int n = nums.size();
        if(idx == n-1) return 0;
        if(dp[idx] != -1) return dp[idx];
        int ans = INT_MIN;
        for(int j = idx+1; j<n; j++){
            if(abs(nums[idx] - nums[j]) <= target){
                int next = helper(nums, dp, target, j);
                if(next != INT_MIN){
                    ans = max(ans, 1 + next);
                }
            }
        }
        return dp[idx] = ans;
    }
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        int ans = helper(nums, dp, target, 0);
        if(ans == INT_MIN) return -1;
        else return ans;
    }
};
int main(){
    
    return 0;
}