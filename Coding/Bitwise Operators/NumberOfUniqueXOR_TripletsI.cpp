// Leetcode 3513
#include<bits/stdc++.h>
using namespace std;
// Ask: How many bits can the answer have?
// If: n = 5 = 101, we have only 3 relevant bits. Therefore, XOR values can only be: 000, 001, 010, 011, 100, 101, 110, 111
// That's exactly: 2³ = 8 possible values.
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n;
        else{
            int val = 1;
            while(true){
                val *=2;
                if(val > n){
                    return val;                                             
                }
            }
        }
    }
};
int main(){
    
    return 0;
}
// 3513. Number of Unique XOR Triplets I — Concise Intuition
// 3514. Ignore the permutation order
// `nums` is a permutation of `[1, 2, ..., n]`, and `i <= j <= k` allows using the same element multiple times.
// So we only need to think about:
// `a XOR b XOR c`
// where `a, b, c ∈ [1, n]`.
// ---
// 2. Generate all numbers from 1 to n
// Using the XOR property:
// `x XOR x = 0`
// Therefore:
// `x XOR x XOR x = x`
// So every number from `1` to `n` is possible.
// ---
// 3. Generate 0
// If `n >= 3`:
// `1 XOR 2 XOR 3 = 0`
// So for `n >= 3`, we can generate at least:
// `0, 1, 2, ..., n`
// ---
// 4. Think in binary
// XOR works bit by bit.
// For example:
// `n = 5 = 101`
// The numbers use at most 3 bits, so the maximum possible XOR is:
// `111₂ = 7`
// Thus all possible values lie in:
// `0 ... 7`
// There are:
// `2³ = 8`
// possible values.
// For `n >= 3`, all values in this range can be generated.
// Therefore:
// `answer = 2^(number of bits in n)`
// This is equivalent to finding the smallest power of 2 strictly greater than `n`.
// Examples:
// `n = 3 → answer = 4`
// `n = 5 → answer = 8`
// `n = 7 → answer = 8`
// `n = 8 → answer = 16`
// ---
// 5. Special cases
// For `n = 1`:
// Only `1 XOR 1 XOR 1 = 1`
// Answer = `1`
// For `n = 2`:
// Possible values are only `{1, 2}`.
// We cannot generate `0` because `3` is unavailable.
// Answer = `2`
// Therefore:
// `if n <= 2, answer = n`
// ---
// Mental Shortcut
// Permutation `[1...n]`
// → Order doesn't matter
// → Repeated indices are allowed
// → `x XOR x XOR x = x`
// → Generate `1...n`
// → If `n >= 3`, `1 XOR 2 XOR 3 = 0`
// → Think in binary
// → Find number of bits in `n`
// → All bit patterns are achievable
// → Answer = `2^(number of bits)`

// Complexity:
// Time: `O(log n)`
// Space: `O(1)`
