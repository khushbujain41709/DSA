// Leetcode 1466
// Treat the graph as undirected. Start a dfs from the root, if you come across an edge in the forward direction, you need to reverse the edge.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int root, vector<vector<int>>& graph, int& count, set<pair<int, int>>& s, unordered_set<int>& vis){
        for(auto x: graph[root]){
            if(!vis.count(x)){
                vis.insert(x);
                if(s.count({root, x})) count++;
                dfs(x, graph,count, s, vis);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        set<pair<int, int>>s;
        vector<vector<int>> graph(n);
        for(int i = 0; i<n-1; i++){
            int u = connections[i][0];
            int v = connections[i][1];
            s.insert({u,v});
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int ans = 0;
        unordered_set<int> vis;
        vis.insert(0); // imp
        dfs(0, graph, ans, s, vis);
        return ans;
    }
};
int main(){
    
    return 0;
}