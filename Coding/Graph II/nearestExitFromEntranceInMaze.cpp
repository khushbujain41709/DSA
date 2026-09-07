// Leetcode 1926
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        queue<pair<pair<int,int> , int>> q;
        set<pair<int, int>> vis;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(i == entrance[0] && j == entrance[1]){
                    q.push({{i,j}, 0});
                    vis.insert({i,j});
                }
                else continue;
            }
        }
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int step = q.front().second;
            q.pop();
            int dx[] = {1, -1, 0, 0};
            int dy[] = {0, 0, 1, -1};
            for(int i = 0; i<4; i++){
                int nr = dx[i] + r;
                int nc = dy[i] + c;
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && !vis.count({nr,nc}) && maze[nr][nc] != '+' && maze[nr][nc] == '.'){
                    q.push({{nr,nc}, step+1});
                    vis.insert({nr,nc});
                    if((nr == m-1 || nr == 0 || nc == 0 || nc == n-1) && !(nr == entrance[0] && nc == entrance[1])){
                        return step+1;
                    }
                }
            }
        }
        return -1;
    }
};
int main(){
    
    return 0;
}