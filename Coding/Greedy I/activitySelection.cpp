// https://www.geeksforgeeks.org/problems/activity-selection-1587115620/1
#include<bits/stdc++.h>
using namespace std;
bool comparator(vector<int>& a, vector<int>& b){
    return a[1] < b[1];
}
class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        int n = start.size();
        vector<vector<int>> intervals(n, vector<int>(2));
        for(int i = 0; i<n; i++){
            intervals[i][0] = start[i];
            intervals[i][1] = finish[i];
        }
        int ans = 0;
        sort(intervals.begin(), intervals.end(), comparator);
        int lastEndTime = intervals[0][1];
        for(int i = 1; i<n; i++){
            int currTime = intervals[i][0];
            if(currTime <= lastEndTime){
                ans++;
            }
            else{
                lastEndTime = intervals[i][1];
            }
        }
        return n-ans;
    }
};
int main(){
    
    return 0;
}