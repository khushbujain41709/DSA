// Leetcode 1334
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int m = edges.size();
        vector<vector<int>> adjMat(n, vector<int>(n, INT_MAX));
        for(int i = 0; i<m; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adjMat[u][v] = w;
            adjMat[v][u] = w;
        }
        for(int i = 0; i<n; i++){
            adjMat[i][i] = 0;
        }
        // Shortest distance using Floyd Warshall Algorithm
        for(int k = 0; k<n; k++){
            for(int i = 0; i<n; i++){
                for(int j = 0; j<n; j++){
                    if(adjMat[i][k] != INT_MAX && adjMat[k][j] != INT_MAX) adjMat[i][j] = min(adjMat[i][k] + adjMat[k][j], adjMat[i][j]);
                }
            }
        }
        int minCity = INT_MAX;
        int city = -1;
        for(int i = 0; i<n; i++){
            int cnt = 0;
            for(int j = 0; j<n; j++){
                if(adjMat[i][j] <= distanceThreshold){
                    cnt++;
                }
            }
            if(cnt <= minCity){
                minCity = cnt;
                city = i;
            }
        }
        return city;
    }
};
int main(){
    
    return 0;
}