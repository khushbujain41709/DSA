// https://takeuforward.org/plus/dsa/problems/frog-jump-with-k-distances
#include<bits/stdc++.h>
using namespace std;
int frogJump(vector<int>& heights, int k){
    int n = heights.size();
    vector<int> dp(n, 0);
    dp[0] = 0;
    for(int i = 1; i<n; i++){
        int ans = INT_MAX;
        for(int j = 1; j<=k; j++){
            if(i >= j){ // imp
                int val = dp[i-j] + abs(heights[i] - heights[i-j]);
                ans = min(ans, val);
            }
        }
        dp[i] = ans;
    }
    return dp[n-1];
}
int main(){
    return 0;
}