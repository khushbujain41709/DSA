// Leetcode 3653
#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int q = queries.size();
        int n = nums.size();
        for(int i = 0; i<q; i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];
            int v = queries[i][3];
            for(int j = l; j<=r; j+=k){
                nums[j] = (1LL* nums[j]% MOD * v% MOD) % MOD;
            }
        }
        int ans = 0;
        for(int i = 0; i<n; i++){
            ans = ans^nums[i];
        }
        return ans;
    }
};
int main(){
    
    return 0;
}