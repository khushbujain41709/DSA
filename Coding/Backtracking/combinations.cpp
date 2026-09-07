// Leetcode 77
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void helper(int n, int k, vector<vector<int>>& ans, int idx, vector<int> v){
        if(v.size() == k){
            ans.push_back(v);
            return;
        }
        for(int i = idx; i<=n; i++){
            v.push_back(i);
            helper(n, k, ans, i+1, v);
            v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        helper(n, k, ans, 1, {});
        return ans;
    }
};
int main(){
    
    return 0;
}