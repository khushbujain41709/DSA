// Leetcode 994
// Multisource BFS
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    queue<pair<int, int>> q;
    int freshOranges = 0;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(grid[i][j] == 0) continue;
            if(grid[i][j] == 1) freshOranges++;
            if(grid[i][j] == 2){
                q.push({i,j}); // multisource BFS
            }
        }
    }
    q.push({-1,-1}); // Represents end of a minute or level
    // when we encounter {-1, -1} we do minutes++
    // But at first level all rotten oranges gets enqueued so at end we do minutes-1
    int minutes = 0;
    while(! q.empty()){
        auto curr = q.front();
        int currRow = curr.first;
        int currCol = curr.second;
        q.pop();
        if(currRow == -1 && currCol == -1){
            minutes++;
            if(! q.empty()){ // q mei kuch elements hai
                q.push({-1,-1});
            }
            else break; // queue khali ho gya hai toh loop break krdo
        }
        else{
            if(currRow - 1>= 0 && grid[currRow-1][currCol] == 1){
                freshOranges --;
                grid[currRow-1][currCol] = 2; // mark as visited
                q.push({currRow-1,currCol});
            }
            // down
            if(currRow + 1 < m && grid[currRow+1][currCol] == 1){
                freshOranges --;
                grid[currRow+1][currCol] = 2; // mark as visited
                q.push({currRow+1,currCol});
            }
            // left
            if(currCol - 1 >= 0 && grid[currRow][currCol-1] == 1){
                freshOranges --;
                grid[currRow][currCol-1] = 2; // mark as visited
                q.push({currRow,currCol-1});
            }
            // right
            if(currCol + 1 < n && grid[currRow][currCol+1] == 1){
                freshOranges --;
                grid[currRow][currCol+1] = 2; // mark as visited
                q.push({currRow,currCol+1});
            }
        }
    }
    if(freshOranges == 0) return minutes-1;
    else return -1;
}
int main(){
    
    return 0;
}