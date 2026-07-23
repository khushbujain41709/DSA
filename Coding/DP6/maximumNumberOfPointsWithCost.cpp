// Leetcode 1937
#include<bits/stdc++.h>
using namespace std;
// Method 1 - Memoization but giving TLE
// TC = O(m * n²)
typedef long long ll;
class Solution {
public:
    ll helper(int i, int j, vector<vector<int>>& points, vector<vector<ll>>& dp){
        int m = points.size();
        int n = points[0].size();
        if(dp[i][j] != -1) return dp[i][j];
        if(i == m-1) return points[i][j];
        ll ans = LLONG_MIN;
        for(int idx = 0; idx<n; idx++){
            ans = max(ans, (ll)points[i][j] + helper(i+1, idx, points, dp) - (ll)abs(idx - j));
        }
        return dp[i][j] = ans;
    }
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        vector<vector<ll>> dp(m+1, vector<ll>(n+1, -1));
        ll ans = LLONG_MIN;
        for(int i = 0; i<n; i++){
            ans = max(ans, helper(0, i, points, dp));
        }
        return ans;
    }
};

// Method 2 - TC = O(m*n)
typedef long long ll;
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        vector<ll> dp(n);
        ll ans = LLONG_MIN;
        // Because first row has no movement cost.
        for(int i = 0; i<n; i++){
            dp[i] = points[0][i];
        }
        for(int i = 1; i<m; i++){ // traverse each row and compute left, right and newdp
            vector<ll> left(n), right(n), newdp(n);
            left[0] = dp[0];
            for(int j = 1; j<n; j++){
                left[j] = max(left[j-1]-1, dp[j]);
            }
            right[n-1] = dp[n-1];
            for(int j = n-2; j>=0; j--){
                right[j] = max(right[j+1]-1, dp[j]);
            }
            for(int j = 0; j<n; j++){
                newdp[j] = points[i][j] + max(left[j], right[j]);
            }
            dp = newdp;
        }
        for(int i = 0; i<n; i++){
            ans = max(ans, dp[i]); // ans will be stored in old dp and newdp will be at index m
        }
        return ans;
    }
};
/*
Transition formula:
dp[i][j] = points[i][j] + max_k ( dp[i+1][k] - |k-j| )

Split the absolute value:
Case 1: k ≤ j
dp[i+1][k] - (j-k) = (dp[i+1][k] + k) - j
Case 2: k ≥ j
dp[i+1][k] - (k-j) = (dp[i+1][k] - k) + j
*/
// dp[j] = maximum score reaching column j in the current row
// left[j] = best value reaching j from the left side
/*
Example:
dp = [5, 3, 4]. Compute left.
left[0] = 5, Now:
left[1] = max(dp[1], left[0] - 1) = max(3, 5-1) = 4 
// 5-1 means agar 5 ko choose nhi krte hai toh maximum 5-1 ho skta hai next.
left[2] = max(dp[2], left[1] - 1) = max(4, 3-1) = 4
Result: left = [5,4,4]
*/
int main(){
    
    return 0;
}