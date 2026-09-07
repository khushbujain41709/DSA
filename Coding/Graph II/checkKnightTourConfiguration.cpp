// Leetcode 2596
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool dfs(vector<vector<int>>& grid, set<pair<int, int>>&  vis, int idx, int jdx, int num){
        int n = grid.size();
        if(num == n*n - 1) return true;
        int dx[] = {-1, -2, -2, -1, +1, +2, +2, +1};
        int dy[] = {+2, +1, -1, -2, +2, +1, -1, -2};
        for(int i = 0; i<8; i++){
            int nr = idx+dx[i];
            int nc = jdx+dy[i];
            if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == num+1 && !vis.count({nr,nc})){
                vis.insert({nr, nc});
                if(dfs(grid, vis, nr, nc, num+1)) return true;
            }
        }
        return false;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        set<pair<int,int>> vis;
        vis.insert({0,0});
        bool flag = dfs(grid, vis, 0, 0, 0);
        return flag;
    }
};
int main(){
    
    return 0;
}