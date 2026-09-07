// Leetcode 567
#include<bits/stdc++.h>
using namespace std;
// Solution 1 - TLE sometimes
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        unordered_map<char, int> m1;
        for(int i = 0; i<n1; i++){
            m1[s1[i]]++;
        }
        int r = 0;
        int l = 0;
        sort(s1.begin(), s1.end());
        while(r<n2){
            int window = r-l+1;
            if(window > n1){
                l++;
            }
            window = r-l+1;
            if(window == n1){
                string str = s2.substr(l, n1); // s2.substr(starting_index, length of substring)
                sort(str.begin(), str.end());
                if(str == s1){
                    return true;
                }
            }
            r++;
        }
        return false;
    }
};

// Solution 2 - Same as Leetcode 438 - Find All Anagrams in a String
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if(n1 > n2) return false;
        unordered_map<char, int> m1;
        for(int i = 0; i<n1; i++){
            m1[s1[i]]++;
        }
        int r = 0;
        int l = 0;
        unordered_map<char, int> m2;
        while(r<n2){
            m2[s2[r]]++;
            int window = r-l+1;
            if(window > n1){
                m2[s2[l]]--;
                if(m2[s2[l]] == 0){
                    m2.erase(s2[l]);
                }
                l++;
            }
            window = r-l+1;
            if(window == n1){
                if(m1 == m2){ // imp
                    return true;
                }
            }
            r++;
        }
        return false;
    }
};
int main(){
    
    return 0;
}