// Leetcode 1197
// https://www.geeksforgeeks.org/problems/steps-by-knight5927/1
#include<bits/stdc++.h>
using namespace std;
// Solution 1 - TLE
// The timeout is mainly because we're using: set<pair<int,int>> vis; and set is a balanced BST
class Solution {
  public:
    int dfs(vector<int>& knightPos, vector<int>& targetPos, set<pair<int, int>>&  vis, int idx, int jdx, int n){
        queue<pair<pair<int, int>, int>> q;
        q.push({{idx, jdx}, 0});
        while(!q.empty()){
            auto node = q.front();
            int ans = node.second;
            q.pop();
            int dx[] = {-1, -2, -2, -1, +1, +2, +2, +1};
            int dy[] = {+2, +1, -1, -2, +2, +1, -1, -2};
            for(int i = 0; i<8; i++){
                int nr = node.first.first + dx[i];
                int nc = node.first.second + dy[i];
                if(nr >= 1 && nr <= n && nc >= 1 && nc <= n && !vis.count({nr,nc})){
                    if(nr == targetPos[0] && nc == targetPos[1]){
                        return ans+1; // return ans+1 not ans
                    }
                    vis.insert({nr, nc});
                    q.push({{nr, nc}, ans+1});
                }
            }
        }
    }
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        if(knightPos[0] == targetPos[0] && knightPos[1] == targetPos[1]) return 0;
        set<pair<int,int>> vis;
        vis.insert({knightPos[0], knightPos[1]});
        return dfs(knightPos, targetPos, vis, knightPos[0], knightPos[1], n);
    }
};

// Accepted Solution
class Solution {
  public:
    int dfs(vector<int>& knightPos, vector<int>& targetPos, vector<vector<int>>& vis, int idx, int jdx, int n){
        queue<pair<pair<int, int>, int>> q;
        q.push({{idx, jdx}, 0});
        while(!q.empty()){
            auto node = q.front();
            int ans = node.second;
            q.pop();
            int dx[] = {-1, -2, -2, -1, +1, +2, +2, +1};
            int dy[] = {+2, +1, -1, -2, +2, +1, -1, -2};
            for(int i = 0; i<8; i++){
                int nr = node.first.first + dx[i];
                int nc = node.first.second + dy[i];
                if(nr >= 1 && nr <= n && nc >= 1 && nc <= n && vis[nr][nc] == 0){ // 1 based indexing is given
                    if(nr == targetPos[0] && nc == targetPos[1]){
                        return ans+1; // return ans+1 not ans
                    }
                    vis[nr][nc] = 1;
                    q.push({{nr, nc}, ans+1});
                }
            }
        }
    }
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        if(knightPos[0] == targetPos[0] && knightPos[1] == targetPos[1]) return 0;
        vector<vector<int>> vis(n+1, vector<int>(n+1, 0)); // n+1 is imp as 1 based indexing is given
        vis[knightPos[0]][knightPos[1]] = 1;
        return dfs(knightPos, targetPos, vis, knightPos[0], knightPos[1], n);
    }
};
int main(){
    
    return 0;
}