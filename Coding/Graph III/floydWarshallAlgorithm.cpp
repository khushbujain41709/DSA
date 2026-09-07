// https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
// Multi-Source Shortest Path Algorithm
// Helps to detect negative weight cycles in a graph. If the distance of a vertex from itself becomes negative then it means that there is a negative weight cycle in the graph.
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        int n = dist.size();
        for(int k = 0; k<n; k++){
            for(int i = 0; i<n; i++){
                for(int j = 0; j<n; j++){
                    if(dist[i][k] != 1e8 && dist[k][j] != 1e8) dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
                }
            }
        }
        // Since in this question, it is stated that graph doesnot contain any negative weight cycle but still checking.
        // for(int i = 0; i<n; i++){
        //     if(dist[i][i] < 0){
        //         return {{-1}};
        //     }
        // }
    }
};
int main(){
    
    return 0;
}