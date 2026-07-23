// Leetcode 3635
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int helper(vector<int>& s1, vector<int>& d1, vector<int>& s2, vector<int>& d2){
        int n = s1.size();
        int m = s2.size();
        vector<pair<int, int>> rides;
        for(int i = 0; i<m; i++){
            rides.push_back({s2[i], d2[i]});
        }
        sort(rides.begin(), rides.end());
        vector<int> pref(m), start(m);
        for(int i = 0; i<m; i++){
            start[i] = rides[i].first;
        }
        // min prefix array of duration of ride 2
        pref[0] = rides[0].second;
        for(int i = 1; i<m; i++){
            pref[i] = min(pref[i-1], rides[i].second); 
        }
        // min suffix array of start+duration of ride 2
        vector<int> suff(m);
        suff[m-1] = rides[m-1].first + rides[m-1].second;
        for(int i = m-2; i>=0; i--){
            suff[i] = min(suff[i+1], rides[i].first + rides[i].second); 
        }
        int ans = INT_MAX;
        for(int i = 0; i<n; i++){
            int finish1 = s1[i] + d1[i];
            int pos = upper_bound(start.begin(), start.end(), finish1) - start.begin();
            // as upper_bound return an iterator
            if(pos > 0){
                ans = min(ans, finish1 + pref[pos-1]);
            }
            if(pos < m){
                ans = min(ans, suff[pos]);
            }
        }
        return ans;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int ans1 = INT_MAX, ans2 = INT_MAX;
        ans1 = helper(landStartTime, landDuration, waterStartTime, waterDuration);
        ans2 = helper(waterStartTime, waterDuration, landStartTime, landDuration);
        return min(ans1, ans2);
    }
};
int main(){
    
    return 0;
}