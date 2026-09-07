// Leetcode 3558
// We need the total cost to be odd.
// The total is odd iff the number of edges assigned weight 1 is odd.
// Suppose there are d edges.
// For every assignment of the first d-1 edges, the last edge is forced:
// If the first d-1 edges contain an even number of 1s → last edge must be 1.
// If they contain an odd number of 1s → last edge must be 2.
// So:
// First d-1 edges:
// each has 2 choices
// Number of possibilities = 2^(d-1)
// And exactly one choice of the last edge makes the total number of 1s odd.
#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
class Solution {
public:
    unordered_map<int, vector<int>> m;
    unordered_set<int> vis;
    void adjacencyList(int u, int v){
        m[u].push_back(v);
        m[v].push_back(u);
    }
    long long pow(long long a, long long b){
        long long res = 1;
        while(b>0){
            if(b & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }
    int max_depth(int depth, vector<vector<int>>& edges){
        queue<pair<int, int>> q;
        // Tree is rooted at node 1 hence pushing node 1
        q.push({1, 0});
        vis.insert(1);
        while(!q.empty()){
            int node = q.front().first;
            int d = q.front().second;
            depth = max(depth, d);
            for(auto x: m[node]){
                if(!vis.count(x)){
                    vis.insert(x);
                    q.push({x, d+1});
                }
            }
            q.pop();
        }
        return depth;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int e = edges.size();
        for(int i = 0; i<e; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adjacencyList(u,v);
        }
        int depth = max_depth(0, edges);
        int ans = (pow(2, depth-1)) % mod;
        return ans;
    }
};
int main(){
    
    return 0;
}