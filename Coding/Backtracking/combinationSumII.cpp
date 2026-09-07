// Leetcode 40
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Solution 1
class Solution {
public:
    // [1, 2, 2, 5], target = 3 so [1,2] using fisrt two and [1,2] using second two.

    // [1, 1, 2, 3, 1], target = 5 so 
    // at i = 0 using first one -> [1,1,3] and [1,1,2,1]
    // at i = 1 using second one -> [1,1,3] again repeat so skip this i = 1 one

    // Ex: [1,1,2,6], target = 8
    // helper(start = 0)          ← Level 0
    // for loop
    //   i=0 → choose 1
    //       helper(start = 1) ← Level 1
    //           for loop
    //             i=1 → choose 1
    //                 helper(start = 2) ← Level 2
    //                     for loop
    //                       i=2 → choose 2
    //                       i=3 → choose 6
    //             i=2 → choose 2
    //             i=3 → choose 6
    //   i=1 → duplicate 1 → skip
    //   i=2 → choose 2
    //       helper(start = 3)
    //           for loop
    //             i=3 → choose 6
    //   i=3 → choose 6
    void helper(vector<vector<int>>& ans, vector<int> v, int sum, vector<int>& candidates, int target, int idx){
        int n = candidates.size();
        if(sum == target){
            ans.push_back(v);
            return;
        }
        for(int i = idx; i<n; i++){
            if(i > idx && candidates[i] == candidates[i-1]) continue;
            // // This line is heart of combination sum II
            if(sum + candidates[i] <= target){
                v.push_back(candidates[i]);
                helper(ans, v, sum+candidates[i], candidates, target, i+1);
                // pass i+1 to avoid using same candidates[i] 
                v.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        helper(ans, {}, 0, candidates, target, 0);
        return ans;
    }
};

// Solution 2
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