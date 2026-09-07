// Leetcode 1318
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        for(int i = 0; i<32; i++){
            int digi1 = 1 & a;
            int digi2 = 1 & b;
            int digi3 = 1 & c;
            if(digi1 == 1 && digi2 == 1 && digi3 == 0){
                ans += 2;
            }
            else if(digi1 == 0 && digi2 == 0 && digi3 == 0){
                ans += 0;
            }
            else if(digi1 == 1 && digi2 == 1 && digi3 == 1){
                ans += 0;
            }
            else if(digi1 != digi2 && digi3 == 1){
                ans += 0;
            }
            else if(digi1 != digi2 && digi3 == 0){
                ans += 1;
            }
            else ans += 1; // digi1 = 0, digi2 = 0, digi3 = 1 
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return ans;
    }
};
int main(){
    
    return 0;
}