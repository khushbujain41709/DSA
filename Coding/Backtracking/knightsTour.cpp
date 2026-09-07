// Leetcode 2664 - Premium
// https://www.geeksforgeeks.org/problems/the-knights-tour-problem/1
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool helper(vector<vector<int>>& ans, int n, vector<vector<int>>& vis, int idx, int jdx, int k){
        if(k == n*n){
            return true;
        }
        int dx[] = {-1, -2, -2, -1, +1, +2, +2, +1};
        int dy[] = {+2, +1, -1, -2, +2, +1, -1, -2};
        for(int i = 0; i<8; i++){
            int nr = idx+dx[i];
            int nc = jdx+dy[i];
            if(nr >= 0 && nr < n && nc >= 0 && nc < n && vis[nr][nc] == 0){
                vis[nr][nc] = 1;
                ans[nr][nc] = k;
                k++; // k == n*n bcoz at the end k is append to k++;
                if(helper(ans, n, vis, nr, nc, k) == true){
                    return true;
                }
                ans[nr][nc] = 0;
                vis[nr][nc] = 0;
                k--;
            }
        }
        return false;
    }
    vector<vector<int>> knightTour(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        vector<vector<int>> vis(n, vector<int>(n, 0));
        int k = 1; // k = 0; is already alloted to ans[0][0];
        vis[0][0] = 1;
        ans[0][0] = 0;
        if(helper(ans, n, vis, 0, 0, k) == true){
            return ans;
        }
        else{
            return {};
        }
    }
};
int main(){
    
    return 0;
}