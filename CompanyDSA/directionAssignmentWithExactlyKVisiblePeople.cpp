// Contest question - Biweekly Contest 179©leetcode
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    const long long MOD = 1e9 + 7;
    // Function to calculate a^b % m
    long long binpow(long long a, long long b){
        long long result = 1;
        while (b) {
            if (b & 1)
                result = (result * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return result;
    }
    long long combination(int n, int r){
        if(r>n || r<0) return 0;
        long long nfact = 1;
        for(int i = 2; i<=n; i++){
            nfact = (nfact*i) % MOD;
        }
        long long rfact = 1;
        for(int i = 2; i<=r; i++){
            rfact = (rfact*i) % MOD;
        }
        long long nrfact = 1;
        for(int i = 2; i<=n-r; i++){
            nrfact = (nrfact*i) % MOD;
        }
        long long deno = (rfact*nrfact) % MOD;
        long long inv = binpow(deno, MOD-2);
        return (nfact*inv) % MOD;
    }
    int countVisiblePeople(int n, int pos, int k) {
        int count = 2;
        int ans = 2*combination(n-1, k)%MOD;
        return ans;
    }
};
int main(){
    
    return 0;
}
/*
Use Fermat’s theorem:
b^{-1} = b^(MOD-2) % MOD
*/