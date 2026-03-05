// Leetcode 417
// Multisource BFS/DFS
// TC = O(m*n)
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<vector<bool>> bfs(vector<vector<int>>& heights, queue<pair<int, int>>& q){
    vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int m = heights.size();
    int n = heights[0].size();
    vector<vector<bool>> visited(m, vector<bool> (n,  false)); // initialized with false
    while(! q.empty()){
        auto curr = q.front();
        q.pop();
        int i = curr.first;
        int j = curr.second;
        visited[i][j] = true;
        for(int d = 0; d<4; d++){
            int newRow = i + dir[d][0];
            int newCol = j + dir[d][1];
            if(newRow < 0 || newCol < 0 || newRow >= m || newCol >= n) continue;
            if(visited[newRow][newCol]) continue;
            // We are applying BFS from water(boundary cells) to land cells
            if(heights[newRow][newCol] < heights[i][j]) continue; // water to land we need increaing height
            q.push({newRow, newCol});
        }
    }
    return visited;
}
vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights){
    int m = heights.size();
    int n = heights[0].size();
    vector<vector<int>> ans;
    queue<pair<int, int>> pacificBFS;
    queue<pair<int, int>> atlanticBFS;
    // Step of multisource BFS
    for(int i = 0 ; i<m ; i++){
        pacificBFS.push({i,0});
        atlanticBFS.push({i, n-1});
    }
    for(int j = 1; j<n; j++){
        pacificBFS.push({0,j});
    }
    for(int j = 0; j<n-1; j++){
        atlanticBFS.push({m-1, j});
    }
    vector<vector<bool>> pacific = bfs(heights, pacificBFS);
    vector<vector<bool>> atlantic = bfs(heights, atlanticBFS);
    for(int i = 0; i< m; i++){
        for(int j = 0; j<n; j++){
            if(pacific[i][j] && atlantic[i][j]){
                ans.push_back({i,j});
            }
        }
    }
    return ans;
}
int main(){
    
    return 0;
}