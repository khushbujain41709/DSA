// Leetcode 547
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_set<int> vis;
    void bfs(int src, vector<vector<int>>& adjList){
        int n = adjList.size();
        queue<int> q;
        q.push(src);
        vis.insert(src);
        while(!q.empty()){
            int node = q.front();
            for(auto x: adjList[node]){
                if(!vis.count(x)){
                    vis.insert(x);
                    q.push(x);
                }
            }
            q.pop();
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjList(n, vector<int>());
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(isConnected[i][j]){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        int count = 0;
        for(int i = 0; i<n; i++){
            if(!vis.count(i)){
                bfs(i, adjList);
                count++;
            }
        }
        return count;
    }
};
int main(){
    
    return 0;
}