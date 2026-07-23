// Leetcode 3614
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    char processStr(string s, long long k) {
        // Index : 0 1 2 3 4 5 6
        // Char  : a b # c % * d
        // Len   : 1 2 4 5 5 4 5
        // Notice we never stored the string, only these numbers.
        int n = s.size();
        vector<long long> len(n, 0);
        long long curr = 0;
        for(int i = 0; i<n; i++){
            if(s[i] == '*'){
                if(curr > 0) curr--;
            }
            else if(s[i] == '#'){
                curr *= 2;
            }
            else if(s[i] >= 97 && s[i] <= 122){
                curr++;
            }
            // '%' does not change length
            len[i] = curr;
        }
        if(len[n-1] <= k) return '.';
        for(int i = n-1; i>=0; i--){
            if(s[i] >= 97 && s[i] <= 122){
                if(k == len[i]-1){
                    return s[i];
                }
            }
            else if(s[i] == '%'){
                k = len[i]-k-1;
            }
            else if(s[i] == '#'){
                long long prev = len[i]/2;
                k %= prev;
            }
            // '*' needs no change to k
        }
        return '.';
    }
};
int main(){
    
    return 0;
}