// Leetcode 120
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int helper(vector<vector<int>>& triangle, int idx, int j, vector<vector<int>>& dp){
        int n = triangle.size();
        if(idx == n){
            return 0;
        }
        if(dp[idx][j] != -1e9) return dp[idx][j];
        int points = triangle[idx][j] + min(helper(triangle, idx+1, j, dp), helper(triangle, idx+1, j+1, dp));
        return dp[idx][j] = points;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1e9)); 
        // as -10^4 <= triangle[i][j] <= 10^4
        return helper(triangle, 0, 0, dp);
    }
};

// Method 2 - More optimized - Tabulation with space optimization
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n+1, 0);
        for(int i = 0; i<n; i++){
            dp[i] = triangle[n-1][i];
        }
        for(int i = n-2; i>=0; i--){
            vector<int> cur(n);
            for(int j = i; j>=0; j--){
                cur[j] = triangle[i][j] + min(dp[j], dp[j+1]);
            }
            dp = cur;
        }
        return dp[0];
    }
};
int main(){
    
    return 0;
}