// Leetcode 79
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool helper(int idx, int jdx, vector<vector<char>>& board, string word, set<pair<int, int>>& vis, int k){
        if(k == word.size()){
            return true;
        }
        int m = board.size();
        int n = board[0].size();
        int dx[] = {+1, -1, 0, 0};
        int dy[] = {0, 0, -1, +1};
        for(int i = 0; i<4; i++){
            int nr = idx+dx[i];
            int nc = jdx+dy[i];
            if(nr >= 0 && nr < m && nc >= 0 && nc < n && board[nr][nc] == word[k] && !vis.count({nr,nc})){
                vis.insert({nr, nc});
                k++; // k == n as k++ at the end.
                if(helper(nr, nc, board, word, vis, k)) return true;
                k--;
                vis.erase({nr,nc});
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        char start = word[0];
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(board[i][j] == start){
                    set<pair<int, int>> vis;
                    vis.insert({i,j});
                    int k = 1; // word index and start is already index 0 so k = 1
                    if(helper(i, j, board, word, vis, k) == true){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
int main(){
    
    return 0;
}