// Leetcode 1034
/*
DFS traversal to mark all cells in the component.
Temporarily mark visited cells with negative newColor (-newColor) → prevents revisits and distinguishes them.
While backtracking from recursion, decide if a cell is internal (all 4 neighbors belong to the same component).
Internal cells are later restored to original color.
Non-internal cells (border) stay as color.
*/
#include<iostream>
#include<vector>
using namespace std;
vector<pair<int, int>> internalCells;
void dfs(vector<vector<int>>& grid, int currRow, int currCol, int newColor, int initialColor){
    int m = grid.size();
    int n = grid[0].size();
    if(currRow < 0 || currCol < 0 || currRow >= m || currCol >= n || grid[currRow][currCol] != initialColor){
        return;
    }
    grid[currRow][currCol] = -newColor;

    dfs(grid, currRow-1, currCol, newColor, initialColor); // up
    dfs(grid, currRow+1, currCol, newColor, initialColor); // down
    dfs(grid, currRow, currCol-1, newColor, initialColor); // left
    dfs(grid, currRow, currCol+1, newColor, initialColor); // right

    // below code will be executed while coming back from recursion
    // This indicates a internal cell
    if(not (currRow <= 0 || currCol <= 0 || currRow >= m-1 || currCol >= n-1 || grid[currRow+1][currCol] != -newColor || grid[currRow][currCol-1] != -newColor || grid[currRow-1][currCol] != -newColor || grid[currRow][currCol+1] != -newColor)){
        internalCells.push_back({currRow, currCol});
    }
}
vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color){
    int initialColor = grid[row][col]; // This is the initial color of the component
    int m = grid.size();
    int n = grid[0].size();
    if(initialColor == color) return grid;
    dfs(grid, row, col, color, initialColor);
    for(auto ele : internalCells){
        grid[ele.first][ele.second] = initialColor;
    }
    for(int i = 0; i< m; i++){
        for(int j = 0; j<n; j++){
            if(grid[i][j] < 0) grid[i][j] *= -1;
        }
    }
    return grid;
}
int main(){
    
    return 0;
}