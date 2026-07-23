// Leetcode 120
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
// Use DP but Greedy as [[-1],[2,3],[1,-1,-3]] expected output is -1 but our code gives -2
int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    int sum = 0;
    for(int i = 0; i<n; i++){
        int minn = INT_MAX;
        for(int j = 0; j<triangle[i].size(); j++){
            minn = min(minn, triangle[i][j]);
        }
        sum += minn;
    }
    return sum;
}
// Gives TLE using memoization
vector<vector<int>> dp;
int solveTriangle(vector<vector<int>>& triangle, int n, int i, int j){
    if (i == n - 1) return triangle[i][j];
    if(dp[i][j] != -1) return dp[i][j];
    int down = solveTriangle(triangle, n, i+1, j);
    int diag = solveTriangle(triangle, n, i+1, j+1);
    return dp[i][j] = triangle[i][j] + min(down, diag);
}
int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    dp.clear();
    dp.resize(n, vector<int>(n,-1));
    int sum = solveTriangle(triangle, n, 0, 0);
    return sum;
}
int main(){
    return 0;
}