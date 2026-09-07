// Topological Sorting - Exists only for Directed Acyclic Graphs (DAGs). Linear ordering of vertices such that for every directed edge u->v, vertex u comes before v in the ordering.

#include<iostream>
#include<list>
#include<vector>
#include<unordered_set>
#include<queue>
#include<stack>
using namespace std;
// Solution 1:
// Using DFS and stack
// https://www.geeksforgeeks.org/problems/topological-sort/1
class Solution {
  public:
    void dfs(vector<vector<int>>& graph, unordered_set<int>& vis, int src, stack<int>& st){
        vis.insert(src);
        for(auto x: graph[src]){
            if(!vis.count(x)){
                dfs(graph, vis, x, st);
            }
        }
        st.push(src);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        stack<int> st;
        int m = edges.size();
        vector<vector<int>> graph(V);
        for(int i = 0; i<m; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
        }
        unordered_set<int> vis;
        for(int i = 0; i<V; i++){
            if(!vis.count(i)){
                dfs(graph, vis, i, st);
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};

// Solution 2:
// 1. Kahn’s Algorithm (Indegree-Based)Indegree: The number of incoming edges pointing to a node.
// Step 1: Calculate the indegree for every node in the graph.
// Step 2: Place all nodes with an indegree of 0 into a queue.
// Step 3: Remove a node from the queue, add it to your sorted order, and reduce the indegree of its neighbors by 1.
// Step 4: If any neighbor's indegree drops to 0, add it to the queue. Repeat until the queue is empty.
// Using BFS and Kahn's Algorithm
/*
8
11
0 2
1 2
2 4
4 6
2 6
2 5
2 3
1 3
3 5
5 6
6 7
0 1 2 4 3 5 6 7 
*/
// If topological sort does not have all vertices then graph has a cycle.
// Topological sorting only exists for directed acyclic graph.
vector<list<int>> graph;
void addEdge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir){
        graph[dest].push_back(src);
    }
}
void topologicalBFS(int v){ // number of vertices
    queue<int> q;
    unordered_set<int> visited;
    vector<int> indegree(v,0); // size - v initialized with 0 degrees
    for(int i = 0; i<v; i++){
        for(auto neighbour : graph[i]){
            indegree[neighbour]++; // filling of indegree vector
        }
    }
    for(int i = 0; i<v; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    while(! q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        for(auto neighbour : graph[node]){
            if(not visited.count(neighbour)){ // if unvisited
                indegree[neighbour]--;
                if(indegree[neighbour] == 0){
                    q.push(neighbour);
                    visited.insert(neighbour);
                }
            }
        }
    }
}
int main(){
    int v;
    cin>>v;
    int e;
    cin>>e;
    graph.resize(v, list<int>());
    while(e--){
        int src, dest;
        cin>>src>>dest;
        addEdge(src, dest, false); // DAG is directed acyclic graph
    }
    topologicalBFS(v);
    return 0;
}