// Leetcode 3397
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// a0 = nums[0]−k
// a1 = min(max(nums[1]−k, a0+1), nums[1]+k)
int maxDistinctElements(vector<int>& nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int first = nums[0] - k;
    int count = 1; // first is the first distinct element
    for(int i = 1; i<n; i++){
        int neww = min(max(nums[i] - k, first+1), nums[i] + k);
        if(neww > first){
            count++;
            first = neww; // imp
        }
    }
    return count;
}
int main(){
    
    return 0;
}