// Leetcode 1081
// Same as Leetcode 316
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // dry run on s = "cbaacabcaaccaacababa"
    // if(vis.count(s[i])) continue; without this line this case will give error
    // dry run on other leetcode examples without this line
    string smallestSubsequence(string s) {
        int n = s.size();
        string t = s;
        unordered_map<char, int> m;
        unordered_set<char> vis;
        stack<char> st;
        string ans = "";
        for(int i = 0; i<n; i++){
            m[s[i]]++;
        }
        for(int i = 0; i<n; i++){
            m[s[i]]--;
            if(vis.count(s[i])) continue; // very imp
            while(!st.empty() && st.top() > s[i] && m[st.top()] > 0){
                vis.erase(st.top()); // very imp
                st.pop();
            }
            if(!vis.count(s[i])){
                st.push(s[i]);
                vis.insert(s[i]);
            }
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main(){
    
    return 0;
}
// s = "cbaacabcaaccaacababa"
// Initial: a = 10, b = 3, c = 5
// | i  | char | Action                                         | Stack     |
// | -- | ---- | ---------------------------------------------- | --------- |
// | 0  | c    | Push c                                         | `[c]`     |
// | 1  | b    | Pop c, push b                                  | `[b]`     |
// | 2  | a    | Pop b, push a                                  | `[a]`     |
// | 3  | a    | Already present → skip                         | `[a]`     |
// | 4  | c    | Push c                                         | `[a,c]`   |
// | 5  | a    | Pop c, a already present → skip                | `[a]`     |
// | 6  | b    | Push b                                         | `[a,b]`   |
// | 7  | c    | Push c                                         | `[a,b,c]` |
// | 8  | a    | Pop c, pop b, a already present → skip         | `[a]`     |
// | 9  | a    | Skip                                           | `[a]`     |
// | 10 | c    | Push c                                         | `[a,c]`   |
// | 11 | c    | Skip                                           | `[a,c]`   |
// | 12 | a    | **Cannot pop c (`m[c]=0`)**, a already present | `[a,c]`   |
// | 13 | a    | Cannot pop c, skip                             | `[a,c]`   |
// | 14 | c    | Skip                                           | `[a,c]`   |
// | 15 | a    | Cannot pop c, skip                             | `[a,c]`   |
// | 16 | a    | Cannot pop c, skip                             | `[a,c]`   |
// | 17 | b    | Cannot pop c, push b                           | `[a,c,b]` |
// | 18 | a    | Cannot pop b (`m[b]=0`), skip                  | `[a,c,b]` |
// | 19 | b    | Skip                                           | `[a,c,b]` |
// | 20 | a    | Cannot pop b, skip                             | `[a,c,b]` |

// Final stack: [a, c, b]
// Reverse stack → "acb"
// Expected: "abc"

// The key problem
// At i = 12:
// stack = [a, c]
// current = a
// c cannot be popped because:
// m[c] = 0
// So c gets stuck above a.
// Later, when b arrives:
// stack = [a, c]
// current = b
// You can only check/pop the top, which is c. Since c cannot be popped, b gets pushed:
// [a, c, b]
// That's how you end up with "acb".