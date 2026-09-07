// Leetcode 1756
// Same as Leetcode 542 = 01 Matrix
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        queue<pair<pair<int, int>, int>> q;
        set<pair<int, int>> vis;
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(isWater[i][j] == 0) continue;
                if(isWater[i][j] == 1){
                    ans[i][j] = 0;
                    q.push({{i,j}, 0});
                    vis.insert({i,j});
                }
            }
        }
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int height = q.front().second;
            q.pop();
            int dx[] = {1, -1, 0, 0};
            int dy[] = {0, 0, -1, 1};
            for(int i = 0; i<4; i++){
                int nr = dx[i] + r;
                int nc = dy[i] + c;
                if(nr >= 0 && nr < m && nc >=0 && nc < n && !vis.count({nr,nc})){
                    q.push({{nr,nc} , height+1});
                    ans[nr][nc] = height+1;
                    vis.insert({nr,nc});
                }
            }
        }
        return ans;
    }
};
int main(){
    
    return 0;
}