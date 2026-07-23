// Leetcode 2316
// We need to find the size of each connected component. Use DSU.
// For example, Component1 has a nodes, component2 has b nodes and component3 has c nodes then answer is: a*b + a*c + b*c but this will give TLE due to O(N^2) TC.
/*
Method 1 is : Suppose nodes in components are: 3, 4, 2, 5
using suffix sum
so ans is 3*4 + 3*2  + 3*5 + 4*4 + 4*5 + 2*5
ans = 3*(4+2+5) + 4*(2+5) + 2*(5)
*/
/*
Method 2 is : Suppose nodes in components are: 3, 4, 2, 5
using formula: (size of component - (remaining nodes - size of component))
In remaining nodes here, we consider nodes after the connected  component
subtract current node from remaining nodes in each iteration
*/
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
void dfs(int node, unordered_set<int>& visited, int& size){
    visited.insert(node);
    size++; // count this node
    for(auto neighbour: graph[node]){
        if(not visited.count(neighbour)){
            dfs(neighbour, visited,size);
        }
    }
}
vector<int> sizeOfComponents;
int connectedComponents(){ // here we just want size of each connected component
    unordered_set<int> visited;
    int count = 0;
    sizeOfComponents.clear();
    for(int i = 0; i<vertices; i++){
        int size = 0;
        if(visited.count(i) == 0){
            count++;
            dfs(i, visited, size);
            sizeOfComponents.push_back(size);
        }
    }
    return count;
}
long long countPairs(int n, vector<vector<int>>& edges){
    vertices = n;
    graph.resize(n, list<int>());
    for(int i = 0; i<edges.size(); i++){
        addEdge(edges[i][0], edges[i][1]);
    }
    connectedComponents();
    long long pairs = 0;
    long long sum = 0;
    for(int i = 0; i<sizeOfComponents.size(); i++){
        sum += (long long)sizeOfComponents[i];
    }
    for(int i = 0; i<sizeOfComponents.size(); i++){
        pairs += (long long)sizeOfComponents[i]*(sum - (long long)sizeOfComponents[i]);
        sum -= (long long)sizeOfComponents[i];
    }
    return pairs;
}
int main(){
    
}