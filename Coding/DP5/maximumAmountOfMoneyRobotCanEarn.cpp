// Leetcode 3418
#include<bits/stdc++.h>
using namespace std;
// Method 1 - Memoization but this gives TLE
class Solution {
public:
    int helper(vector<vector<int>>& coins, vector<vector<vector<int>>>& dp, int i, int j, int k){
        int m = coins.size();
        int n = coins[0].size();
        if(i<0 || i>m-1 || j<0 || j>n-1) return -1e9;
        if(i == m-1 && j == n-1){
            if(coins[i][j] < 0 && k < 2) return 0; // we try to skip that cell coins to maximize profit
            return coins[i][j];
        }
        if(k > 2) return -1e9; // imp
        int best = -1e9;
        if(dp[i][j][k] != -1) return dp[i][j][k];
        if(coins[i][j] >= 0){
            int down = coins[i][j] + helper(coins, dp, i+1, j, k);
            int right = coins[i][j] + helper(coins, dp, i, j+1, k);
            best = max(down, right);
        }
        else{
            int down = helper(coins, dp, i+1, j, k) + coins[i][j]; // coins already negative hai
            int right = helper(coins, dp, i, j+1, k) + coins[i][j];
            int take = max(down , right);
            int skip = -1e9;
            if(k < 2){ // if k >= 2 then we have take negative coins, we can't neutralize robber
                skip = max(helper(coins, dp, i+1, j, k+1), helper(coins, dp, i, j+1, k+1));
            }
            best = max(take, skip);
        }
        return dp[i][j][k] = best;
    }
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(3, -1)));
        return helper(coins, dp, 0, 0, 0);
    }
};
// Method 2 - Tabulation
class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(3, -1e9))); 
        // initialize with negative number
        for(int i = m-1; i>=0; i--){
            for(int j = n-1; j>=0; j--){
                for(int k = 0; k<=2; k++){
                    if(i == m-1 && j == n-1){
                        if(i<0 || i>m-1 || j<0 || j>n-1) dp[i][j][k] = -1e9;
                        if(i == m-1 && j == n-1){
                            if(coins[i][j] < 0 && k < 2){
                                dp[i][j][k] = 0; // we try to skip that cell coins to maximize profit
                            }
                            else dp[i][j][k] = coins[i][j];
                            continue;
                        }
                    }
                    int best = -1e9;
                    if(coins[i][j] >= 0){
                        int down = coins[i][j] + dp[i+1][j][k];
                        int right = coins[i][j] + dp[i][j+1][k];
                        best = max(down, right);
                    }
                    else{
                        int down = dp[i+1][j][k] + coins[i][j]; // coins already negative hai
                        int right = dp[i][j+1][k] + coins[i][j];
                        int take = max(down , right);
                        int skip = -1e9;
                        if(k < 2){ // if k >= 2 then we have take negative coins, we can't neutralize robber
                            skip = max(dp[i+1][j][k+1], dp[i][j+1][k+1]);
                        }
                        best = max(take, skip);
                    }
                    dp[i][j][k] = best;
                }
            }
        }
        return dp[0][0][0];
    }
};
int main(){
    
    return 0;
}