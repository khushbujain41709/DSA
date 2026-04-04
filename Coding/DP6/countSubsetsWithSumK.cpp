// https://www.naukri.com/code360/problems/count-subsets-with-sum-k_3952532
#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int helper(vector<int>& arr, vector<vector<int>>& dp, int k, int idx){
	if(idx < 0) return 0;
	if(idx == 0){
		if(k == 0 && arr[0] == 0) return 2;
		if(k == 0 || k == arr[0]) return 1;
		else return 0;
	}
	// if(k == 0){ 
	//  instead of returning from here we need to go deep in recursion
	// 	return 1;
	// }
	if(dp[idx][k] != -1) return dp[idx][k];
	int leave = helper(arr, dp, k, idx-1);
	int take = 0;
	if(k >= arr[idx]){
		take = helper(arr, dp, k-arr[idx], idx-1);
	}
	return dp[idx][k] = (take + leave) % MOD;
}
int findWays(vector<int>& arr, int k){
	int n = arr.size();
	vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
	return helper(arr, dp, k, n-1) % MOD;
}
// Method 2 - Tabulation
int findWays(vector<int>& arr, int sum){
	int n = arr.size();
	vector<vector<int>> dp(n+1, vector<int>(sum+1, 0)); 
    if(arr[0] == 0){
        dp[0][0] = 2;
    }
    else dp[0][0]  = 1;
    if(arr[0] != 0 && sum >= arr[0]) dp[0][arr[0]] = 1;
    // bcoz when arr[0] == 0, dp[0][0] must be 2 not 1 but for any other arr[0] it must be 1
    for(int i = 1; i<n; i++){
        for(int j = 0; j<=sum; j++){
            int leave = dp[i-1][j];
            int take = 0;
            if(j >= arr[i]){
                take = dp[i-1][j-arr[i]];
            }
            dp[i][j] = (take + leave) % MOD;
        }
    }
	return dp[n-1][sum];
}
int main(){
    
    return 0;
}