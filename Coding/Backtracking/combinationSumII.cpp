// Leetcode 40
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
        combination(v, candidates, target - candidates[i], i+1, vec);
        v.pop_back();
    }
    // avoid call or not pick call
    // if not picking any element
    int j = i+1; 
    // imagine case - candidates = [2] and target = 1 so j = i+1 is not defined
    while(j < candidates.size() && candidates[j] == candidates[j-1]){ // only possible if sorted
        j++;
    }
    combination(v, candidates, target, j, vec); 
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