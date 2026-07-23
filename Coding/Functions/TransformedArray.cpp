// Leetcode 3379
#include<iostream>
#include<vector>
using namespace std;
vector<int> constructTransformedArray(vector<int>& nums){
    // newIndex = (i + nums[i]) mod n
    // % with negative numbers gives negative results. So we must normalize it
    int n = nums.size();
    vector<int> res(n);
    for(int i = 0; i<n; i++){
        int val = nums[i];
        if(val > 0){
            res[i] = nums[((i + nums[i])%n+n)%n];
        }
        else if(val < 0){
            res[i] = nums[((i + nums[i])%n+n)%n];
        }
        else{
            val = nums[i];
            res[i] = nums[i];
        }
    }
    return res;
}
int main(){
    
    return 0;
}