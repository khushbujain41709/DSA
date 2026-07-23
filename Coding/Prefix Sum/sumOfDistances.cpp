// Leetcode 2615
// same as leetcode 2121 - Intervals Between Identical Elements
#include<bits/stdc++.h>
using namespace std;
// Method 1 - Gives TLE as TC = O(n^2)
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<long long, vector<long long>> m;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            m[nums[i]].push_back((long long)i);
        }
        vector<long long> ans(n);
        for(int i = 0; i<n; i++){
            if(m[nums[i]].size() == 1){
                ans[i] = 0;
            }
            else{
                long long sum = 0;
                for(int j = 0; j<m[nums[i]].size(); j++){
                    sum += abs(i - m[nums[i]][j]);
                }
                ans[i] = sum;
            }
        }
        return ans;
    }
};
// Method 2 - Using prefix sum
// left side  = i * pi - sum of previous positions
// right side = sum of next positions - (k - i) * pi
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<long long, vector<long long>> m;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            m[nums[i]].push_back((long long)i);
        }
        vector<long long> ans(n,0LL);
        vector<long long> prefix;
        for(auto x: m){
            long long len = x.second.size();
            prefix.resize(len);
            prefix[0] = x.second[0];
            for(long long j = 1; j<len; j++){
                prefix[j] = prefix[j-1] + x.second[j];
            }
            for(int i = 0; i<len; i++){
                long long val = x.second[i];
                long long left = 0, right = 0;
                long long sum = 0;
                if(i > 0){
                    left = val*i - prefix[i - 1];
                }
                if(i < len-1){
                    right = (prefix[len-1] - prefix[i]) - val*(len-i-1);
                }
                sum = left + right;
                ans[val] = sum;
            }
            prefix.clear();
        }
        return ans;
    }
};
int main(){

    return 0;
}