// Leetcode 46
#include<iostream>
#include<vector>
using namespace std;
// Solution 1
void permutations(vector<int>& nums, int i, vector<vector<int>>& ans){
    if(i == nums.size() - 1){
        ans.push_back(nums);
        return;
    }
    for(int idx = i; idx < nums.size(); idx++){
        swap(nums[i], nums[idx]);
        permutations(nums, i+1, ans);
        swap(nums[i], nums[idx]);
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    permutations(nums, 0, ans);
    return ans;
}

// Solution 2
void permutations(vector<int>& nums, vector<int>& current, vector<vector<int>>& ans, vector<bool>& used){
    if(current.size() == nums.size()){
        ans.push_back(current);
        return;
    }
    for(int i = 0; i < nums.size(); i++){
        if(!used[i]){
            used[i] = true;
            current.push_back(nums[i]);
            permutations(nums, current, ans, used);
            current.pop_back();
            used[i] = false;
        }
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> current;
    vector<bool> used(nums.size(), false);
    permutations(nums, current, ans, used);
    return ans;
}
int main(){
    
    return 0;
}