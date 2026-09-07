// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
#include<bits/stdc++.h>
using namespace std;
// Use BFS here because the graph is undirected and all edges have unit distance. The time complexity of this approach is O(V + E), where V is the number of vertices and E is the number of edges in the graph.

// Method 1
class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        int m = edges.size();
        vector<vector<int>> graph(V);
        for(int i = 0; i<m; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
            // graph is undirected
            graph[v].push_back(u);
        }
        unordered_set<int> vis;
        vis.insert(src);
        queue<pair<int, int>> q;
        vector<int> dist(V, -1);
        q.push({src, 0});
        dist[src] = 0;
        while(!q.empty()){
            int node = q.front().first;
            int step = q.front().second;
            q.pop();
            for(auto x: graph[node]){
                if(!vis.count(x)){
                    vis.insert(x);
                    dist[x] = step+1;
                    q.push({x, step + 1});
                }
            }
        }
        return dist[dest];
    }
};

// Method 2
class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        int m = edges.size();
        vector<vector<int>> graph(V);
        for(int i = 0; i<m; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
            // graph is undirected
            graph[v].push_back(u);
        }
        queue<int> q;
        vector<int> dist(V, INT_MAX);
        q.push(src);
        dist[src] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto x: graph[node]){
                int distance = dist[node] + 1;
                if(distance < dist[x]){ // used instead of visited set
                    dist[x] = distance;
                    q.push(x); // added to queue only if the distance is updated, so that we don't process the same node again and again
                }
            }
        }
        vector<int> ans(V, -1);
        for(int i = 0; i<V; i++){
            if(dist[i] != INT_MAX){
                ans[i] = dist[i];
            }
        }
        return ans[dest];
    }
};
int main(){
    
    return 0;
}