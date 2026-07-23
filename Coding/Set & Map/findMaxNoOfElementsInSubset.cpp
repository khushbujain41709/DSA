// Leetcode 3020
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;
        for(int i = 0; i<n; i++){
            m[nums[i]]++;
        }
        int val = INT_MIN;
        for(auto x: m){
            if(x.first == 1){
                int curr = 0;
                if(x.second % 2 == 0) curr = x.second - 1;
                else curr = x.second;
                val = max(val, curr);
            }
            else{
                int ans = 0;
                if(m[x.first] >= 2){
                    ans += 2;
                    long long nxt = 1LL * x.first * x.first;
                    while(nxt <= 1000000000LL && m.find(nxt) != m.end()){
                        if(m[nxt] >= 2){
                            ans += 2;
                        }
                        else{
                            ans += 1;
                            break;
                        }
                        nxt = nxt * nxt;
                    }
                }
                else{
                    ans += 1;
                }
                if(ans % 2 == 0){
                    ans --;
                }
                val = max(ans, val);
            }
        }
        return val;
    }
};
int main(){
    
    return 0;
}