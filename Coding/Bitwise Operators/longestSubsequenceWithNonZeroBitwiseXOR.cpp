// Leetcode 3702
#include<bits/stdc++.h>
using namespace std;
// Solution 1
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xorr = 0;
        int zero = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] == 0){
                zero++;
            }
            xorr ^= nums[i];
        }
        if(zero == n){
            return 0;
        }
        else{
            if(xorr == 0){
                return n-1;
            }
            else return n;
        }
    }
};

// Solution 2
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n= nums.size();
        int xorr = 0; // as x^0 = x
        for(int i = 0; i<n; i++){
            xorr = nums[i]^xorr;
        }
        if(xorr != 0){
            return n;
        }
        else{
            bool zeros = true;
            int count = 0;
            for(int i = 0; i<n; i++){
                if(nums[i] != 0){
                    zeros = false;
                    count++;
                }
            }
            if(zeros) return 0;
            else return n-1;
        }
    }
};
int main(){
    
    return 0;
}