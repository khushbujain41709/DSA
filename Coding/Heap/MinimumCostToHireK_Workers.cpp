// Leetcode 2462
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int l = 0;
        set<pair<int, int>> vis;
        for(int i = 0; i<candidates ; i++){
            pq.push({costs[i], i});
            vis.insert({costs[i], i});
            l = i;
        }
        int r = n-1;
        for(int i = n-1; i>n-candidates-1; i--){
            if(!vis.count({costs[i], i})){
                pq.push({costs[i], i});
                vis.insert({costs[i], i});
            }
            r = i;
        }
        long long sum = 0;
        for(int i = 0; i<k; i++){
            auto x = pq.top();
            pq.pop();
            int ele = x.first;
            int idx = x.second;
            sum += ele;
            if(idx <= l && l <= r && l<=n-2){
                l++;
                if(!vis.count({costs[l], l})){
                    pq.push({costs[l], l});
                    vis.insert({costs[l], l});
                }
            }
            else if(idx >= r && l <= r && r >= 1){ 
                r--;
                if(!vis.count({costs[r], r})){
                    pq.push({costs[r], r});
                    vis.insert({costs[r], r});
                }
            }
        }
        return sum;
    }
};
int main(){
    
    return 0;
}