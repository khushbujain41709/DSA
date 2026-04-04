// Leetcode 1248
// Logic is same as Leetcode 930 and Leetcode 560
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int helper(vector<int>& nums, int k){ // counts number of subarrays with sum less than equal to goal
        int n = nums.size();
        if(k < 0) return 0; // as we have passed goal - 1 as parameter as of goal = 0 then goal-1 = -1
        int l = 0;
        int r = 0;
        int count = 0;
        int sum = 0;
        while(r<n){
            sum += nums[r];
            while(sum > k){
                sum -= nums[l];
                l++;
            }
            if(sum <= k){
                count += (r-l+1);
            }
            r++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0; i<n; i++){
            if(nums[i] % 2 == 0){
                nums[i] = 0;
            }
            else{
                nums[i] = 1;
            }
        }
        int count1 = helper(nums, k);
        int count2 = helper(nums, k-1);
        return count1 - count2;
    }
};
int main(){
    
    return 0;
}
/*
nums = [2,2,2,1,2,2,1,2,2,2], k = 2
nums → [0,0,0,1,0,0,1,0,0,0]
exactly(k) = atMost(k) - atMost(k-1)
answer = helper(nums, 2) - helper(nums, 1)

| r | nums[r] | sum | l | count added | total count |
| - | ------- | --- | - | ----------- | ----------- |
| 0 | 0       | 0   | 0 | 1           | 1           |
| 1 | 0       | 0   | 0 | 2           | 3           |
| 2 | 0       | 0   | 0 | 3           | 6           |
| 3 | 1       | 1   | 0 | 4           | 10          |
| 4 | 0       | 1   | 0 | 5           | 15          |
| 5 | 0       | 1   | 0 | 6           | 21          |
| 6 | 1       | 2   | 0 | 7           | 28          |
| 7 | 0       | 2   | 0 | 8           | 36          |
| 8 | 0       | 2   | 0 | 9           | 45          |
| 9 | 0       | 2   | 0 | 10          | 55          |
helper(nums,2) = 55

| r | nums[r] | sum      | l | count added | total count |
| - | ------- | -------- | - | ----------- | ----------- |
| 0 | 0       | 0        | 0 | 1           | 1           |
| 1 | 0       | 0        | 0 | 2           | 3           |
| 2 | 0       | 0        | 0 | 3           | 6           |
| 3 | 1       | 1        | 0 | 4           | 10          |
| 4 | 0       | 1        | 0 | 5           | 15          |
| 5 | 0       | 1        | 0 | 6           | 21          |
| 6 | 1       | 2→shrink | 4 | 3           | 24          |
| 7 | 0       | 1        | 4 | 4           | 28          |
| 8 | 0       | 1        | 4 | 5           | 33          |
| 9 | 0       | 1        | 4 | 6           | 39          |
helper(nums,1) = 39

exactly 2 = 55 - 39 = 16
*/