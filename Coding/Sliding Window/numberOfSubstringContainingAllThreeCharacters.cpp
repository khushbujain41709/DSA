// Leetcode 1358
// With every character there is a substring that ends.
// Create a last seen array.
// TC = O(N). SC = O(1)
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int l = 0;
        int r = 0;
        vector<int> lastSeen(3, -1);
        int minn = INT_MAX;
        int count = 0;
        while(r<n){
            lastSeen[s[r] - 'a'] = r;
            if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1){
                minn = min(lastSeen[0], min(lastSeen[1], lastSeen[2]));
                count += minn + 1;
            }
            r++;
        }
        return count;
    }
};
int main(){
    
    return 0;
}