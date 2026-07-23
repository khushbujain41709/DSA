// Leetcode 992
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int helper(vector<int>& nums, int k){ 
        // no. of subarrays where different integers <= K
        int n = nums.size();
        int l = 0;
        int r = 0;
        unordered_map<int, int> m;
        int count = 0;
        while(r<n){
            m[nums[r]]++;
            while(m.size()>k){
                m[nums[l]]--;
                if(m[nums[l]] == 0){
                    m.erase(nums[l]);
                }
                l++;
            }
            count += (r-l+1);
            r++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k){
        return helper(nums, k) - helper(nums, k-1);
    }
};
int main(){
    
    return 0;
}