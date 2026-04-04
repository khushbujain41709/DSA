// Leetcode 2304
#include<bits/stdc++.h>
using namespace std;
int helper(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& moveCost, vector<vector<int>>& dp){
    int m = grid.size();
    int n = grid[0].size();
    if(dp[i][j] != -1) return dp[i][j];
    if(i == m-1) return grid[i][j];
    int mini = INT_MAX;
    int val = grid[i][j];
    for(int idx = 0; idx<n; idx++){ // traverse every column in below row
        vector<int> v = moveCost[val];
        int cost = val + v[idx] + helper(i+1, idx, grid, moveCost, dp);
        mini = min(mini, cost);
    }
    return dp[i][j] = mini;
}
int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
    int ans = INT_MAX;
    for(int i =0; i<n; i++){
        ans = min(ans, helper(0, i, grid, moveCost, dp)); 
        // Try every column first cell.
    }
    return ans;
}
int main(){
    
    return 0;
}