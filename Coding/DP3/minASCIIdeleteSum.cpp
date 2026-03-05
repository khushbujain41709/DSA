// Leetcode 712
#include<iostream>
#include<vector>
using namespace std;
// Method 1: Memoization
vector<vector<int>> dp;
int del(string& s1, string& s2, int i, int j){ 
    // Remember to pass s1 and s2 by reference.
    if(i < 0){
        int sum = 0;
        while(j>=0){
            sum += (int)s2[j];
            j--;
        }
        return sum;
    };
    if(j < 0){
        int sum = 0;
        while(i>=0){
            sum += (int)s1[i];
            i--;
        }
        return sum;
    }
    if(dp[i][j] != -1) return dp[i][j];
    // If characters match → no deletion needed
    if(s1[i] == s2[j]){
        return dp[i][j] = del(s1, s2, i-1, j-1);
    }
    // Either delete s1[i] or delete s2[j]
    int del1 = del(s1, s2, i-1, j) + (int)s1[i];
    int del2 = del(s1, s2, i, j-1) + (int)s2[j];
    return dp[i][j] = min(del1, del2);
}
int minimumDeleteSum(string& s1, string& s2){
    int n = s1.size();
    int m = s2.size();
    dp.resize(n+1, vector<int>(m+1, -1));
    int ans = del(s1, s2, n-1, m-1);
    return ans;
}

// Method 2: Tabulation
int minimumDeleteSum(string s1, string s2){
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    // loop starts from i = 1, so s[i-1] is s[0]
    for(int i = 1; i<=n; i++){
        dp[i][0] = dp[i-1][0] + s1[i-1];
    }
    for(int j = 1; j<=m; j++){
        dp[0][j] = dp[0][j-1] + s2[j-1];
    }
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            } 
            else{
                dp[i][j] = min(
                    dp[i-1][j] + s1[i-1],
                    dp[i][j-1] + s2[j-1]
                );
            }
        }
    }
    return dp[n][m];
}
int main(){
    
    return 0;
}