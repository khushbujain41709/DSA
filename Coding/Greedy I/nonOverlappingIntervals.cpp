// Leetcode 435
#include<bits/stdc++.h>
using namespace std;
// Approach 1 - Sorted by ending points
bool comparator(vector<int>& a, vector<int>& b){
    return a[1] < b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int ans = 0;
        sort(intervals.begin(), intervals.end(), comparator);
        int lastEndTime = intervals[0][1];
        for(int i = 1; i<n; i++){
            if(intervals[i][0] < lastEndTime){
                ans++;
            }
            else{
                lastEndTime = intervals[i][1];
            }
        }
        return ans;
    }
};
// Approach 2 - Sorted by starting points
bool comparator(vector<int>& a, vector<int>& b){
    return a[0] < b[0];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int ans = 0;
        sort(intervals.begin(), intervals.end(), comparator);
        int lastEndTime = intervals[0][1];
        for(int i = 1; i<n; i++){
            if(intervals[i][0] < lastEndTime){
                ans++;
                lastEndTime = min(lastEndTime, intervals[i][1]); // only change in case when sorted by starting points
            }
            else{
                lastEndTime = intervals[i][1];
            }
        }
        return ans;
    }
};
int main(){
    
    return 0;
}