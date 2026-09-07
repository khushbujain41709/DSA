// Leetcode 3310
#include<bits/stdc++.h>
using namespace std;
// Soution 1 - TLE 
class Solution {
public:
    void dfs(unordered_set<int>& vis, int k, vector<vector<int>>& adjList){
        vis.insert(k);
        for(auto x: adjList[k]){
            if(!vis.count(x)){
                dfs(vis, x, adjList);
            }
        }
    }
    bool find(int i, unordered_set<int>& travel, unordered_set<int>& temp, vector<vector<int>>& adjList){
        temp.insert(i);
        for(auto x: adjList[i]){
            if(travel.count(x)){
                return true;
            }
            if(!temp.count(x)){
                if(find(x, travel, temp, adjList) == true){
                    return true;
                }
            }
        }
        return false;
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adjList(n);
        int m = invocations.size();
        for(int i = 0; i<m; i++){
            int u = invocations[i][0];
            int v = invocations[i][1];
            adjList[u].push_back(v);
        }
        unordered_set<int> vis;
        dfs(vis, k, adjList);
        unordered_set<int> travel;
        for(auto x: vis){
            travel.insert(x);
        }
        bool flag = false;
        vector<int> ans;
        for(int i = 0; i<n; i++){
            unordered_set<int> temp;
            if(!vis.count(i)){
                bool res = find(i, travel, temp, adjList);
                if(res){
                    for(int i = 0; i<n; i++){
                        ans.push_back(i);
                    }
                    return ans;
                }
            }
        }
        for(int i = 0; i<n; i++){
            if(!travel.count(i)) ans.push_back(i);
        }
        return ans;
    }
};

// Solution 2
class Solution {
public:
    void dfs(unordered_set<int>& vis, int k, vector<vector<int>>& adjList){
        vis.insert(k);
        for(auto x: adjList[k]){
            if(!vis.count(x)){
                dfs(vis, x, adjList);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adjList(n);
        int m = invocations.size();
        for(int i = 0; i<m; i++){
            int u = invocations[i][0];
            int v = invocations[i][1];
            adjList[u].push_back(v);
        }
        unordered_set<int> vis;
        dfs(vis, k, adjList);
        vector<int> ans;
        for(int i = 0; i<m; i++){
            int u = invocations[i][0];
            int v = invocations[i][1];
            if(!vis.count(u)){
                if(vis.count(v)){
                    for(int i = 0; i<n; i++){
                        ans.push_back(i);
                    }
                    return ans;
                }
            }
        }
        for(int i = 0; i<n; i++){
            if(!vis.count(i)) ans.push_back(i);
        }
        return ans;
    }
};
int main(){
    
    return 0;
}