// Leetcode 3720
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        string formed = "";
        bool flag = false;
        unordered_map<char, int> m;
        for(int i = 0; i<n; i++){
            m[s[i]]++;
        }
        for(int i = 0; i<n; i++){
            char ch = target[i];
            if(m.count(ch)){
                formed += ch;
                m[ch]--;
                if(m[ch] == 0){
                    m.erase(ch);
                }
            }
            else if(flag == false){
                for(int j = target[i]+1; j <= 'z'; j++){
                    if(m.count(j)){
                        flag = true;
                        formed += j;
                        m[j]--;
                        if(m[j] == 0){
                            m.erase(j);
                        }
                        break;
                    }
                }
                if(flag == true){
                    string rem = "";
                    for(auto x: m){
                        for(int i = 0; i<x.second; i++){
                            rem += x.first;
                        }
                    }
                    sort(rem.begin(), rem.end());
                    formed += rem;
                    return formed;
                }
                // else break is for:
                // Input: s = "hxlo", target = "xxxh"
                // Output: ""
                else break;
                // This line is for:
                // Input: s = "kb", target = "ui"
                // Output: ""
                if(flag == false && formed.empty()) return "";
            }
        }
        // If neither equality nor a greater character works at the current position, you must backtrack to a previous matched position and increase that character.
        
        // Go from the rightmost position toward the left, restoring one character at a time, and try to increase that character.

        // Input: s = "abc", target = "acb"
        // Output: "bac"

        // Input: s = "aab", target = "aab"
        // Output: "aba"

        // Input: s = "aab", target = "abb"
        // Output: "baa"
        // formed = "ab"
        // m = {a:1}. So backtrack.
        int i = formed.size()-1;
        while(!formed.empty()){
            m[formed[i]]++;
            int ch = formed[i];
            i--;
            formed.pop_back();
            bool flag = false;
            for(int j = ch+1; j <= 'z'; j++){
                if(m.count(j)){
                    flag = true;
                    formed += j;
                    m[j]--;
                    if(m[j] == 0){
                        m.erase(j);
                    }
                    break;
                }
            }
            if(flag == true){
                string rem = "";
                for(auto x: m){
                    for(int i = 0; i<x.second; i++){
                        rem += x.first;
                    }
                }
                sort(rem.begin(), rem.end());
                formed += rem;
                return formed;
            }
        }
        if(formed == target || formed.size() != n)  return "";
        // Input: s = "baba", target = "bbaa"
        // Output: ""
        return formed;
    }
};
int main(){
    
    return 0;
}