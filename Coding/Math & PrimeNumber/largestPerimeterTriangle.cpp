// Leetcode 976
#include<bits/stdc++.h>
using namespace std;
int largestPerimeter(vector<int>& nums) {
    int n = nums.size();
    // Method 1
    // Gives TLE
    // int maxx = 0;
    // for(int i = 0; i<n-2; i++){
    //     for(int j = i+1; j<n-1; j++){
    //         for(int k = j+1; k<n; k++){
    //             if((nums[i]+nums[k] > nums[j]) && (nums[j]+nums[i] > nums[k]) && (nums[k]+nums[j] > nums[i])){
    //                 maxx = max(nums[i]+nums[j]+nums[k] , maxx);
    //             }
    //         }
    //     }
    // }
    // return maxx;
    // ----------------------------------------------------------------------------------------------------
    // Method 2
    sort(nums.begin(), nums.end());
    for(int i = n-1; i>= 2; i--){
        if(nums[i-2] + nums[i-1] > nums[i]){
            return nums[i-1] + nums[i-2] + nums[i];
        }
    }
    return 0;
    /*
    1. Triangle inequality
    For sides (a,b,c), only one check matters:[ a+b>c ]
    If this holds, then automatically (a+c>b) and (b+c>a).

    2. Why consecutive elements are enough - After sorting: [nums[0] <= nums[1] <= .. <= nums[n-1]]
    We want the largest perimeter, so we try the largest three:
    (x=nums[i-2], y=nums[i-1], z=nums[i]).
    If (x+y <= z), then replacing (x) with a smaller value (like (nums[i-3])) only decreases the sum, so it will also fail. 
    Hence we just move left.

    3. Why not skip elements
    If (nums[i-2],nums[i-1],nums[i]) fails, then (nums[i-3],nums[i-1],nums[i]) has smaller perimeter and also fails the inequality. 
    So non-consecutive choices can’t beat consecutive ones.
    */
}
int main(){
    
    return 0;
}