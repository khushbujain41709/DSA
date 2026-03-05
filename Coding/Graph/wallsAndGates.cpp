// Leetcode 286 - Subscription problem
// On naukri.com
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define INF 2147483647
vector<vector<int>> wallsAndGates(vector<vector<int>> &a, int n, int m){
    queue<pair<int, int>> q;
    vector<vector<int>> ans(n, vector<int> (m, INF)); // already initialized with INF to ensure visited
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(a[i][j] == 0){
                q.push({i, j});
                ans[i][j] = 0; // gate
            }
            else if(a[i][j] == -1){
                ans[i][j] = -1; // wall
            }
        }
    }
    while(! q.empty()){
        auto curr = q.front();
        int r = curr.first;
        int c = curr.second;
        q.pop();
        if(r < 0 || c < 0 || r >= n || c >= m || a[r][c] == -1) continue;
        if(r + 1 < n && ans[r+1][c] == INF){
            q.push({r+1, c});
            ans[r+1][c] = 1 + ans[r][c];
        }
        if(c + 1 < m && ans[r][c+1] == INF){
            q.push({r, c+1});
            ans[r][c+1] = 1 + ans[r][c];
        }
        if(r - 1 >= 0 && ans[r-1][c] == INF){
            q.push({r-1, c});
            ans[r-1][c] = 1 + ans[r][c];
        }
        if(c - 1 >= 0 && ans[r][c-1] == INF){
            q.push({r, c-1});
            ans[r][c-1] = 1 + ans[r][c];
        }
    }
    return ans;
}
int main(){
    
    return 0;
}