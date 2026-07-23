// Leetcode 840
#include<bits/stdc++.h>
using namespace std;
bool traverse(int idx, int jdx, vector<vector<int>>& grid){
    int d1 = 0;
    int d2 = 0;
    unordered_map<int,int> m;
    d1 = grid[idx][jdx+2] + grid[idx+1][jdx+1] + grid[idx+2][jdx];
    if(d1 != 15) return false;
    d2 = grid[idx][jdx] + grid[idx+1][jdx+1] + grid[idx+2][jdx+2];
    if(d2 != 15) return false;
    for(int i = idx; i<idx+3; i++){
        int r = 0;
        for(int j = jdx; j<jdx+3; j++){
            if(grid[i][j] < 1 || grid[i][j] > 9) return false;
            m[grid[i][j]]++;
            r += grid[i][j];
        }
        if(r != 15) return false;
    }
    for(int j = jdx; j<jdx+3; j++){
        int c = 0;
        for(int i = idx; i<idx+3; i++){
            c+=grid[i][j];
        }
        if(c!=15) return false;
    }
    for(auto x : m){
        if(x.second >= 2){
            return false;
        }
    }
    return true;
}
int numMagicSquaresInside(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int count = 0;
    for(int i = 0; i<n-2; i++){
        for(int j = 0; j<m-2; j++){
            bool flag = traverse(i, j, grid);
            if(flag) count++;
        }
    }
    return count;
}
int main(){
    
    return 0;
}