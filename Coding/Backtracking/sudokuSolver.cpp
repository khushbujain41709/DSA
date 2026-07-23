// Leetcode 37
#include<iostream>
#include<vector>
using namespace std;
bool isValidSudoku(vector<vector<char>>& board, int r, int c, char val){
    // checking row
    for(int j = 0; j<9; j++){
        if(board[r][j] == val){
            return false;
        }
    }
    // checking column
    for(int i = 0; i<9; i++){
        if(board[i][c] == val){
            return false;
        }
    }
    // checking submatrix of 3x3
    int startRow = (r / 3) * 3; // imp
    int startCol = (c / 3) * 3; // imp
    for(int i = startRow; i<startRow+3; i++){
        for(int j = startCol; j<startCol+3; j++){
            if(board[i][j] == val){
                return false;
            }
        }
    }
    return true;
}
bool f(vector<vector<char>>& board, int r, int c){
    if(r == 9){
        return true;
    }
    if(c >= 9){ // traversed all columns of a row
        return f(board, r+1, 0);
    }
    if(board[r][c] != '.'){
        return f(board, r, c+1);
    }
    else{
        for(char i = '1'; i <= '9'; i++){
            if(isValidSudoku(board, r, c, i)){
                board[r][c] = i;
                bool ans = f(board, r, c+1);
                if(ans){
                    return true;
                }
                board[r][c] = '.';
            }
        }
    }
    return false;
}
void solveSudoku(vector<vector<char>>& board) {
    f(board, 0, 0);
    return;
}
int main(){
    
    return 0;
}