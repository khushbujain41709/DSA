// Leetcode 303
// Can be solved using prefix sum
// TC = O(n+q) where q is query
// SC = O(n)
#include<iostream>
#include<vector>
using namespace std;
class NumArray {
public:
    vector<int> pref;
    NumArray(vector<int>& nums){
        int n = nums.size();
        pref.resize(n);
        pref[0] = nums[0];
        for(int i = 1; i<n; i++){
            pref[i] = pref[i-1] + nums[i];
        }
    }
    int sumRange(int left, int right){
        if(left == 0){
            return pref[right];
        }
        else{
            return pref[right] - pref[left-1];
        }
    }
};
int main(){
    
    return 0;
}