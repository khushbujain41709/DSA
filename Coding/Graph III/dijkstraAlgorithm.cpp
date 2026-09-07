// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

// Dijkstra Algorithm is not applicable with any negative weight edge or negative edge weight cycle.

// In an undirected graph, a negative edge automatically creates a negative cycle.
// Example:
// 0 --(-2)-- 1
// Since the graph is undirected:
// 0 → 1 = -2
// 1 → 0 = -2

// Cycle cost:
// 0 → 1 → 0
// = -2 + (-2)
// = -4

// Every time we traverse this cycle, the distance decreases by 4:
// 0 → -4 → -8 → -12 → ...
// Hence there is no finite shortest path. It will fall in an infinite loop. Dijkstra's algorithm will not work in this case.

// This code will give correct answers if we replace priority queue with a simple queue. But the time complexity will be O(V^2) instead of O(ElogV) as in Dijkstra's algorithm. Queue will generate unnecessary paths following a brute force solution. So prefer priority queue.

// Initially:
// dist[0] = 0

// 0 → 1:
// dist[1] = -2

// 1 → 0:
// dist[0] = -4

// 0 → 1:
// dist[1] = -6

// 1 → 0:
// dist[0] = -8

// 0 → 1:
// dist[1] = -10
// ...

// This is why Dijkstra's algorithm requires all edge weights to be non-negative.

// Using priority queue, we can get the minimum distance node in O(logV) time. Hence the overall time complexity of Dijkstra's algorithm is O(ElogV).
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        int m = edges.size();
        vector<vector<pair<int, int>>> graph(V);
        for(int i = 0; i<m; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // In priority queue insert distance that is weight first and then insert node as a pair.
        pq.push({0, src});
        vector<int> shortestDis(V, INT_MAX);
        shortestDis[src] = 0;
        while(!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto x: graph[node]){
                // x.first is node
                // x.second id dist
                int distance = dist + x.second;
                if(distance < shortestDis[x.first]){
                    shortestDis[x.first] = distance;
                    pq.push({distance, x.first});
                }
            }
        }
        return shortestDis;
    }
};

// Using set 
// Set stores every element in ascending order and stores minimum at the top.
// We are using set so that we can use set.erase() operration which takes lograithmic time. This operation removes the already existing paths saving unnecessary iterations.
// Time complexity changes minutely and both priority_queue and set approach has nearly same TC.
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        int m = edges.size();
        vector<vector<pair<int, int>>> graph(V);
        for(int i = 0; i<m; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }
        set<pair<int, int>> s;
        // In set insert distance that is weight first and then insert node as a pair.
        s.insert({0, src});
        vector<int> shortestDis(V, INT_MAX);
        shortestDis[src] = 0;
        // For a set, the smallest pair is always at: s.begin()
        // s.begin() is an iterator, so use ->
        while(!s.empty()){
            int dist = s.begin()->first;
            int node = s.begin()->second;
            s.erase({dist, node});
            for(auto x: graph[node]){
                // x.first is node
                // x.second id dist
                int distance = dist + x.second;
                if(shortestDis[x.first] != INT_MAX && distance < shortestDis[x.first]){
                    s.erase({shortestDis[x.first], x.first}); // IMP Change
                }
                if(distance < shortestDis[x.first]){
                    shortestDis[x.first] = distance;
                    s.insert({distance, x.first});
                }
            }
        }
        return shortestDis;
    }
};
int main(){
    
    return 0;
}
// Dijkstra's Algorithm — Why Priority Queue instead of Queue + Time Complexity
// 1. Why can a normal Queue work?

// A normal queue can still eventually give the correct shortest distances, but it may process many unnecessary paths.

// Example:

// Source = 0

// 0 → 1 = 3
// 0 → 2 = 1

// 1 → 3 = 4
// 2 → 3 = 2

// Starting from node 0:

// Queue: (0,0)

// Process 0:

// dist[1] = 3  → push (3,1)
// dist[2] = 1  → push (1,2)

// Queue:
// (3,1), (1,2)

// Because it is a normal Queue, (3,1) comes out first.

// Process node 1:

// Distance to 3 = 3 + 4 = 7

// dist[3] = 7
// push (7,3)

// Then:

// Process node 2:

// Distance to 3 = 1 + 2 = 3

// dist[3] improves:

// 7 → 3

// push (3,3)

// Now we have:

// (7,3)
// (3,3)

// The (7,3) path is unnecessary because we already found a better path with distance 3.

// A normal queue explores paths in insertion order, which can lead to processing worse paths before better ones.

// 2. Why Priority Queue?

// A Priority Queue always gives us:

// Minimum Distance First

// Instead of:

// FIFO order

// So if the PQ contains:

// (7, 3)
// (3, 3)

// the Priority Queue processes:

// (3, 3) first

// This follows the greedy idea:

// Always explore the currently smallest distance first.

// This reduces unnecessary exploration and makes Dijkstra efficient.

// 3. Priority Queue Format

// Store:

// {distance, node}

// because C++ min-priority behavior should prioritize the smallest distance.

// Example:

// {0, 0}
// {3, 1}
// {1, 2}

// The PQ gives:

// {1, 2}

// before:

// {3, 1}
// 4. Dijkstra's Core Idea
// 1. Set all distances = Infinity.

// 2. Source distance = 0.

// 3. Insert {0, source}.

// 4. Take the node having minimum distance.

// 5. Traverse all its neighbors.

// 6. Calculate:

//    newDistance =
//    currentDistance + edgeWeight

// 7. If:

//    newDistance < shortestDistance[neighbor]

//    then update the distance.

// 8. Push the new {distance, node}.

// 9. Repeat until the PQ becomes empty.
// 5. Why O(E log V)?

// The commonly used complexity is:

// O(E log V)

// Where:

// V = number of vertices
// E = number of edges
// Operations

// For every useful edge relaxation:

// Push into Priority Queue → O(log heap size)
// Pop from Priority Queue  → O(log heap size)

// Across the graph, edge relaxations can cause up to O(E) heap insertions/processing operations, and the logarithmic heap factor is O(log V) in the standard complexity expression.

// Therefore:

// O(E × log V)
// One-Line Interview Answer
// Dijkstra uses a Priority Queue because it always processes the node with the smallest currently known distance first. A normal queue may process longer paths before shorter ones, causing unnecessary relaxations and repeated processing. The Priority Queue implements Dijkstra's greedy strategy efficiently, giving a time complexity of O(E log V).
// Quick Memory Trick
// Queue:
// First In → First Out
// May process unnecessary longer paths.

// Priority Queue:
// Minimum Distance → First Out
// Processes shortest candidate first.

// Dijkstra = Greedy + Minimum Distance First