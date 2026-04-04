// Leetcode 2906
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> prefix(n, vector<int>(m, 1));
        vector<vector<int>> suffix(n, vector<int>(m, 1));
        int val = 1;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                prefix[i][j] = val%12345;
                val = (1LL * val%12345 * grid[i][j]%12345) % 12345;
            }
        }
        val = 1;
        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                suffix[i][j] = val%12345;
                val = (1LL * val%12345 * grid[i][j]%12345) % 12345;
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                prefix[i][j] = (1LL * prefix[i][j] * suffix[i][j]) % 12345;
            }
        }
        return prefix;
    }
};
int main(){
    
    return 0;
}