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
#include<iostream>
#include<list>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;
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