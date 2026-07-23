// Leetcode 1752
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // An array A rotated by x positions results in an array B of the same length such that B[i] == A[(i+x) % A.length] for every valid index i.
    bool sorted(vector<int>& nums){
        vector<int> v = nums;
        sort(v.begin(), v.end());
        if(v == nums) return true;
        else return false;
    }
    bool check(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n);
        for(int x = 0; x<n; x++){
            bool flag = true;
            for(int i = 0; i<n; i++){
                v[i] = nums[(i+x) % n];
            }
            if(sorted(v)) return true;
        }
        return false;
    }
};
int main(){
    
    return 0;
}