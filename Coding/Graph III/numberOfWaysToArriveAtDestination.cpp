// Leetcode 1976
// Ways to arrive at a node is: node1 -> node, node2 -> node, node3 -> node
// Ways[node] = Ways[node1] + Ways[node2] + Ways[node3] recursively
#include<bits/stdc++.h>
using namespace std;
// if(newDist < dist[v]) {
//     dist[v] = newDist;
//     ways[v] = ways[u];       // RESET
// }
// else if(newDist == dist[v]) {
//     ways[v] += ways[u];      // ADD
// }
const int mod = 1e9 + 7;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int m = roads.size();
        vector<vector<pair<int, int>>> graph(n);
        for(int i = 0; i<m; i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
        priority_queue<pair< long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<int> ways(n, 0);
        vector<long long> distArr(n, LLONG_MAX);
        ways[0] = 1; // we can reach node 0 in 1 way
        distArr[0] = 0LL;
        pq.push({0, 0}); // Insert distance first and then insert node
        while(! pq.empty()){
            long long dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto x: graph[node]){
                // x.first = node
                // x.second = distance
                long long distance = dist + (long long)x.second;
                if(distance < distArr[x.first]){
                    distArr[x.first] = distance;
                    // Suppose node 3 was previously reachable in: 10 ways with distance 20.
                    // Now you discover a shorter path with distance 10, and there are 2 ways to reach it.
                    // The old 10 ways are useless because they correspond to a longer distance.
                    // So: ways[3] = 2
                    ways[x.first] = ways[node] % mod;
                    pq.push({distance, x.first});
                }
                else if(distance == distArr[x.first]){
                    // do not re push same entry in priority queue
                    ways[x.first] = (ways[x.first] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1] % mod;
    }
};
int main(){
    
    return 0;
}