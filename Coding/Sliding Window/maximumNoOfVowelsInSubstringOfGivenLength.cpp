// Leetcode 1456
#include<bits/stdc++.h>
using namespace std;
// Method 1 - Giving TLE
class Solution {
public:
    int countVowel(string str){
        int n = str.size();
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
                cnt++;
            }
        }
        return cnt;
    }
    int maxVowels(string s, int k) {
        int n = s.size();
        int maxx = 0;
        for(int i = 0; i<=n-k; i++){
            string str = s.substr(i, k);
            maxx = max(maxx, countVowel(str));
        }
        return maxx;
    }
};

// Method 2 - Sliding Window
class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int maxx = 0;
        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                cnt++;
            }
            if(i >= k){
                if(s[i-k] == 'a' || s[i-k] == 'e' || s[i-k] == 'i' || s[i-k] == 'o' || s[i-k] == 'u'){
                    cnt--;
                }
            }
            if(i >= k-1){
                maxx = max(maxx, cnt);
            }
        }
        return maxx;
    }
};
int main(){
    
    return 0;
}