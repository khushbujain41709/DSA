#include<bits/stdc++.h>
using namespace std;
// Valid for - https://www.naukri.com/code360/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494
// Only valid for non negative numbers
// From subset sum equal to K tabulation problem, we can say that:
// If we check for a target = K, we can derive if every possible target between 1 and K is possible or not.
// row of table signify: till this no. of element in array, the target can be achieved or not.
// column of table signify: whether we can obtain that target or not.
// Here we will create two sets S1 and S2.
// S1 contains all possible combination of elements and S1 contains remianing elements. Sum of S2 = Total sum - S1.
// For we try to create S1.
// S1 is created using tabulation of subset sum equals K where last row of this table gives whether for size of array n we can achieve target or not. Target will range like this:
// Here sum of all elements is maximum target and 0 is the minimu target we chose zero element in S1.
int minSubsetSumDifference(vector<int>& nums, int n){
    int total_sum = 0;
    for(int i = 0; i<n; i++){
        total_sum += nums[i];
    }
    int minSum = 0;
    int maxSum = total_sum;
    vector<vector<bool>> dp(n+1, vector<bool>(total_sum+1, 0));
    for(int i = 0; i<n; i++){
        dp[i][0] = true; // if(target == 0) return true;
    }
    if(n>0 && nums[0] <= total_sum) dp[0][nums[0]] = true; // if(index == 0 && target == nums[0]) return true;
    for(int i = 1; i<n; i++){
        for(int j = 1; j<=total_sum; j++){
            int notTake = dp[i-1][j];
            int take = false;
            if(j >= nums[i]){
                take = dp[i-1][j-nums[i]];
            }
            dp[i][j] = take || notTake;
        }
    }
    vector<int> v;
    for(int i = 0; i<=total_sum; i++){
        if(dp[n-1][i] == true){
            v.push_back(i);
        }
    }
    int minn = INT_MAX;
    int diff = 0;
    for(int i = 0; i<v.size(); i++){
        diff = total_sum-v[i];
        minn = min(minn, abs(diff-v[i]));
    }
    return minn;
}
int main(){
    
    return 0;
}