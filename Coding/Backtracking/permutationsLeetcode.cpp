// Leetcode 46
#include<iostream>
#include<vector>
using namespace std;
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
int main(){
    
    return 0;
}