// Leetcode 692 - Premium
// https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1
// Store elements pair in a set but subtract each element with its base element before storing
// Remember to follow the same order of direction throughout the code
// Both shapes are the same, but DFS can start at different positions and the order in which DFS visits cells can differ.
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    set<pair<int, int>> vis;
    set<vector<pair<int, int>>> shape;
    void dfs(int i, int j, vector<vector<char>>& grid, vector<pair<int, int>>& v, int b1, int b2){
        int n = grid.size();
        int m = grid[0].size();
        vis.insert({i, j});
        v.push_back({i-b1, j-b2});
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        for(int x = 0; x<4; x++){
            int nr = dx[x] + i;
            int nc = dy[x] + j;
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis.count({nr, nc}) && grid[nr][nc] == 'L'){
                dfs(nr, nc, grid, v, b1, b2);
            }
        }
    }
    int countDistinctIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vis.clear();
        shape.clear();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 'W') continue;
                else if(grid[i][j] == 'L' && !vis.count({i,j})){
                    vector<pair<int, int>> v;
                    dfs(i, j, grid, v, i, j);
                    // sort(v.begin(), v.end());
                    shape.insert(v);
                }
            }
        }
        int cnt = shape.size();
        return cnt;
    }
};

int main(){
    
    return 0;
}