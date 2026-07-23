// Leetcode 3043
#include<bits/stdc++.h>
using namespace std;
// Method 1 - TLE
class Solution {
public:
    int common(string s1, string s2){
        int len = 0;
        for(int i = 0; i<min(s1.size(), s2.size()); i++){
            if(s1[i] == s2[i]){
                len++;
            }
            else break;
        }
        return len;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        vector<string> s1(n1), s2(n2);
        for(int i = 0; i<n1; i++){
            string s = to_string(arr1[i]);
            s1[i] = s;
        }
        for(int i = 0; i<n2; i++){
            string s = to_string(arr2[i]);
            s2[i] = s;
        }
        int maxx = INT_MIN;
        unordered_set<int> s;
        for(int i = 0; i<n2; i++){
            for(int j = 0; j<n1; j++){
                int len = common(s2[i], s1[j]);
                maxx = max(maxx, len);
            }
        }
        return maxx;
    }
};

// Method 2
class Solution {
public:
    // chooses maximum length
    int find(int x, unordered_set<int>& s){
        int len = 0;
        int y = x;
        while(y > 0){
            y = y/10;
            len++;
        }
        while(x > 0){
            if(s.count(x)) return len;
            x = x/10;
            len--;
        }
        return 0;
    }
    vector<int> make(int x){
        vector<int> v;
        while(x > 0){
            v.push_back(x);
            x = x/10;
        }
        return v;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        unordered_set<int> s;
        // All prefixes of arr1 elements
        for(int i = 0; i<n1; i++){
            vector<int> prefix = make(arr1[i]);
            for(int i = 0; i<prefix.size(); i++){
                s.insert(prefix[i]);
            }
        }
        // Matching of prefixes of arr1 with arr2
        int maxx = INT_MIN;
        for(int i = 0; i<n2; i++){
            int len = find(arr2[i], s);
            maxx = max(maxx, len);
        }
        return maxx;
    }
};
int main(){
    
    return 0;
}