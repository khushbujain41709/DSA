// Leetcode 36
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
bool matrixTraverse(vector<vector<char>>& board, int idx, int jdx){
    unordered_map<int,int> grid;
    for(int i = idx; i<3+idx; i++){
        for(int j = jdx; j<3+jdx; j++){
            if(board[i][j] == '.') continue;
            grid[board[i][j]]++;
        }
    }
    // pura grid bharne k baad check krna hai frequency ko
    // grid clear krne ki jarurat nhi hai kyuki new form hoga har 3x3 matrix k liye
    for(auto x : grid){
        if(x.second >= 2){
            return false;
        }
    }
    return true;
}
bool isValidSudoku(vector<vector<char>>& board){
    unordered_map<int,int> row, column, grid;
    // traversing each row
    for(int i = 0; i<9; i++){
        for(int j = 0; j<9; j++){
            if(board[i][j] == '.') continue;
            row[board[i][j]]++;
        }
        for(auto x : row){
            if(x.second >= 2){
                return false;
            }
        }
        row.clear();
    }
    // traversing each column
    for(int j = 0; j<9; j++){
        for(int i = 0; i<9; i++){
            if(board[i][j] == '.') continue;
            column[board[i][j]]++;
        }
        for(auto x : column){
            if(x.second >= 2){
                return false;
            }
        }
        column.clear();
    }
    // traversing in 3x3 size sub matrix
    for(int i = 0; i<9; i+= 3){
        for(int j = 0; j<9; j+= 3){
            bool ans = matrixTraverse(board,i,j);
            if(ans == false)return false;
        }
    }
    return true;
}
int main(){
    
    return 0;
}