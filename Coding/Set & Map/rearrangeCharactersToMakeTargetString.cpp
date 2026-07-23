// Leetcode 2287
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int n = s.size();
        int m = target.size();
        if(n < m) return 0;
        unordered_map<char, int> m1, m2;
        for(int i = 0; i<m; i++){
            m2[target[i]]++;
        }
        for(int i = 0; i<n; i++){
            if(m2[s[i]] != 0){
                m1[s[i]]++;
            }
        }
        for(int i = 0; i<m; i++){
            if(m1[target[i]] == 0){
                return 0;
            }
        }
        int minn = INT_MAX;
        for(auto x : m1){
            int freq = x.second/m2[x.first];
            minn = min(minn, freq);
        }
        if(minn == INT_MAX) return 0;
        else return minn;
    }
};
int main(){
    
    return 0;
}