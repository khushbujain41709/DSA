// Leetcode 45
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
// Method 1 - Using Dynamic Programming
class Solution {
public:
    int helper(int idx, vector<int>& nums, vector<int>& dp){
        int n = nums.size();
        if(idx >= n-1) return 0;
        if(dp[idx] != -1) return dp[idx];
        int count = 1e9;
        for(int i = 1; i<=nums[idx]; i++){
            count = min(count, 1+helper(idx+i, nums, dp));
        }
        return dp[idx] = count;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return helper(0, nums, dp);
    }
};

// Method 2 - Using Greedy
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int jumps = 0;
        while(r<n-1){ // when we reach r == n-1 so no need to run loop
            int farthest = INT_MIN;
            for(int i = l; i<=r; i++){
                farthest = max(farthest, nums[i]+i); // farthest mtlb uss range l to r ke har element kitna dur ja skte hai. Hum yaha new range create krna chahte hai. Har element apni value jitna dur jayege from index i.
            }
            l = r+1;
            r = farthest;
            jumps++;
        }
        return jumps;
    }
};
int main(){
    
    return 0;
}