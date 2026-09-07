// Leetcode 399
#include<bits/stdc++.h>
using namespace std;
// We can't make vector<vector<pair<string, double>>> graph as graph[s1] doesnot exist. If s1 is a string, because vector only accepts an integer index.
// As graph is a vector, so graph[u] expects an integer index, not a string.
// Hence using map
class Solution {
public:
    bool dfs(string s1, string s2, unordered_map<string, vector<pair<string, double>>>& graph, unordered_set<string>& vis, double& val){
        vis.insert(s1);
        for(auto x: graph[s1]){
            if(!vis.count(x.first)){
                val *= x.second;
                if(x.first == s2){
                    return true;
                }
                else{
                    if(dfs(x.first, s2, graph, vis, val) == true) return true;
                }
                val = val/x.second;
            }
        }
        return false;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        unordered_map<string, vector<pair<string, double>>> graph;
        for(int i = 0; i<n; i++){
            string u = equations[i][0];
            string v = equations[i][1];
            double w1 = values[i];
            double w2 = 1/w1;
            graph[u].push_back({v, w1});
            graph[v].push_back({u, w2});
        }
        vector<double> ans;
        int m = queries.size();
        for(int i = 0; i<m; i++){
            string v1 = queries[i][0];
            string v2 = queries[i][1];
            unordered_set<string> vis;
            double val = 1;
            if(!graph.count(v1) || !graph.count(v2)){
                val = -1;
                ans.push_back(val);
            }
            else if(v1 == v2){
                val = (double)1;
                ans.push_back(val);
            }
            else{
                if(dfs(v1, v2, graph, vis, val) == true){
                    ans.push_back(val);
                }
                else{
                    ans.push_back((double)-1);
                }
            }
        }
        return ans;
    }
};
int main(){
    
    return 0;
}