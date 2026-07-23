// https://www.naukri.com/code360/problems/partitions-with-given-difference_3751628
#include<bits/stdc++.h>
using namespace std;
// s1 - s2 = D
// s1 + s2 = total_sum
// so, total_sum - s2 - s2 = D
// s2 = (total_sum - d) / 2
// Now this problem reduces to count subsets with sum equal to K
// Method 1 - Memoization
#include <bits/stdc++.h>
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
int countPartitions(int n, int d, vector<int> &arr) {
    int sum = 0, total_sum = 0;
    for(int i = 0; i<n; i++){
        total_sum += arr[i];
    }
    sum = (total_sum - d) / 2;
	if(total_sum - d < 0 || (total_sum - d) % 2) return 0;
    // total_sum - d must be even and positive
	vector<vector<int>> dp(n+1, vector<int>(sum+1, -1)); 
    return helper(arr, dp, sum, n-1) % MOD;
}

// Method 2 - Tabulation
int countPartitions(int n, int d, vector<int> &arr) {
    int sum = 0, total_sum = 0;
    for(int i = 0; i<n; i++){
        total_sum += arr[i];
    }
    sum = (total_sum - d) / 2;
	if(total_sum - d < 0 || (total_sum - d) % 2) return 0;
    // total_sum - d must be even and positive
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

// Method 3 - Space Optimization
int countPartitions(int n, int d, vector<int> &arr) {
    int sum = 0, total_sum = 0;
    for(int i = 0; i<n; i++){
        total_sum += arr[i];
    }
    sum = (total_sum - d) / 2;
	if(total_sum - d < 0 || (total_sum - d) % 2) return 0;
    // total_sum - d must be even and positive
	vector<int> prev(sum+1, 0), curr(sum+1, 0);
    if(arr[0] == 0){
        prev[0] = 2;
    }
    else prev[0]  = 1;
    if(arr[0] != 0 && sum >= arr[0]) prev[arr[0]] = 1;
    // bcoz when arr[0] == 0, dp[0][0] must be 2 not 1 but for any other arr[0] it must be 1
    for(int i = 1; i<n; i++){
        for(int j = 0; j<=sum; j++){
            int leave = prev[j];
            int take = 0;
            if(j >= arr[i]){
                take = prev[j-arr[i]];
            }
            curr[j] = (take + leave) % MOD;
        }
        prev = curr;
    }
    return prev[sum];
}
int main(){
    
    return 0;
}