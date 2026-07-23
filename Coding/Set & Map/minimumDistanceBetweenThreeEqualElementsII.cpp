// Leetcode 3741
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> m;
        for(int i = 0; i<n; i++){
            m[nums[i]].push_back(i);
        }
        vector<int> v;
        int l = 0;
        int r = 0;
        int res = INT_MAX;
        int ans = 0;
        for(auto x: m){
            if(x.second.size() >= 3){
                v = x.second;
                sort(v.begin(), v.end());
                l = 0;
                r = 2;
                while(r<v.size()){
                    ans = 2*(v[r] - v[l]); 
                    // |a - b| + |b - c| + |c - a| = 2*(maxx - minn) -> solve
                    res = min(res, ans);
                    l++;
                    r++;
                }
            }
            v.clear();
        }
        if(res == INT_MAX) return -1;
        return res;
    }
};
int main(){
    
    return 0;
}