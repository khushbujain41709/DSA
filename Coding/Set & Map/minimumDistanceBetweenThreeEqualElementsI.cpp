// Leetcode 3740
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
        int minn = INT_MAX;
        int dist = 0;
        for(auto x: m){
            if(x.second.size() >= 3){
                v = x.second;
                for(int i = 0; i<v.size(); i++){
                    for(int j = 0; j<v.size(); j++){
                        for(int k = 0; k<v.size(); k++){
                            if(i != j && j != k && k != i){
                                dist = abs(v[i] - v[j]) + abs(v[j] - v[k]) + abs(v[k] - v[i]);
                                minn = min(minn, dist);
                            }
                        }
                    }
                }
            }
            v.clear();
        }
        if(minn == INT_MAX) return -1;
        else return minn;
    }
};
int main(){
    
    return 0;
}