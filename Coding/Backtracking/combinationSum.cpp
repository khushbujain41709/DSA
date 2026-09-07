// Leetcode 39
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
// Solution 1 - Better than 2nd solution
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
vector<vector<int>> combinationSum(vector<int>& candidates,int target){
    vector<vector<int>> ans;
    sort(candidates.begin(), candidates.end()); // we can skip this
    combination({},candidates,target,0,ans);
    return ans;
}

// Best Solution
class Solution {
public:
    void combination(vector<int> v , vector<int>& candidates , int target ,int index,vector<vector<int>>& vec){
        if(target == 0){
            vec.push_back(v);
            return;
        }
        if(target < 0){
            return;
        }
        for(int i = index;i<candidates.size();i++){ // start i with index
            v.push_back(candidates[i]);
            combination(v,candidates,target - candidates[i] , i,vec); 
            v.pop_back();  // see line 2
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates,int target){
        vector<vector<int>> ans;
        combination({},candidates,target,0,ans);
        return ans;
    }
};

// Solution 2 - using sort and set
class Solution {
public:
    void helper(vector<vector<int>>& ans, vector<int> v, vector<int>& candidates, int target, int sum, set<vector<int>>& vis){
        int n = candidates.size();
        if(sum == target){
            sort(v.begin(), v.end());
            if(!vis.count(v)){
                ans.push_back(v);
                vis.insert(v);
            }
            return;
        }
        for(int i = 0; i<candidates.size(); i++){
            if(sum+candidates[i] <= target){
                v.push_back(candidates[i]);
                helper(ans, v, candidates, target, sum+candidates[i], vis);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        set<vector<int>> vis;
        helper(ans, {}, candidates, target, 0, vis);
        return ans;
    }
};
int main(){
    
    return 0;
}