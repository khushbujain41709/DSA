// Leetcode 76
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool equal(unordered_map<char, int>& m1, unordered_map<char, int>& m2){
        for(auto x: m1){
            if(!m2.count(x.first)) return false;
            else{
                if(x.second > m2[x.first]){
                    return false;
                }
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(t.size() > s.size()) return ""; // imp
        unordered_map<char, int> m1;
        for(int i = 0; i<n; i++){
            m1[t[i]]++;
        }
        int l = 0;
        int r = 0;
        int lo = -1;
        int ro = -1;
        int minn = INT_MAX;
        unordered_map<char, int> m2;
        while(r<m){
            m2[s[r]]++;
            int window = r-l+1;
            while(equal(m1, m2)){
                window = r-l+1;
                if(minn >= window){
                    minn = min(minn, window);
                    lo = l;
                    ro = r;
                }
                m2[s[l]]--;
                if(m2[s[l]] == 0) m2.erase(s[l]);
                l++;
            }
            r++;
        }
        string ans = "";
        if(lo == -1) return ""; // imp
        for(int i = lo; i<=ro; i++){
            ans += s[i];
        }
        return ans;
    }
};
int main(){
    
    return 0;
}