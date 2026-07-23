#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> graph;
void create(int u, int v, int w){
    graph[u].push_back({v,w});
    return;
}
set<pair<int, int>> vis;
int val = 0;
// The global variable is hidden by the parameter. Remove the global one.
void dfs(int src, int& val){
    // You should only mark nodes as visited not pairs as
    // The set contains {3,5} - If another edge {3,7} comes, vis.count({3,7}) returns 0, so DFS visits node 3 again.
    vis.insert({src, 0});
    for(auto x: graph[src]){
        if(!vis.count(x)){
            vis.insert({x.first, x.second}); // error
            val += x.second;
            return dfs(x.first, val); // don't use return keyword here
        }
    }
}
int fun(int n, int m, vector<vector<int>>& edges){
    graph.resize(n);
    // resize it to n+1
    for(int i = 0; i<m; i++){
        // cin>>edges[i][0] >> edges[i][1] >> edges[i][2];
        create(edges[i][0], edges[i][1], edges[i][2]);
    }
    int maxx = INT_MIN;
    for(int i = 1; i<=n; i++){
        val = 0;
        vis.clear();
        dfs(i, val);
        maxx = max(maxx, val);
    }
    return maxx;
}
int main(){
    vector<vector<int>> edges = 
    {{1,2,5}, {2,3,10}, {3,4,10}, {1,3, 15}, {2,4, 20}};
    cout<<fun(4, 5, edges);
}