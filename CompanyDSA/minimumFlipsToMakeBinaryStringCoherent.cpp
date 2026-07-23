// Leetcode Biweekly Contest 182
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        if(n <= 2 || s == "101") return 0;
        int zero = 0;
        int one = 0;
        for(int i = 0; i<n; i++){
            if(s[i] == '0'){
                zero++;
            }
            else one++;
        }
        if(zero == 0) return 0;
        else{
            if(one == 0) return 0;
            // Target: exactly one '1', rest zeros. Keep any one '1', flip all others to 0. Cost = one-1.
            int ans = one - 1;
            // Target: all ones. Flip every '0' to '1'. Cost = zero.
            ans = min(ans, zero);
            // Target: 1[000...0]1 - ones pinned at both ends, zeros inside.
            // Force s[0]=1: costs 1 if it's currently '0'
            // Force s[n-1]=1: costs 1 if it's currently '0'
            // Flip all inner ones to 0: cost = ones not at edges
            if(n >= 2){
                int innerOnes = one - (s[0]=='1') - (s[n-1]=='1');
                int cost  = (s[0]!='1') + (s[n-1]!='1');
                ans = min(ans, cost + innerOnes);
            
            }
            return ans;
        }
        return 0;
    }
};
int main(){
    
    return 0;
}