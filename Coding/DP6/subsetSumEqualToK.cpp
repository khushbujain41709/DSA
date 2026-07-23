// https://www.naukri.com/code360/problems/subset-sum-equal-to-k_1550954
// f(n-1, target) -> In the entire array till the index n-1, does there exists target?
// Express everything in terms of index and target.
#include<bits/stdc++.h>
using namespace std;
// Method 1 - Memoization
bool helper(vector<int>& arr, int k, vector<vector<int>>& dp, int idx){
    int n = arr.size();
    if(k == 0) return true;
    if(idx == 0){
        return (arr[0] == k);
    }
    if(dp[idx][k] != -1) return dp[idx][k];
    bool notTake = helper(arr, k, dp, idx-1);
    bool take = false;
    if(k >= arr[idx]){
        take = helper(arr, k-arr[idx], dp, idx-1);
    }
    return dp[idx][k] = take||notTake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
    return helper(arr, k, dp, n-1);
}
// Method 2 - Tabulation
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n+1, vector<bool>(k+1, 0));
    // row of table signify: till this no. of element in array, the target can be achieved or not.
    // column of table signify: whether we can obtain that target or not.
    for(int i = 0; i<n; i++){
        dp[i][0] = true;
    }
    dp[0][arr[0]] = true;
    for(int i = 1; i<n; i++){
        for(int j = 1; j<=k; j++){
            bool take = 0;
            if(j >= arr[i]){
                take = dp[i-1][j-arr[i]];
            } 
            bool notTake = dp[i-1][j];
            dp[i][j] = take || notTake;
        }
    }
    return dp[n-1][k];
}
// Method 3 - Space Optimization
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> dp(k+1), curr(k+1);
    dp[0] = true;
    curr[0] = true;
    if(arr[0] <= k){
        dp[arr[0]] = true;
    }
    for(int i = 1; i<n; i++){
        for(int j = 1; j<=k; j++){
            bool take = 0;
            if(j >= arr[i]){
                take = dp[j-arr[i]];
            } 
            bool notTake = dp[j];
            curr[j] = take || notTake;
        }
        dp = curr;
    }
    return dp[k];
}
int main(){
    
    return 0;
}