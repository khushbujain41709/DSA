// Leetcode 443
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        vector<char> ans = chars;
        if(chars.empty()) return 0;
        if(n == 1) return 1;
        int count = 1;
        int k = 0;
        for(int i = 0; i<n-1; i++){
            if(chars[i+1] != chars[i]){
                if(count == 1){
                    chars[k] = chars[i];
                    k++;
                }
                else{
                    chars[k] = chars[i];
                    k++;
                    string str = to_string(count);
                    for(int j = 0; j<str.size(); j++){
                        chars[k] = str[j];
                        k++;
                    }
                }
                count = 1;
            }
            else count++;
        }
        if(chars[n-1] != ans[n-2]){ // ans is imp here
            // Failing case - ["1", "2", "3", "3", "2"]
            // if(chars[n-1] != chars[n-2]) is incorrect as
            // the array is: 1 2 3 2 2
            // But your loop is not finished reading the original array yet.
            chars[k] = chars[n-1];
            k++;
        }
        else{
            chars[k] = chars[n-1];
            k++;
            string str = to_string(count);
            for(int j = 0; j<str.size(); j++){
                chars[k] = str[j];
                k++;
            }
        }
        return k;
    }
};
int main(){
    
    return 0;
}