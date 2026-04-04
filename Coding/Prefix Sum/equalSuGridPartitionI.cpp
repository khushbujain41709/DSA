// Leetcode 3546
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<long long>> mat(m, vector<long long>(n, 0));
        vector<vector<long long>> mat2(m, vector<long long>(n, 0));
        long long val = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                mat[i][j] = (long long)grid[i][j] + val;
                val = (long long)mat[i][j];
            }
            val = 0;
        }
        val = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                mat2[j][i] = (long long)grid[j][i] + val;
                val = mat2[j][i];
            }
            val = 0;
        }
        long long sumr = 0, sumc = 0;
        for(int i = 0; i<m; i++){
            sumr += mat[i][n-1];
        }
        val = 0;
        for(int i = 0; i<m; i++){
            val += mat[i][n-1];
            if(val == sumr - val){
                return true;
            }   
        }
        for(int i = 0; i<n; i++){
            sumc += mat2[m-1][i];
        }
        val = 0;
        for(int i = 0; i<n; i++){
            val += mat2[m-1][i];
            if(val == sumc - val){
                return true;
            }   
        }
        return false;
    }
};
int main(){
    
    return 0;
}