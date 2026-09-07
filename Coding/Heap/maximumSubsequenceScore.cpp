// Leetcode 2542
// Almost same as Leetcode 1383 - Maximum Performance Of a Team
// Only change is - Choose at most k different engineers out of the n engineers in that problem 
#include<bits/stdc++.h>
using namespace std;
// Solution 1 - TLE -> TC = O(n^2 logn)
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int,int>> v;
        for(int i = 0; i<n; i++){
            v.push_back({nums2[i], nums1[i]});
        }
        sort(v.begin(), v.end());
        long long maxx = LLONG_MIN;
        for(int i = 0; i<n-k+1; i++){
            int ele = v[i].first;
            long long sum = v[i].second;
            priority_queue<int> pq;
            for(int j = i+1; j<n; j++){
                pq.push(v[j].second);
            }
            for(int j = 0; j<k-1; j++){
                sum += (long long)pq.top();
                pq.pop();
            }
            maxx = max(maxx, (long long)(ele*sum));
        }
        return maxx;
    }
};
// Solution 2 -> TC = (O(n logk))
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int,int>> v;
        for(int i = 0; i<n; i++){
            v.push_back({nums2[i], nums1[i]});
        }
        sort(v.rbegin(), v.rend());
        long long maxx = LLONG_MIN;
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0;
        for(int i = 0; i<n; i++){
            pq.push(v[i].second);
            int ele = v[i].first;
            sum += v[i].second;
            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
                maxx = max(maxx, (long long)(ele*sum));
            }
            else if(pq.size() == k){
                maxx = max(maxx, (long long)(ele*sum));
            }
        }
        return maxx;
    }
};
int main(){
    
    return 0;
}