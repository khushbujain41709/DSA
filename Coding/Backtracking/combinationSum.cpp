// Leetcode 39
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void combination(vector<int> v , vector<int>& candidates , int target ,int i ,vector<vector<int>>& vec){
    if(target == 0){
        vec.push_back(v);
        return;
    }
    if(target < 0 || i == candidates.size()){
        return;
    }
    if(candidates[i] <= target){
        v.push_back(candidates[i]);
        combination(v, candidates, target - candidates[i], i, vec); // i because we can repeat same element
        v.pop_back();
    }
    // avoid call or not pick call
    // if not picking any element
    combination(v, candidates, target, i+1, vec); 
}
vector<vector<int>> combinationSum2(vector<int>& candidates,int target){
    vector<vector<int>> ans;
    sort(candidates.begin(), candidates.end());
    combination({},candidates,target,0,ans);
    return ans;
}
int main(){
    
    return 0;
}