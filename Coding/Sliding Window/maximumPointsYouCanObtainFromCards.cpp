// Leetcode 1423
#include<bits/stdc++.h>
using namespace std;
// Method 1 - Using prefix sum - Hard
// TC = O(n), SC = O(n)
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> prefix(n, 0);
        prefix[0] = cardPoints[0];
        for(int i = 1; i<n; i++){
            prefix[i] = prefix[i-1] + cardPoints[i];
        }
        int lsum = 0, rsum = 0;
        int maxx = INT_MIN;
        if(n == k) return prefix[n-1];
        for(int i = 0; i<=k; i++){
            if(i != 0) lsum = prefix[i-1];
            else lsum = 0;
            rsum = prefix[n-1] - prefix[n-(k-i)-1]; // if(n == k) return prefix[n-1]; imp
            maxx = max(maxx, lsum + rsum);
        }
        return maxx;
    }
};
// Method 2 - Using sliding window - Easy
// TC = O(k), SC = O(1)
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int lsum = 0;
        for(int i = 0; i<k; i++){
            lsum += cardPoints[i];
        }
        int rsum = 0;
        int maxx = rsum+lsum;
        int r_idx = n-1;
        for(int i = k-1; i>=0; i--){
            lsum = lsum - cardPoints[i];
            rsum = rsum + cardPoints[r_idx];
            r_idx--;
            maxx = max(maxx, lsum+rsum);
        }
        return maxx;
    }
};
int main(){
    
    return 0;
}