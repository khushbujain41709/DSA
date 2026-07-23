// Leetcode 3212
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> prefix(m, vector<int>(n, 0));
        vector<vector<int>> px(m, vector<int>(n, 0)); // count of X
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 'X'){
                    prefix[i][j] = 1;
                    px[i][j] = 1;
                }
                else if(grid[i][j] == 'Y') prefix[i][j] = -1;
                else if(grid[i][j] == '.') prefix[i][j] = 0;
            }
        }
        if(grid[0][0] == 'X'){
            px[0][0] = 1;
        }
        else{
            px[0][0] = 0;
        }
        for(int i = 1; i<n; i++){
            prefix[0][i] = prefix[0][i] + prefix[0][i-1];
            px[0][i] = px[0][i] + px[0][i-1];
        }
        for(int i = 1; i<m; i++){
            prefix[i][0] = prefix[i][0] + prefix[i-1][0];
            px[i][0] = px[i][0] + px[i-1][0];
        }
        int val = 0, valx = 0;
        for(int i = 1; i<m; i++){
            for(int j = 1; j<n; j++){
                if(grid[i][j] == 'X'){
                    val = 1;
                    valx = 1;
                }
                else if(grid[i][j] == 'Y'){
                    val = -1;
                    valx = 0;
                }
                else if(grid[i][j] == '.'){
                    val = 0;
                    valx = 0;
                }
                prefix[i][j] = val + prefix[i][j-1] + prefix[i-1][j] - prefix[i-1][j-1];
                px[i][j] = px[i][j-1] + px[i-1][j] + valx - px[i-1][j-1]; 
            }
        }
        int count = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(prefix[i][j] == 0 && px[i][j] > 0) count++;
            }
        }
        return count;
    }
};
int main(){
    
    return 0;
}