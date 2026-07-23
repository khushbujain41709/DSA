// Leetcode 2492
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<pair<int, int>>> graph;
    unordered_set<int> vis;
    void adjMat(int s, int d, int w){
        graph[s].push_back({d,w});
        graph[d].push_back({s,w});
    }
    void dfs(int s, int& minn){
        vis.insert(s);
        for(auto neigh : graph[s]){
            minn = min(minn, neigh.second);
            if(!vis.count(neigh.first)){
                vis.insert(neigh.first);
                dfs(neigh.first, minn);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        int m = roads.size();
        graph.resize(n+1);
        for(int i = 0; i<m; i++){
            int s = roads[i][0];
            int d = roads[i][1];
            int w = roads[i][2];
            adjMat(s,d,w);
        }
        int minn = INT_MAX;
        dfs(1, minn);
        return minn;
    }
};
int main(){
    cout<<(int)'9';
    return 0;
}