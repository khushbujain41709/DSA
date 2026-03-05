// Leetcode 26
#include<iostream>
#include<vector>
using namespace std;
int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    if (nums.empty()) return 0;
    int j = 1; // tracks unique elements
    for(int i = 1; i<n; i++){
        if(nums[i] != nums[i-1]){
            nums[j] = nums[i];
            j++;
        }
    }
    return j;
}
int main(){
    
    return 0;
}