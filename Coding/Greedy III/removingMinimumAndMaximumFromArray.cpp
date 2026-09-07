// Leetcode 2091
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minn = INT_MAX;
        int maxx = INT_MIN;
        int minL = 0, minR = 0, maxL = 0, maxR = 0;
        int idxMin = 0;
        int idxMax = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] < minn){
                minn = nums[i];
                idxMin = i;
            }
            if(nums[i] > maxx){
                maxx = nums[i];
                idxMax = i;
            }
        }
        // If an element is at index i:
        // Delete from front = i + 1
        // Delete from back  = n - i
        // case 1 - delete both from front
        int front = 0, back = 0;
        front = max(idxMin, idxMax) + 1;
        // case 2 - delete both from back
        back = n - min(idxMin, idxMax);
        // case 3 - delete one from front and one from back
        int case1 = (n - idxMin) + (idxMax + 1);
        int case2 = (n - idxMax) + (idxMin + 1);
        int both = min(case2, case1);
        return min(front, min(back, both));
    }
};
int main(){
    
    return 0;
}