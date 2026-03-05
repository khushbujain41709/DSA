// Leetcode 3318
#include<bits/stdc++.h>
using namespace std;
bool comparator(pair<int, int>& a, pair<int, int>& b){
    if(a.second != b.second){
        return a.second > b.second;
    }
    else{
        return a.first > b.first;
    }
}
class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> result;
        for(int i = 0; i<n-k+1; i++){
            int sum = 0;
            unordered_map<int, int> m;
            for(int j = i; j<i+k; j++){
                m[nums[j]]++;
            }
            vector<pair<int, int>> v;
            for(auto z: m){
                int key = z.first;
                int value = z.second;
                pair<int, int> p = {key, value};
                v.push_back(p);
            }
            sort(v.begin(), v.end(), comparator);
            int y = min(x,(int)v.size()); 
            // typecasting is imp as v.size() returns size_t (an unsigned long type)
            for(int b = 0; b < y; b++){
                sum += v[b].first*v[b].second;
            }
            result.push_back(sum);
        }
        return result;
    }
};
int main(){
    
    return 0;
}