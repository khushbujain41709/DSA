// Leetcode 334
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int first = INT_MAX;
        int second = INT_MAX;
        int third = INT_MIN;
        for(int i = 0; i<n; i++){
            if(nums[i] <= first){ // = sign is imp
                first = nums[i];
            }
            else if(nums[i] <= second){ // = sign is imp
                second = nums[i];
            }
            else{
                third = nums[i];
            }
        }
        if(first < second && second < third){
            return true;
        }
        else return false;
    }
};
int main(){
    
    return 0;
}