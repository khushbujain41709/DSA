// Leetcode 17
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void helper(string& digits, vector<string>& ans, unordered_map<char, string>& mp, string s, int idx){
        int n = digits.size();
        if(idx == n){
            ans.push_back(s);
            return; // imp
        }
        for(int i = 0; i<mp[digits[idx]].size(); i++){
            helper(digits, ans, mp, s + (char)mp[digits[idx]][i], idx+1);
        }
    }
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        vector<string> ans;
        unordered_map<char, string> mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        helper(digits, ans, mp, "", 0);
        return ans;
    }
};
int main(){
    
    return 0;
}