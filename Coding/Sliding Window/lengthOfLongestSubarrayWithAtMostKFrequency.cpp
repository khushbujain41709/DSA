// Leetcode 2958
#include<bits/stdc++.h>
using namespace std;
// Solution 1 - TLE
class Solution {
public:
    bool freq(unordered_map<int, int>& m, int k){
        for(auto x: m){
            if(x.second > k) return false;
        }
        return true;
    }
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int maxx = INT_MIN;
        unordered_map<int, int> m;
        while(r<n){
            m[nums[r]]++;
            if(!freq(m, k)){
                m[nums[l]]--;
                if(m[nums[l]] == 0){
                    m.erase(nums[l]);
                }
                l++;
            }
            else{
                int window = r-l+1;
                maxx = max(maxx, window);
            }
            r++;
        }
        return maxx;
    }
};

// Solution 2
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int maxx = INT_MIN;
        unordered_map<int, int> m;
        while(r<n){
            m[nums[r]]++;
            while(m[nums[r]] > k){
                m[nums[l]]--;
                if(m[nums[l]] == 0){
                    m.erase(nums[l]);
                }
                l++;
            }
            int window = r-l+1;
            maxx = max(maxx, window);
            r++;
        }
        return maxx;
    }
};
int main(){
    
    return 0;
}