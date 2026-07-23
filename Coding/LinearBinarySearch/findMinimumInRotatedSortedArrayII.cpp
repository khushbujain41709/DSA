// Leetcode 154
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // nums[mid] == nums[high], we cannot decide anything.
    // Because both sides may contain the pivot.
    // Example: [1,1,1,0,1] or [1,0,1,1,1]

    // use high-- where nums[high] equals nums[mid]
    // then removing one duplicate cannot remove the unique minimum if it exists elsewhere, and if high itself is minimum, another equal value still exists at mid.
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low < high){
            int mid  = low + (high- low)/2;
            if(nums[low] < nums[high]){
                return nums[low];
            }
            if(nums[high] < nums[mid]){
                low = mid+1;
            }
            else if(nums[high] > nums[mid]){
                high = mid;
            }
            else{
                high--;
            }
        }
        return nums[low];
    }
};
int main(){
    
    return 0;
}