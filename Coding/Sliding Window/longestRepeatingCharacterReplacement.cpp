// Leetcode 424
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0;
        int r = 0;
        vector<int> freq(26);
        int maxFreq = INT_MIN, maxLen = INT_MIN;
        while(r<n){
            freq[s[r] - 'A']++;
            maxFreq = max(maxFreq, freq[s[r] - 'A']);
            if((r-l+1) - maxFreq > k){
                // window length - most frequent character count
                freq[s[l] - 'A']--;
                l++;
            }
            else{
                maxLen = max(maxLen, r-l+1);
            }
            r++;
        }
        return maxLen;
    }
};
int main(){
    
    return 0;
}