// https://www.naukri.com/code360/problems/distinct-characters_2221410
// Leetcode Premium
#include<bits/stdc++.h>
using namespace std;
int kDistinctChars(int k, string &str){
    int n = str.size();
    int l = 0;
    int r = 0;
    unordered_map<int, int> m;
    int maxLen = INT_MIN;
    while(r<n){
        m[str[r]]++;
        if(m.size() > k){ 
            // make the window intact of maximum length, do not shrink it using while loop
            m[str[l]]--;
            if(m[str[l]] == 0){
                m.erase(str[l]);
            }
            l++;
        }
        else{ // m.size() <= k
            maxLen = max(maxLen, (r-l+1));
        }
        r++;
    }
    return maxLen;
}
int main(){
    
    return 0;
}