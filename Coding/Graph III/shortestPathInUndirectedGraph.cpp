// https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1
// Hint: Remember from where am I coming from?
// If multiple shortest paths have the same total weight, return the lexicographically smallest path.
// TC - O(ElogV) + O(V)
#include<bits/stdc++.h>
using namespace std;
// This code is correct for non - lexicographically smallest path.
class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        vector<vector<pair<int, int>>> graph(V+1);
        int m = edges.size();
        for(int i = 0; i<m; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src}); // Insert weight first and then insert node
        vector<int> dist(V+1, INT_MAX);
        vector<int> parent(V+1, src);
        dist[src] = 0;
        parent[src] = src;
        while(! pq.empty()){
            int weight = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto x: graph[node]){
                // x.first = node
                // x.second = weight
                int distance = dist[node] + x.second;
                if(distance < dist[x.first]){
                    dist[x.first] = distance;
                    parent[x.first] = node;
                    pq.push({distance, x.first});
                }
            }
        }
        int node = dest;
        vector<int> ans;
        ans.push_back(dest);
        while(parent[node] != node){
            node = parent[node];
            ans.push_back(node);
        }
        if(dist[dest] == INT_MAX) return {-1}; // imp
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// For lexicographically smallest path
// For lexicographically smallest path, one dist array from src is not enough. We need another distance array from dest.
class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        vector<vector<pair<int, int>>> graph(V+1);
        int m = edges.size();
        for(int i = 0; i<m; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
        // ---------------- DIJKSTRA FROM SRC ----------------
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src}); // Insert weight first and then insert node
        vector<int> dist(V+1, INT_MAX);
        dist[src] = 0;
        while(! pq.empty()){
            int weight = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto x: graph[node]){
                // x.first = node
                // x.second = weight
                int distance = dist[node] + x.second;
                if(distance < dist[x.first]){
                    dist[x.first] = distance;
                    pq.push({distance, x.first});
                }
            }
        }
        // No path
        if(dist[dest] == INT_MAX) return {-1}; // imp
        // ---------------- DIJKSTRA FROM DEST ----------------
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq2;
        vector<int> distDest(V+1, INT_MAX);
        distDest[dest] = 0;
        pq2.push({0, dest}); // Insert weight first and then insert node
        while(! pq2.empty()){
            int weight = pq2.top().first;
            int node = pq2.top().second;
            pq2.pop();
            for(auto x: graph[node]){
                // x.first = node
                // x.second = weight
                int distance = distDest[node] + x.second;
                if(distance < distDest[x.first]){
                    distDest[x.first] = distance;
                    pq2.push({distance, x.first});
                }
            }
        }
        vector<int> ans;
        int node = src;
        ans.push_back(src);
        while(node != dest){
            int smallest = INT_MAX;
            for(auto x: graph[node]){
                // x.first = node
                // x.second = weight
                
                // dist[node] = shortest distance from source to the current node
                // x.second = weight of the edge from node to nextNode
                // distDest[x.first] = shortest distance from destination to nextNode (or from nextNode to destination, since it's undirected)
                // dist[dest] = total shortest distance from source to destination
                if(dist[node] + x.second + distDest[x.first] == dist[dest]){
                    smallest = min(smallest, x.first);
                }
            }
            ans.push_back(smallest);
            node = smallest;
        }
        return ans;
    }
};
int main(){
    
    return 0;
}