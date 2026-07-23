#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> graph;
void create(int u, int v, int w){
    graph[u].push_back({v,w});
    return;
}
set<int> vis;
int val = 0;
void dfs(int src, int& val){
    vis.insert(src);
    for(auto x: graph[src]){
        if(!vis.count(x.first)){
            vis.insert(x.first);
            val += x.second;
            return dfs(x.first, val);
        }
    }
}
int fun(int n, int m, vector<vector<int>>& edges){
    graph.resize(n+1);
    for(int i = 0; i<m; i++){
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
    {{1,2,5}, {2,3,10}, {3,4,10}, {1,3,15}, {2,4,20}};
    cout<<fun(4, 5, edges);
}