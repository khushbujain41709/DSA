// Leetcode 153
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low < high){
            int mid  = low + (high- low)/2;
            if(nums[low] <= nums[high]){
                return nums[low];
            }
            if(nums[high] < nums[mid]){
                low = mid+1;
            }
            else{
                high = mid;
            }
        }
        return nums[low];
    }
};
int main(){
    
    return 0;
}