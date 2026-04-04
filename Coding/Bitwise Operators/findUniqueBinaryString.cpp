// Leetcode 1980
#include<bits/stdc++.h>
using namespace std;
long long bin_to_deci(string s){
    int n = s.size();
    long long result = 0;
    for(int i = n-1; i>=0; i--){
        char ch = s[i];
        int num = ch - '0';
        result += num*(1LL<<(n-i-1));
    }
    return result;
}
string deci_to_bin(long long x, int n){
    string res(n, '0');
    for(int i = n-1; i>=0; i--){
        if(x&1){
            res[i] = '1';
        }
        x >>= 1;
    }
    return res;
}
string findDifferentBinaryString(vector<string>& nums) {
    int n = nums.size();
    vector<long long> deci(n);
    for(int i = 0; i<n; i++){
        deci[i] = bin_to_deci(nums[i]);
    }
    sort(deci.begin(), deci.end());
    string ans = "";
    for(int i = 0; i<=n; i++){
        if(i == n || deci[i] != i){
            ans = deci_to_bin(i, n);
            break;
        }
    }
    return ans;
}
int main(){
    
    return 0;
}