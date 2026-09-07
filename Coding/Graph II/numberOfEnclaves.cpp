// Leetcode 1020
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid, set<pair<int, int>>& vis){
        int m = grid.size();
        int n = grid[0].size();
        vis.insert({i, j});
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        for(int x = 0; x<4; x++){
            int nr = i + dx[x];
            int nc = j + dy[x];
            if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1 && !vis.count({nr, nc})){
                dfs(nr, nc, grid, vis);
            }
        }
        return;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        set<pair<int, int>> vis;
        for(int i = 0; i<n; i++){
            if(grid[0][i] == 1 && !vis.count({0,i})){
                dfs(0, i, grid, vis);
            }
        }
        for(int i = 0; i<m; i++){
            if(grid[i][0] == 1 && !vis.count({i,0})){
                dfs(i, 0, grid, vis);
            }
        }
        for(int i = 0; i<n; i++){
            if(grid[m-1][i] == 1 && !vis.count({m-1,i})){
                dfs(m-1, i, grid, vis);
            }
        }
        for(int i = 0; i<m; i++){
            if(grid[i][n-1] == 1 && !vis.count({i, n-1})){
                dfs(i, n-1, grid, vis);
            }
        }
        int cnt = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(!vis.count({i,j}) && grid[i][j] == 1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
int main(){
    
    return 0;
}