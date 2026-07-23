// Leetcode 542
// Multi-source BFS with sources as zeroes
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> ans(m, vector<int> (n, -1)); // already initialized with -1 to ensure visited
    queue<pair<int, int>> q;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(mat[i][j] == 0){
                q.push({i, j});
                ans[i][j] = 0;
            }
        }
    }
    while(! q.empty()){
        auto curr = q.front();
        int r = curr.first;
        int c = curr.second;
        q.pop();
        if(r < 0 || c < 0 || r >= m || c >= n) continue;
        if(r + 1 < m && ans[r+1][c] == -1){
            q.push({r+1, c});
            ans[r+1][c] = 1 + ans[r][c];
        }
        if(r - 1 >= 0 && ans[r-1][c] == -1){
            q.push({r-1, c});
            ans[r-1][c] = 1 + ans[r][c];
        }
        if(c + 1 < n && ans[r][c+1] == -1){
            q.push({r, c+1});
            ans[r][c+1] = 1 + ans[r][c];
        }
        if(c - 1 >= 0 && ans[r][c-1] == -1){
            q.push({r, c-1});
            ans[r][c-1] = 1 + ans[r][c];
        }
    }
    return ans;
}
int main(){
    
    return 0;
}