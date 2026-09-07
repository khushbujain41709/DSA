#include<bits/stdc++.h>
using namespace std;
// My code - Given a binary string and a zone limit so we need to make continguous partitions of the string such that: partition size must be less or equal to zone limit and partitions must be non alternating like 10101 is alternating but 11001 is non alternating. Give the minimum number of partitions in the string.
// DP will be used here bcoz the longest valid first partition may leave a suffix that requires many partitions. Another slightly shorter first partition might leave a much easier suffix.
// This assumes: "I can decide the next partition based only on the current window."
// But the problem asks: "Which partition choice gives me the minimum total number of partitions for the entire string?"
bool isAlternating(string s){
    int n = s.size();
    for(int i = 0; i<n-1; i++){
        if(s[i] == s[i+1]) return false;
    }
    return true;
}
int minPartitions(string s, int zoneLimit){
    int z = zoneLimit;
    int n = s.size();
    int l = 0;
    int r = 0;
    int count = 0;
    while(r<n){
        int window = r-l+1;
        if(window > z){
            if(isAlternating(s.substr(l, window-1)) == true){
                count += window;
            }
            else count++;
            l = r+1;
        }
        r++;
    }
    return count;
}
// DP
class Solution {
public:
    int minimumPartitions(string s, int zoneLimit) {
        int n = s.size();
        const int INF = 1e9;
        vector<int> dp(n + 1, INF);
        // Empty suffix needs 0 partitions
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            bool nonAlternating = false;
            for (int j = i; j < n && j < i + zoneLimit; j++) {
                // If two consecutive characters are same,
                // substring s[i...j] is non-alternating
                if (j > i && s[j] == s[j - 1]) {
                    nonAlternating = true;
                }
                if (nonAlternating) {
                    dp[i] = min(dp[i], 1 + dp[j + 1]);
                }
            }
            // If length-1 partitions are considered valid
            if (dp[i] == INF) {
                dp[i] = 1 + dp[i + 1];
            }
        }
        return dp[0];
    }
};
int main(){
    
    return 0;
}