// Leetcode 216
#include<bits/stdc++.h>
using namespace std;
// Solution 1
class Solution {
public:
    void helper(vector<vector<int>>& ans, int k, int n, vector<int> v, int sum , int idx){
        if(sum == n && v.size() == k){
            ans.push_back(v);
            return ;
        }
        for(int i = idx; i<=9; i++){
            if(sum + i <= n){
                v.push_back(i);
                helper(ans, k, n, v, sum+i, i+1);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        helper(ans, k, n, {}, 0, 1);
        return ans;
    }
};

// Solution 2
class Solution {
public:
    void helper(int k, int n, vector<vector<int>>& ans, vector<int> v, int idx, int sum){
        // idx represents the starting number, not how many elements you have selected
        if(v.size() == k && sum == 0){
            ans.push_back(v);
            return;
        }
        for(int i = idx+1; i<=9; i++){
            if(i > sum) break;
            v.push_back(i);
            helper(k, n, ans, v, i, sum-i);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        helper(k, n, ans, {}, 0, n);
        return ans;
    }
};
int main(){
    
    return 0;
}