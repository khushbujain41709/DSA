// Leetcode 3
#include<bits/stdc++.h>
using namespace std;
// Dry run on cadbzabcd
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s == "") return 0;
        int n = s.size();
        int maxx = INT_MIN;
        int l = 0, r = 0;
        vector<int> hash(256, -1);
        while(r < n){
            if(hash[s[r] != -1]){
                if(hash[s[r]] >= l){
                    l = hash[s[r]] + 1;
                }
            }
            maxx = max(maxx, r - l + 1);
            hash[s[r]] = r;
            r++;
        }
        return maxx;
    }
};
int main(){
    
    return 0;
}