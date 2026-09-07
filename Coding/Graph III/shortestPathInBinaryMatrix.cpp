// Leetcode 1091
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        // Check if source or destination is blocked
        if(mat[0][0] == 1 || mat[n-1][n-1] == 1) return -1;
        if(n == 1) return 1;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int, pair<int, int>>> q;
        // Insert distance first and then insert {row, column}
        q.push({1, {0, 0}});
        dist[0][0] = 1;
        while(! q.empty()){
            int distance = q.front().first;
            int row = q.front().second.first;
            int column = q.front().second.second;
            q.pop();
            int dx[] = {0, 0, -1, +1, +1, -1, +1, -1};
            int dy[] = {+1, -1, 0, 0, +1, -1, -1, +1};
            for(int i = 0; i<8; i++){
                int nrow = row + dx[i];
                int ncol = column + dy[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && mat[nrow][ncol] == 0){
                    if(distance + 1 < dist[nrow][ncol]){
                        dist[nrow][ncol] = distance + 1;
                        if(nrow == n-1 && ncol == n-1){
                            return distance + 1;
                        }
                        q.push({distance + 1, {nrow, ncol}});
                    }
                }
            }
        }
        return -1;
    }
};
int main(){

}