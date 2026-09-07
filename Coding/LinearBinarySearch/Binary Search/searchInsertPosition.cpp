// Leetcode 35
// Search lower bound
#include<bits/stdc++.h>
using namespace std;
// Solution 1
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int idx = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        return idx;
    }
};
// Solution 2
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid] > target){
                high = mid-1;
            }
            if(nums[mid]<target){
                low = mid+1;
            }
            if(nums[mid] == target){
                return mid;
            }
        }
        return low;
    }
};
int main(){
    
    return 0;
}