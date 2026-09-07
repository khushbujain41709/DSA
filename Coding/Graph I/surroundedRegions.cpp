// Leetcode 130
// For all zeroes present at the boundary, do a BFS or DFS and mark the whole set of O neighbours as non capturable.
#include<iostream>
#include<vector>
using namespace std;
void dfs(vector<vector<char>>& board, int r, int c){
    int m = board.size();
    int n = board[0].size();
    if(r < 0 || c < 0 || r >= m || c >= n) return;
    if(board[r][c] == '1' || board[r][c] == 'X') return;
    board[r][c] = '1';
    dfs(board, r+1, c);
    dfs(board, r, c+1);
    dfs(board, r-1, c);
    dfs(board, r, c-1);
}
void solve(vector<vector<char>>& board){
    int m = board.size();
    int n = board[0].size();
    for(int i = 0; i<m ; i++){
        for(int j = 0; j<n; j++){
            if(i == 0 || j == 0 || i == m-1 || j == n-1){
                if(board[i][j] == 'O'){
                    dfs(board, i, j);
                }
            }
        }
    }
    for(int i = 0; i<m ; i++){
        for(int j = 0; j<n; j++){
            if(board[i][j] == '1'){
                board[i][j] = 'O';
            }
            else board[i][j] = 'X';
        }
    }
    return;
}
int main(){
    
    return 0;
}