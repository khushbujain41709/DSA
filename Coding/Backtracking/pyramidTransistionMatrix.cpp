// Leetcode 756
#include<bits/stdc++.h>
using namespace std;
unordered_map<string, bool> dp;
bool dfs(string bottom, unordered_map<string, vector<char>>& m){
    if(bottom.size() == 1){
        return true;
    }
    if(dp.count(bottom)){
        return dp[bottom];
    }
    vector<string> nextRows;
    isPossible(bottom, 0, nextRows, m, "");
    for(int i = 0; i<nextRows.size(); i++){
        if(dfs(nextRows[i], m)){
            return dp[bottom] = true;
        }
    }
    return dp[bottom] = false;
}
void isPossible(string bottom, int idx, vector<string>& nextRows, unordered_map<string, vector<char>>& m, string curr){
    if(idx == bottom.size() - 1){
        nextRows.push_back(curr);
        return;
    }
    string key = "";
    key += bottom[idx];
    key += bottom[idx+1];
    if(m.find(key) == m.end()){
        return;
    }
    for(int i = 0; i<m[key].size(); i++){
        isPossible(bottom, idx+1, nextRows, m, curr + m[key][i]);
    }
}
bool pyramidTransition(string bottom, vector<string>& allowed) {
    int n = allowed.size();
    unordered_map<string, vector<char>> m;
    for(int i = 0; i<n; i++){
        string p = allowed[i].substr(0,2);
        m[p].push_back(allowed[i][2]);
    }
    return dfs(bottom, m);
}
int main(){
    
    return 0;
}