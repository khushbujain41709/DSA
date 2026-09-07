// Leetcode 162
// This is a classic binary-search-on-answer-space problem.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int h = n-1;
        while(l<h){
            int mid = l + (h-l)/2;
            // Decreasing slope → mid could itself be a peak
            if(nums[mid] >= nums[mid+1]){
                h = mid;
            }
            // Increasing slope → peak is on the right
            else if(nums[mid] < nums[mid+1]){
                l = mid+1;
            }
        }
        return l;
    }
};
int main(){
    
    return 0;
}
// Goal: Find any index i such that nums[i] > nums[i-1] and nums[i] > nums[i+1].
// The array can be treated as having -∞ outside both boundaries, so the first and last elements can also be peaks.
// Key observation: Compare nums[mid] with nums[mid + 1].
// If nums[mid] < nums[mid + 1]:
// We are on an uphill slope.
// There must be a peak somewhere on the right side.
// Therefore, move to mid + 1 side.
// l = mid + 1.
// If nums[mid] > nums[mid + 1]:
// We are on a downhill slope.
// A peak exists at mid or somewhere on the left side.
// Therefore, keep mid as a possible answer.
// Move right boundary to mid.
// r = mid.
// Important: When moving left, use r = mid, not mid - 1, because mid itself can be the peak.
// When moving right, use l = mid + 1, because mid is already known to have a larger left neighbor and therefore cannot be the required peak.
// Why l < r?
// We continue while there are at least two possible positions.
// When l == r, only one possible peak index remains.
// Hence the search terminates at l == r.
// Why return l?
// At termination, l == r.
// The remaining index is guaranteed to be a peak.
// Therefore, returning either l or r is valid.
// Why is a peak always guaranteed?
// If the array keeps increasing, the last element is a peak.
// If it keeps decreasing, the first element is a peak.
// Whenever the direction changes from increasing to decreasing, the turning point is a peak.
// Why don't we explicitly check nums[mid-1]?
// The comparison with nums[mid+1] is sufficient to determine which half must contain a peak.
// This allows binary search in O(log n).

// Core invariant to remember:
// There is always at least one peak inside [l, r].
// Most important binary-search rule:
// If mid < mid+1, go right.
// Otherwise, go left including mid.

// Complexity:
// Time: O(log n)
// Space: O(1)
// One-line memory trick

// Going UP → peak is ahead → l = mid + 1
// Going DOWN → peak is here/behind → r = mid
// Meet at l == r → return l.