// Leetcode 47
#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
// Solution 1
class Solution {
public:
    void permutations(vector<int>& nums, int i, vector<vector<int>>& ans){
        if(i == nums.size() - 1){
            ans.push_back(nums);
            return;
        }
        unordered_set<int> s;
        for(int idx = i; idx < nums.size(); idx++){
            if(s.count(nums[idx])){
                continue;
            }
            s.insert(nums[idx]);
            swap(nums[i], nums[idx]);
            permutations(nums, i+1, ans);
            swap(nums[i], nums[idx]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        permutations(nums, 0, ans);
        return ans;
    }
};

// Solution 2
class Solution {
public:
    void permutations(vector<int>& nums, vector<int>& current, vector<vector<int>>& ans, vector<bool>& used){
        if(current.size() == nums.size()){
            ans.push_back(current);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(used[i]) continue;
            // Just like leetcode combination II
            if(i > 0 && nums[i] == nums[i-1] && used[i-1]){
                continue;
            }
            if(!used[i]){
                used[i] = true;
                current.push_back(nums[i]);
                permutations(nums, current, ans, used);
                current.pop_back();
                used[i] = false;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        vector<bool> used(nums.size(), false);
        // Best approach for duplicate elements : sort + skip duplicates
        sort(nums.begin(), nums.end());
        permutations(nums, current, ans, used);
        return ans;
    }
};
int main(){
    
    return 0;
}