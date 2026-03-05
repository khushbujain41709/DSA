// Leetcode 403
#include<bits/stdc++.h>
using namespace std;
bool helper(vector<int>& stones, vector<vector<int>>& dp, int idx, int dist, unordered_map<int, int>& m){
    int n = stones.size();
    if(idx == n-1){
        return dp[idx][dist] = true;
    }
    if(dp[idx][dist] != -1) return dp[idx][dist];
    for(int i = dist-1; i <= dist+1; i++){
        if(i <= 0) continue;
        int newPos = stones[idx] + i;
        if(m.count(newPos)){ // if new position exists in map
            int newIdx = m[newPos];
            if(helper(stones, dp, newIdx, i, m)){
                return dp[idx][dist] = true;
            }
        }
    }
    return dp[idx][dist] = false;
}
bool canCross(vector<int>& stones) {
    int n = stones.size();
    vector<vector<int>> dp(n, vector<int>(n+1, -1)); // imp - n+1
    unordered_map<int, int> m;
    for(int i = 0; i<n; i++){
        m[stones[i]] = i;
    }
    return helper(stones, dp, 0, 0, m);
}
int main(){
    
    return 0;
}