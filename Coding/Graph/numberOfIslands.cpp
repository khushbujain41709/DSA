// Leetcode 200
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int numIslands(vector<vector<char>>& grid){
    int m = grid.size();
    int n = grid[0].size();
    int count = 0; // Stores the number of connected component
    for(int i = 0; i<m ; i++){
        for(int j = 0; j<n; j++){
            if(grid[i][j] == '0') continue; // It is a water body
            // new unvisited land piece that is new connected component
            count ++;
            grid[i][j] = 0; // mark as visited as it is binary grid so we can't assign any other number
            // start BFS
            queue<pair<int, int>> q;
            q.push({i, j}); // store the source node
            while(!q.empty()){
                auto curr = q.front();
                int currRow = curr.first;
                int currCol = curr.second;
                q.pop();
                // go to all unvisited neighbours of the curr node
                // up
                if(currRow - 1>= 0 && grid[currRow-1][currCol] == '1'){
                    q.push({currRow-1,currCol});
                    grid[currRow-1][currCol] = '0'; // mark as visited
                }
                // down
                if(currRow + 1 < m && grid[currRow+1][currCol] == '1'){
                    q.push({currRow+1,currCol});
                    grid[currRow+1][currCol] = '0'; // mark as visited
                }
                // left
                if(currCol - 1>= 0 && grid[currRow][currCol-1] == '1'){
                    q.push({currRow,currCol-1});
                    grid[currRow][currCol-1] = '0'; // mark as visited
                }
                // right
                if(currCol + 1 < n && grid[currRow][currCol+1] == '1'){
                    q.push({currRow,currCol+1});
                    grid[currRow][currCol+1] = '0'; // mark as visited
                }
            }
        }
    }
    return count;
}
int main(){
    
    return 0;
}