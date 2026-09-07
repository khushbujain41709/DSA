// Dijkstra algorithm fails when there are negative weight edges in the graph. In such cases, we can use Bellman-Ford algorithm to find the shortest path from a source node to all other nodes in the graph. The Bellman-Ford algorithm can handle graphs with negative weight edges and can also detect negative weight cycles.

// Dijkstra will give TLE in case of negative cycles.

// Bellman Ford is a single source shortest path algorithm. It is slower than Dijkstra's algorithm but more versatile. The Bellman-Ford algorithm is based on the principle of relaxation, which means that it iteratively updates the distance to each vertex by considering all edges in the graph. The algorithm runs in O(V * E) time complexity, where V is the number of vertices and E is the number of edges in the graph.

// Bellman Ford is only applicable to directed graphs. It can be applied to undirected graphs by converting them into directed graphs by replacing each undirected edge with two directed edges of the same weight in opposite directions.

// Path weight in a graph is defined as the sum of weights of edges in the path. If the path weight is negative then the graph is said to have a negative weight cycle. 

// Steps:
// 1) Edges can be in any order. We can relax all edges in any order.
// 2) Relax all edges V-1 times sequentially, where V is the number of vertices in the graph. This is because the maximum number of edges in a shortest path can be V-1.
// 3) Relax: if(distance[u] + weight < distance[v]) then distance[v] = distance[u] + weight

// On Vth iteration, the relaxation will be done and if distance array is reduced then it means that there is a negative weight cycle in the graph.

// TC = O(V * E) where V is the number of vertices and E is the number of edges in the graph.
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        int m = edges.size();
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        for(int i = 0; i<V-1; i++){
            for(int j = 0; j<m; j++){
                int u = edges[j][0];
                int v = edges[j][1];
                int w = edges[j][2];
                int distance = dist[u] + w;
                if(dist[u] != INT_MAX && distance < dist[v]){
                    // dist[u] != INT_MAX is imp
                    dist[v] = distance;
                }
            }
        }
        vector<int> vec(dist.begin(), dist.end());
        for(int i = 0; i<m; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            int distance = vec[u] + w;
            if(vec[u] != INT_MAX && distance < vec[v]){
                // vec[u] != INT_MAX is imp
                vec[v] = distance;
            }
        }
        for(int i = 0; i<V; i++){
            if(dist[i] != vec[i]){
                return {-1};
            }
        }
        for(int i = 0; i<V; i++){
            if(dist[i] == INT_MAX){
                dist[i] = 1e8;
            }
        }
        return dist;
    }
};
int main(){

}