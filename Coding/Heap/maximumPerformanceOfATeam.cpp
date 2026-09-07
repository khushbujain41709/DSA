// Leetcode 1383
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int mod = 1e9 + 7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> v;
        for(int i = 0; i<n; i++){
            v.push_back({efficiency[i], speed[i]});
        }
        sort(v.rbegin(), v.rend());
        long long maxx = LLONG_MIN;
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0;
        for(int i = 0; i<n; i++){
            pq.push(v[i].second);
            int ele = v[i].first;
            sum += (v[i].second);
            // Don't modulo the running sum
            // sum += (v[i].second) % mod; -> This is incorrect
            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
                // Don't take modulo before taking the maximum
                // maxx = max(maxx, ((long long)(ele*sum)) % mod); -> This is incorrect
                maxx = max(maxx, (long long)(ele*sum));
            }
            else if(pq.size() <= k){ // only change is of equal to - in leetcode 2542
                maxx = max(maxx, (long long)(ele*sum));
            }
        }
        return maxx % mod;
    }
};
int main(){
    
    return 0;
}