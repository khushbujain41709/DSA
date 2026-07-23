// Leetcode 52
#include<iostream>
#include<vector>
using namespace std;
vector<vector<char>> grid;
vector<vector<string>> result;
bool isSafe(int row, int col, int n){
    // attack can be from three directions - top, left diagonal, right diagonal
    // we are filling queens from top so bottom is empty, so no attack from bottom
    // we are filling only one queen in a row so no attack in horizontal direction
    // attack from top
    for(int i = row-1; i>=0; i--){
        if(grid[i][col] == 'Q'){
            return false;
        }
    }
    // attack from left diagonal
    for(int i = row-1, j= col-1; i>=0 and j>=0; i--, j--){
        if(grid[i][j] == 'Q'){
            return false;
        }
    }
    // attack from right diagonal
    for(int i = row-1, j= col+1; i>=0 and j<n; i--, j++){
        if(grid[i][j] == 'Q'){
            return false;
        }
    }
    return true;
}
void func(int row, int n){
    if(row == n){
        vector<string> res;
        for(int i = 0; i<n; i++){
            string s = "";
            for(int j = 0; j<n; j++){
                s += grid[i][j];
            }
            res.push_back(s);
        }
        result.push_back(res);
        return;
    }
    for(int col = 0; col < n; col++){
        if(isSafe(row, col, n)){
            grid[row][col] = 'Q';
            func(row+1, n);
            grid[row][col] = '.'; // backtracking
        }
    }
}
int totalNQueens(int n) {
    grid.clear();
    grid.resize(n, vector<char>(n, '.'));
    result.clear();
    func(0, n);
    return result.size();
}
int main(){
    
    return 0;
}