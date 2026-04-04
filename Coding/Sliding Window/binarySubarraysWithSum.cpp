// Leetcode 930
// Same as Leetcode 560, only difference is that Leetcode 560 - Subarrays sum equals K has negative elements also.
#include<bits/stdc++.h>
using namespace std;
// Method 1
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        for(int i = 1;i<n;i++){
            nums[i] = nums[i-1] + nums[i];
        }
        int count = 0;
        unordered_map<int , int> m;
        for(int i = 0; i<n; i++){
            int target = nums[i] - goal;
            if(nums[i] == goal){
                count++;
            }
            if(m.find(target) != m.end()){  
                count += m[target];  // add frequency in count
            }
            m[nums[i]]++;
        }
        return count;
    }
};

// Method 2 - Optimized for this question as it has only 0 and 1 as elements.
// exact(goal) = atMost(goal) − atMost(goal - 1)
// ≤ goal → includes: goal, goal-1, goal-2 ...
// ≤ goal-1 → includes: goal-1, goal-2 ...
// Subtract → only goal remains
class Solution {
public:
    int helper(vector<int>& nums, int k){ // counts number of subarrays with sum less than equal to goal
        int n = nums.size();
        if(k < 0) return 0; // as we have passed goal - 1 as parameter as of goal = 0 then goal-1 = -1
        int l = 0;
        int r = 0;
        int count = 0;
        int sum = 0;
        while(r<n){
            sum += nums[r];
            while(sum > k){
                sum -= nums[l];
                l++;
            }
            if(sum <= k){
                count += (r-l+1);
            }
            r++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count1 = helper(nums, goal);
        int count2 = helper(nums, goal-1);
        return count1 - count2;
    }
};
int main(){
    
    return 0;
}