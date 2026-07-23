// Leetcode 931
#include<bits/stdc++.h>
using namespace std;
// Method 1
class Solution {
public:
    int helper(vector<vector<int>>& matrix, vector<vector<int>>& dp, int idx, int jdx){
        int n = matrix.size();
        if(idx == n) return 0;
        // if(idx == n-1) return matrix[idx][jdx];
        if(dp[idx][jdx] != 1e9) return dp[idx][jdx];
        int points = 0;
        if(jdx == 0){
            points = matrix[idx][jdx] + min(helper(matrix, dp, idx+1, jdx+1), helper(matrix, dp, idx+1, jdx));
        }
        else if(jdx == n-1){
            points = matrix[idx][jdx] + min(helper(matrix, dp, idx+1, jdx-1), helper(matrix, dp, idx+1, jdx));
        }
        else points = matrix[idx][jdx] + min(helper(matrix, dp, idx+1, jdx), min(helper(matrix, dp, idx+1, jdx+1), helper(matrix, dp, idx+1, jdx-1)));
        return dp[idx][jdx] = points;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 1e9));
        int ans = INT_MAX;
        for(int i = 0; i<n; i++){
            ans = min(ans, helper(matrix, dp, 0, i));
        }
        return ans;
    }
};
// Method 2 - Tabulation
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i<n; i++){
            dp[0][i] = matrix[0][i];
        }
        for(int i = 1; i<n; i++){
            for(int j = 0; j<n; j++){
                if(j == n-1) dp[i][j] = matrix[i][j] + min(dp[i-1][j-1], dp[i-1][j]);
                else if(j == 0) dp[i][j] = matrix[i][j] + min(dp[i-1][j+1], dp[i-1][j]);
                else dp[i][j] = matrix[i][j] + min(dp[i-1][j-1], min(dp[i-1][j+1], dp[i-1][j]));
            }
        }
        int ans = INT_MAX;
        for(int i = 0; i<n; i++){
            ans = min(ans, dp[n-1][i]);
        }
        return ans;
    }
};
// Method 3 - Tabulation with space optimization
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> dp(n,0);
        for(int i = 0; i<n; i++){
            dp[i] = matrix[0][i];
        }
        for(int i = 1; i<n; i++){
            vector<int> cur(n);
            for(int j = 0; j<n; j++){
                if(j == n-1) cur[j] = matrix[i][j] + min(dp[j-1], dp[j]);
                else if(j == 0) cur[j] = matrix[i][j] + min(dp[j+1], dp[j]);
                else cur[j] = matrix[i][j] + min(dp[j-1], min(dp[j+1], dp[j]));
            }
            dp = cur;
        }
        int ans = INT_MAX;
        for(int i = 0; i<n; i++){
            ans = min(ans, dp[i]);
        }
        return ans;
    }
};
int main(){
    
    return 0;
}