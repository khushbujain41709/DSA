// https://www.geeksforgeeks.org/problems/geek-jump/1
#include<bits/stdc++.h>
using namespace std;
// Method 1 - Memoization
class Solution {
  public:
    int f(vector<int>& dp, vector<int>& height, int idx){
    int n = height.size();
        if(idx == n-1){
            return dp[idx] = 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        int one = abs(height[idx+1] - height[idx]) + f(dp, height, idx+1);
        int two = INT_MAX;
        if(idx+2 < n) two = abs(height[idx+2] - height[idx]) + f(dp, height, idx+2);
        return dp[idx] = min(one, two);
    }
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n+1, -1);
        return f(dp, height, 0);
    }
};
// Method 2 - Tabulation
int minCost(vector<int>& height){
    int n = height.size();
    vector<int> dp(n, 0);
    dp[0] = 0;
    for(int i = 1; i<n; i++){
        int first = dp[i-1] + abs(height[i] - height[i-1]);
        int second = INT_MAX;
        if(i > 1){
            second = dp[i-2] + abs(height[i] - height[i-2]);
        }
        dp[i] = min(first, second);
    }
    return dp[n-1];
}
// Method 3 - Space Optimization
int minCost(vector<int>& height) {
    int n = height.size();
    int curr = 0;
    int prev2 = 0;
    int prev1 = 0;
    for(int i = 1; i<n; i++){
        int first = prev1 + abs(height[i] - height[i-1]);
        int second = INT_MAX;
        if(i > 1){
            second = prev2 + abs(height[i] - height[i-2]);
        }
        curr = min(first, second);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1; // curr will be at i = n so prev1 will be at i = n-1
}
int main(){
    
    return 0;
}