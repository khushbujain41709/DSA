// Leetcode 1861
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();
        vector<vector<char>> rotated(n, vector<char>(m));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                rotated[i][j] = boxGrid[m-1-j][i];
            }
        }
        for(int col = 0; col<m; col++){
            int emptyRow = n-1;
            for(int row = n-1; row>=0; row--){
                // obstacle
                if(rotated[row][col] == '*'){
                    emptyRow = row-1;
                }
                // stone
                else if(rotated[row][col] == '#'){
                    rotated[row][col] = '.';
                    rotated[emptyRow][col] = '#';
                    emptyRow--;
                }
            }
        }
        return rotated;
    }
};
int main(){
    
    return 0;
}