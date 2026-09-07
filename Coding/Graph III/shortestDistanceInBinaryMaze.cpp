// https://www.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int shortestPath(vector<vector<int>> &mat, vector<int> &src, vector<int> &dest) {
        int m = mat.size();
        int n = mat[0].size();
        // Check if source or destination is blocked
        if(mat[src[0]][src[1]] == 0 || mat[dest[0]][dest[1]] == 0) 
            return -1;
        // If source is same as destination
        if(src[0] == dest[0] && src[1] == dest[1]) 
            return 0;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        queue<pair<int, pair<int, int>>> q;
        // Insert distance first and then insert {row, column}
        q.push({0, {src[0], src[1]}});
        dist[src[0]][src[1]] = 0;
        while(! q.empty()){
            int distance = q.front().first;
            int row = q.front().second.first;
            int column = q.front().second.second;
            q.pop();
            int dx[] = {0, 0, -1, +1};
            int dy[] = {+1, -1, 0, 0};
            for(int i = 0; i<4; i++){
                int nrow = row + dx[i];
                int ncol = column + dy[i];
                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && mat[nrow][ncol] != 0){
                    if(distance + 1 < dist[nrow][ncol]){
                        dist[nrow][ncol] = distance + 1;
                        if(nrow == dest[0] && ncol == dest[1]){
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
    
    return 0;
}