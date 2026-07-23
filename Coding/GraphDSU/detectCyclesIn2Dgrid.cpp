// Leetcode 1559
#include<bits/stdc++.h>
using namespace std;
bool dfs(int i, int j , int parent_i, int parent_j, unordered_set<int>& visited, vector<vector<char>>& grid){
    int m = grid.size();
    int n = grid[0].size();
    // If neighbor is visited and not parent, cycle exists
    // So parent check must be done when exploring neighbors, not at entry.
    if(visited.count(i*n+j) && (i != parent_i || j != parent_j)){
        return true;
    }
    visited.insert(i*n+j);
    if(i != 0 && grid[i][j] == grid[i-1][j]){ // up
        int nid = (i-1)*n + j;
        if(!visited.count(nid)) {
            if(dfs(i-1, j, i, j, visited, grid)) return true;
        }
        else if(i-1 != parent_i || j != parent_j) {
            return true;
        }
    }
    if(j != 0 && grid[i][j] == grid[i][j-1]){ // left
        int nid = (i)*n + j-1;
        if(!visited.count(nid)) {
            if(dfs(i, j-1, i, j, visited, grid)) return true;
        }
        else if(i != parent_i || j-1 != parent_j) {
            return true;
        }
    }
    if(i != m-1 && grid[i][j] == grid[i+1][j]){ // down
        int nid = (i+1)*n + j;
        if(!visited.count(nid)) {
            if(dfs(i+1, j, i, j, visited, grid)) return true;
        }
        else if(i+1 != parent_i || j != parent_j) {
            return true;
        }
    }
    if(j != n-1 && grid[i][j] == grid[i][j+1]){ // right
        int nid = (i)*n + j+1;
        if(!visited.count(nid)) {
            if(dfs(i, j+1, i, j, visited, grid)) return true;
        }
        else if(i != parent_i || j+1 != parent_j) {
            return true;
        }
    }
    return false;
}
bool containsCycle(vector<vector<char>>& grid){
    int m = grid.size();
    int n = grid[0].size();
    unordered_set<int> visited;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){ // int id = i * n + j; This guarantees uniqueness
            if(!visited.count(i*n+j)){
                bool ans = dfs(i, j, -1, -1, visited, grid);
                if(ans) return true;
            }
        }
    }
    return false;
}
int main(){
    
    return 0;
}