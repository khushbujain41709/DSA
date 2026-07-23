// Leetcode 1914
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& v, int k){
        int n = v.size();
        k = k % n;
        vector<int> v1, v2;
        for(int i = 0; i<k; i++){
            v1.push_back(v[i]);
        }
        for(int i = k; i<n; i++){
            v2.push_back(v[i]);
        }
        reverse(v1.begin(), v1.end());
        reverse(v2.begin(), v2.end());
        int i = 0;
        while(i<v1.size()){
            v[i] = v1[i];
            i++;
        }
        i = 0;
        while(i<v2.size()){
            v[i+k] = v2[i];
            i++;
        }
        reverse(v.begin(), v.end());
        return;
    }
    vector<int> change(int bi, int bo, int wi, int wo, int k, vector<vector<int>>& grid){
        vector<int> v;
        for(int i = bi; i<= bo; i++){
            v.push_back(grid[wi][i]);
        }
        for(int i = wi+1; i<= wo; i++){
            v.push_back(grid[i][bo]);
        }
        for(int i = bo-1; i>= bi; i--){
            v.push_back(grid[wo][i]);
        }
        for(int i = wo-1; i>= wi+1; i--){
            v.push_back(grid[i][bi]);
        }
        rotate(v, k);
        return v;
    }
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> ans;
        int m = grid.size();
        int n = grid[0].size();
        int bi = 0;
        int bo = n-1;
        int wi = 0;
        int wo = m-1;
        for(int i = 0; i<min(m,n)/2; i++){
            vector<int> v = change(bi, bo, wi, wo, k, grid);
            int p = 0;
            for(int i = bi; i<= bo; i++){
                grid[wi][i] = v[p];
                p++;
            }
            for(int i = wi+1; i<= wo; i++){
                grid[i][bo] = v[p];
                p++;
            }
            for(int i = bo-1; i>= bi; i--){
                grid[wo][i] = v[p];
                p++;
            }
            for(int i = wo-1; i>= wi+1; i--){
                grid[i][bi] = v[p];
                p++;
            }
            bi++;
            bo--;
            wi++;
            wo--;
        }
        return grid;
    }
};
int main(){
    
    return 0;
}