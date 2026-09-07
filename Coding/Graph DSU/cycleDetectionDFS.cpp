// We will traverse parent to child but not child to parent.
// Check if visited node is not your parent then there is a cycle.
// Time Complexity : O(V+E) = TC of DFS
#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;
vector<list<int>> graph;
int v;  // number of vertices
void addEdge(int src, int dest, bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir){
        graph[dest].push_back(src);
    }
}
void display(){
    for(int i = 0; i<v; i++){
        cout<<i<<"->";
        for(auto ele : graph[i]){
            cout<<ele<<",";
        }
        cout<<"NULL"<<endl;
    }
}
bool dfs(int src, int parent, unordered_set<int>& visited){
    visited.insert(src);
    for(int neighbour: graph[src]){
        if(visited.count(neighbour)  && parent != neighbour){
            // cycle detected
            return true;
        }
        else if(! visited.count(neighbour)){
            bool res = dfs(neighbour, src, visited);
            if(res == true) return true;
        }
    }
    return false;
}
bool hasCycle(){
    for(int i = 0; i<v; i++){
        unordered_set<int> visited;
        if(!visited.count(i)){
            bool ans = dfs(i, -1, visited); // initially parent is -1
            if(ans == true){
                cout<<"Cycle Detected"<<endl;
                return true;
            }
        }
    }
    return false;
}
int main(){
    cin>>v;
    graph.resize(v, list<int>());
    cout<<"For Undirected Graph : Enter number of edges : ";
    int e; // number of edges
    cin>>e;
    while(e --){
        int src, dest;
        cin>>src>>dest;
        addEdge(src, dest); // bidirectional
    }
    display();
    bool b = hasCycle();
    cout<<b<<endl;
}

