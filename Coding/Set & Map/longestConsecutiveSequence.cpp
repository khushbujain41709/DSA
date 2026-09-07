// Leetcode 128
// You must write an algorithm that runs in O(n) time.
#include<bits/stdc++.h>
using namespace std;
// Solution 1 - But not in O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        else if(nums.size() == 1){
            return 1;
        }
        int n = nums.size();
        unordered_set<int> s;
        vector<int> v;
        for(int i = 0; i<n; i++){
            s.insert(nums[i]);
        }
        for(auto x: s){
            v.push_back(x);
        }
        if(v.size() == 1){
            return 1;
        }
        sort(v.begin(), v.end());
        int l = 0;
        int r = 1;
        int maxx = 1;
        while(r<v.size()){
            if(v[r] != v[r-1] + 1){
                l = r;
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

// Solution 2 : TC - O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;
        for(auto x: s){
            // x is the beginning of a sequence
            if(s.find(x-1) == s.end()){
                int curr = x;
                int len = 1;
                while(s.find(curr+1) != s.end()){
                    curr++;
                    len++;
                }
                ans = max(ans, len);
            }
        }
        return ans;
    }
};
int main(){
    
    return 0;
}