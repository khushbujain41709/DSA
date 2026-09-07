// Leetcode 802

// Solution 1
// Any node which is a part of cycle can never be safe node.
// Any node which is connected to the cycle in such manner that node has outgoing edge to the cycle can never be safe node that is anyone leads to the cycle.
// Apart from that all other nodes are safe nodes. So we can find the safe nodes by finding the cycle in the graph and then finding all the nodes which lead to the cycle.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool dfs(vector<vector<int>>& graph, unordered_set<int>& vis, unordered_set<int>& pathVis, int src, vector<int>& check){
        check[src] = 0; // initially mark as unsafe node
        vis.insert(src);
        pathVis.insert(src);
        for(auto x: graph[src]){
            if(!vis.count(x)){
                check[x] = 0;
                if(dfs(graph, vis, pathVis, x, check)) return true;
            }
            else if(pathVis.count(x)){
                check[x] = 0; // cycle node is unsafe node
                // check[src] = 0; // node which leads to cycle is unsafe node
                //imp but we have initially marked check[src] = 0 so no need to mark it again.
                return true;
            }
        }
        check[src] = 1;
        pathVis.erase(src);
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        unordered_set<int> vis;
        int n = graph.size();
        unordered_set<int> pathVis;
        vector<int> check(n, 0); // Initially all nodes are unsafe nodes
        vector<int> ans; // safenodes
        for(int i = 0; i<n; i++){
            if(!vis.count(i)){
                dfs(graph, vis, pathVis, i, check);
            }
        }
        for(int i = 0; i<n; i++){
            if(check[i] == 1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};

// Solution 2 - Topological Sort
// Initially the terminal nodes are those who have outdegree 0 
// but after reversal of edges the terminal nodes becomes those which have indegree 0 
// so we can apply Kahn's algo to find all the nodes connected to it which have linear dependency on the terminal node or is on the path which leads to terminal node 
// so if the nodes is a part of a cycle or points to a cycle , that path cannot lead to terminal node as each node in that path will have cyclic dependency.
class Solution {
public:
    vector<vector<int>> reverse(vector<vector<int>>& graph){
        int n = graph.size();
        vector<vector<int>> graphRev(n);
        for(int i = 0; i<n; i++){
            for(auto neighbour : graph[i]){
                graphRev[neighbour].push_back(i);
            }
        }
        return graphRev;
    }
    vector<int> topologicalSort(vector<vector<int>>& graph){
        vector<int> safe;
        int n = graph.size();
        vector<int> indegree(n, 0);
        for(int i = 0; i<n; i++){
            for(auto neighbour : graph[i]){
                indegree[neighbour]++; // filling of indegree vector
            }
        }
        queue<int> q;
        for(int i = 0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safe.push_back(node);
            for(auto x: graph[node]){
                indegree[x]--;
                if(indegree[x] == 0){
                    q.push(x);
                }
            }
        }
        return safe;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> graphRev(n);
        graphRev = reverse(graph);
        vector<int> safe = topologicalSort(graphRev);
        sort(safe.begin(), safe.end());
        return safe;
    }
};
int main(){
    
    return 0;
}