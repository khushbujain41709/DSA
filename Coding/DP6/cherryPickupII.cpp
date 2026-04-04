// Leetcode 1463
#include<bits/stdc++.h>
using namespace std;
// Method 1 - Memoization
// TC = O(3^n + 3^n)
// SC = O(m*n*n + n)
class Solution {
public:
    int helper(vector<vector<int>>& grid, int i, int j1, int j2, vector<vector<vector<int>>>& dp){
        int m = grid.size();
        int n = grid[0].size();
        if(j1 < 0 || j1 > n-1 || j2 < 0 || j2 > n-1) return -1e9;
        if(i == m-1){
            if(j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        // Not with INT_MIN as we can't add any negative value to it
        int maxx = 0;
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        for(int jdx1 = -1; jdx1<=1; jdx1++){
            for(int jdx2 = -1; jdx2<=1; jdx2++){
                if(j1 == j2){
                    maxx = max(maxx, grid[i][j1] + helper(grid, i+1, j1+jdx1, j2+jdx2, dp));
                }
                else{
                    maxx = max(maxx, grid[i][j1] + grid[i][j2] + helper(grid, i+1, j1+jdx1, j2+jdx2, dp));
                }
            }
        }
        return dp[i][j1][j2] = maxx;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(n+1, -1)));
        return helper(grid, 0, 0, n-1, dp);
    }
};
// Tabulation
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(n+1, 0)));
        // Base case: last row
        for(int j1 = 0; j1<n; j1++){
            for(int j2 = 0; j2<n; j2++){
                if(j1 == j2){
                    dp[m-1][j1][j2] = grid[m-1][j1];
                }
                else{
                    dp[m-1][j1][j2] = grid[m-1][j1] + grid[m-1][j2];
                }
            }
        }// Filling from bottom to top
        for(int i = m-2; i>=0; i--){
            for(int j1 = 0; j1<n; j1++){
                for(int j2 = 0; j2<n; j2++){
                    int maxx = -1e9;
                    for(int jdx1 = -1; jdx1<=1; jdx1++){
                        for(int jdx2 = -1; jdx2<=1; jdx2++){
                            int nj1 = j1 + jdx1;
                            int nj2 = j2 + jdx2;
                            if(nj1 >= 0 && nj1 < n && nj2 >= 0 && nj2 < n){
                                if(j1 == j2){
                                    maxx = max(maxx, grid[i][j1] + dp[i+1][nj1][nj2]);
                                }
                                else{
                                    maxx = max(maxx, grid[i][j1] + grid[i][j2] + dp[i+1][nj1][nj2]);
                                }
                            }
                        }
                    }
                    dp[i][j1][j2] = maxx;
                }
            }
        }
        return dp[0][0][n-1]; // ALice at 0 column and bob at n-1 column
    }
};
int main(){
    
    return 0;
}