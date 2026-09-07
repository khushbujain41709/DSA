// We will traverse parent to child but not child to parent.
// Check if visited node is not your parent then there is a cycle.
// Time Complexity : O(V+E) = TC of BFS
#include<iostream>
#include<vector>
#include<list>
#include<queue>
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
bool bfs(int src){
    queue<int> q;
    vector<int> parent;
    unordered_set<int> visited;
    visited.insert(src);
    q.push(src);
    parent.resize(v, -1); // v nodes have v parent but initial node has no parent so -1
    while(!q.empty()){
        int curr = q.front();
        for(auto neighbour: graph[curr]){
            if(visited.count(neighbour) && parent[curr] != neighbour){
                // Cycle detected
                return true;
            }
            else if(! visited.count(neighbour)){
                visited.insert(neighbour);
                q.push(neighbour);
                parent[neighbour] = curr;
            }
        }
        q.pop();
    }
    return false;
}
bool hasCycle(){
    for(int i = 0; i<v; i++){
        unordered_set<int> visited;
        if(!visited.count(i)){
            bool ans = bfs(i);
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

