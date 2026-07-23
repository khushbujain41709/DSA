// Leetcode 947
// If 2 nodes share their nodes then they are in a same component or if 2 nodes share their columns then they are in the same component.
// Answer = Number of nodes - number of connected components
// Intution - Use DFS to traverse in a graph forming a tree structure without repeating nodes. Now if we kill nodes level by level, that is all leaf nodes first then level above leaf nodes and so on. Only root will be left which will never be killed. So each connected component gives one node that is root.
#include<iostream>
#include<unordered_set>
#include<vector>
#include<list>
#include<unordered_map>
using namespace std;
vector<list<int>> graph;
int vertices;
void addEdge(int src, int dest, bool di_dir = true){
    graph[src].push_back(dest);
    if(di_dir){
        graph[dest].push_back(src);
    }
}
void dfs(int node, unordered_set<int>& visited){
    visited.insert(node);
    for(auto neighbour: graph[node]){
        if(not visited.count(neighbour)){
            dfs(neighbour, visited);
        }
    }
}
int connectedComponents(){
    unordered_set<int> visited;
    int count = 0;
    for(int i = 0; i<vertices; i++){
        if(visited.count(i) == 0){
            count++;
            dfs(i, visited);
        }
    }
    return count;
}
int removeStones(vector<vector<int>>& stones){
    int n = stones.size();
    vertices = n;
    graph.resize(vertices);
    unordered_map<int, vector<int>> rowMap, colMap;
    for(int i = 0; i<n; i++){
        rowMap[stones[i][0]].push_back(i); // store the index
        colMap[stones[i][1]].push_back(i); // suppose nodes are 0,2,3
    }
    for(auto x: rowMap){
        for(int i = 1; i<x.second.size(); i++){
            addEdge(x.second[i-1], x.second[i]);
        }
    }
    for(auto x: colMap){
        for(int i = 1; i<x.second.size(); i++){
            addEdge(x.second[i-1], x.second[i]);
            // connect 0-2, 2-3
        }
    }
    return n - connectedComponents();
}
int main(){
    
}