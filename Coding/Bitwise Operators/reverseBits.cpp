// Leetcode 190
#include<iostream>
using namespace std;
int reverseBits(int n) {
    int ans  = 0;
    for(int i = 0; i<32; i++){
        ans <<= 1; // Shift ans left by 1 bit. Creates space at the rightmost position to insert a new bit.
        ans |= (n&1); // (n&1) extracts the last bit of n. Append it to the right of ans.
        n >>= 1; // Shift n right -> removes the bit we just used.
    }
    return ans;
}
int main(){
    
    return 0;
}