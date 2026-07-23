// Leetcode 474
#include<bits/stdc++.h>
using namespace std;
vector<vector<vector<int>>> dp; // memo table: index, m, n - 3D dp
int countZero(string& s){
    int n = s.size();
    int count = 0;
    for(int i = 0; i<n; i++){
        if(s[i] == '0'){
            count++;
        }
    }
    return count;
}
int countOne(string& s){
    int n = s.size();
    int count = 0;
    for(int i = 0; i<n; i++){
        if(s[i] == '1'){
            count++;
        }
    }
    return count;
}
int helper(vector<pair<int, int>>& count, int i, int m, int n){
    if(i == count.size()) return 0;
    if(dp[i][m][n] != -1) return dp[i][m][n];
    // case 1 : take
    int take = 0;
    if(m >= count[i].first && n >= count[i].second){
        take = 1 + helper(count, i+1, m-count[i].first, n-count[i].second); // imp
    }
    // case 2 : leave
    int leave = helper(count, i+1, m, n);
    return dp[i][m][n] = max(take, leave);
}
int findMaxForm(vector<string>& strs, int m, int n) {
    dp.clear();
    dp.resize(601, vector<vector<int>>(101, vector<int>(101, -1)));
    int size = strs.size();
    vector<pair<int, int>> count;
    for(int i = 0; i<size; i++){
        int z = countZero(strs[i]);
        int o = countOne(strs[i]);
        count.push_back({z,o});
    }
    return helper(count, 0, m, n);
}
int main(){
    
    return 0;
}