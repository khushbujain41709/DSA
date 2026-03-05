// Leetcode 207
#include<iostream>
#include<list>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;
vector<list<int>> graph;
void addEdge(vector<vector<int>>& prerequisites, int numCourses){
    graph.resize(numCourses, list<int>());
    for(int i = 0; i<prerequisites.size(); i++){
        graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }
}
bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
    queue<int> q;
    addEdge(prerequisites, numCourses);
    int v = numCourses;
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
    vector<int> topologicalOrder;
    while(! q.empty()){
        int node = q.front();
        q.pop();
        topologicalOrder.push_back(node);
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
    if(topologicalOrder.size() != numCourses){
        return false;
    }
    else return true;
}
int main(){
    
    return 0;
}