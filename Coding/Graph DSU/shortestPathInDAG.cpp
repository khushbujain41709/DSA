// https://www.geeksforgeeks.org/problems/shortest-path-in-directed-acyclic-graph/1

// We used topological sort to find the shortest path in a directed acyclic graph (DAG). The idea is to perform a topological sort of the graph and then relax the edges in the order of the topological sort. This ensures that we process each vertex only after all its predecessors have been processed, allowing us to find the shortest path efficiently.

// Dijkstra's algorithm is necessary for graphs with cycles(because they can't be topologically sorted) and non-negative weights, but in a DAG, we can achieve the same result more efficiently using topological sorting. The time complexity of this approach is O(V + E), where V is the number of vertices and E is the number of edges in the graph.
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void dfs(unordered_set<int>& vis, vector<vector<pair<int,int>>>& graph, stack<int>& st, int src){
        vis.insert(src);
        for(auto x: graph[src]){
            if(!vis.count(x.first)){
                dfs(vis, graph, st, x.first);
            }
        }
        st.push(src);
    }
    vector<int> shortestPath(int V, vector<vector<int>>& edges) {
        // code here
        int m = edges.size();
        vector<vector<pair<int, int>>> graph(V);
        for(int i = 0; i<m; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            graph[u].push_back({v, w});
        }
        vector<int> dist(V, INT_MAX); // INT_MAX is inf here
        // src is 0 here in this question
        dist[0] = 0;
        stack<int> st;
        unordered_set<int> vis;
        for(int i = 0; i<V; i++){
            if(!vis.count(i)){
                dfs(vis, graph, st, 0);
            }
        }
        // stack contains topological sort ordered nodes - TC = O(V+E) that is simple DFS
        // TC = O(V+E) for the below while loop as well, so overall TC = O(V+E) as O(V) for all vertices in stack and O(E) for all edges in the graph as we are traversing all edges in the graph.
        while(! st.empty()){
            int node = st.top();
            st.pop();
            for(auto x: graph[node]){
                int distance = dist[node] + x.second;
                if(distance < dist[x.first]){
                    dist[x.first] = distance;
                }
            }
        }
        for(int i = 0; i<V; i++){
            if(dist[i] == INT_MAX){
                dist[i] = -1;
            }
        }
        return dist;
    }
};

int main(){

}