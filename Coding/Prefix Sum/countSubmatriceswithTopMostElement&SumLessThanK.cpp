// Leetcode 3070
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> neww(m, vector<int>(n, 0));
        neww[0][0] = grid[0][0];
        for(int i = 1; i<n; i++){
            neww[0][i] = grid[0][i] + neww[0][i-1];
        }
        for(int i = 1; i<m; i++){
            neww[i][0] = grid[i][0] + neww[i-1][0];
        }
        for(int i = 1; i<m; i++){
            for(int j = 1; j<n; j++){
                neww[i][j] = grid[i][j] + neww[i-1][j] + neww[i][j-1] - neww[i-1][j-1];
            }
        }
        int count = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(neww[i][j] <= k) count++;
            }
        }
        return count;
    }
};
int main(){
    
    return 0;
}