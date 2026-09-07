// If you can color the graph with 2 colors such that no adjacent nodes have same color then the graph is bipartite.
// Linear graphs with no cycle are always bipartite.
// Any graph with even length cycle is also bipartite.
// Any graph with odd length cycle can never be bipartite. Graph is non-bipartite graph.
// In code, -1 means not colored yet.
#include<bits/stdc++.h>
using namespace std;
// Using BFS
class Solution {
public:
    bool checkBipartiteBFS(int start, vector<int>& color, vector<vector<int>>& graph){
        color[start] = 0;
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto x: graph[node]){
                if(color[x] == -1){ // not colored
                    color[x] = !color[node];
                    q.push(x);
                }
                if(color[x] == color[node]) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        // If we get TLE or error in graphs, there can be multiple connected components in the graph
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i = 0; i<n; i++){
            // check for every node - can be multiple connected components
            if(color[i] == -1){
                if(!checkBipartiteBFS(i, color, graph)){
                    return false;
                }
            }
        }
        return true;
    }
};

// Using DFS
class Solution {
public:
    bool checkBipartiteDFS(int start, vector<int>& color, vector<vector<int>>& graph, int currColor){
        color[start] = currColor;
        for(auto x: graph[start]){
            if(color[x] == -1){ // not colored
                if(checkBipartiteDFS(x, color, graph, !currColor) == false) return false; // imp line
            }
            else if(color[x] == color[start]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        // If we get TLE or error in graphs, there can be multiple connected components in the graph
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i = 0; i<n; i++){
            // check for every node - can be multiple connected components
            if(color[i] == -1){
                if(!checkBipartiteDFS(i, color, graph, 0)){
                    return false;
                }
            }
        }
        return true;
    }
};
int main(){
    
    return 0;
}
