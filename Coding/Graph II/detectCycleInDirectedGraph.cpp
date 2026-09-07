// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
// We will create two sets - pathVisited and Visited or make Vis array where mark 1 as visited and mark 2 as pathVisited
// If same node is in pathVisited and Visited then cycle exists.
// TC = O(V + E) as it is a directed graph
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool dfs(int src, unordered_set<int>& vis, unordered_set<int>& pathVis, vector<vector<int>> &adjList){
        vis.insert(src);
        pathVis.insert(src);
        for(auto x: adjList[src]){
            if(!vis.count(x)){
                if(dfs(x, vis, pathVis, adjList) == true) return true; // cycle found
            }
            else{ // already visited
                if(pathVis.count(x) == true) return true;
            }
        }
        pathVis.erase(src); // most imp
        return false;
        
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        unordered_set<int> vis;
        unordered_set<int> pathVis;
        vector<vector<int>> adjList(V); // Giving V is imp
        for(int i = 0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adjList[u].push_back(v);
        }
        for(int i = 0; i<V; i++){
            if(!vis.count(i)){
                if(dfs(i, vis, pathVis, adjList) == true){
                    return true; // cycle exists
                }
            }
        }
        return false;
    }
};
int main(){
    
    return 0;
}