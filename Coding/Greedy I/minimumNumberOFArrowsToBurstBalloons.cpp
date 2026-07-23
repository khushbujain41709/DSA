// Leetcode 452
#include<bits/stdc++.h>
using namespace std;
// sort on the basis of ending time
bool comparator(vector<int>& a, vector<int>& b){
    return a[1] < b[1];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        sort(points.begin(), points.end(), comparator);
        int lastEndTime = points[0][1];
        for(int i = 1; i<n; i++){
            int currTime = points[i][0];
            if(currTime <= lastEndTime){
                ans++;
            }
            else{
                lastEndTime = points[i][1];
            }
        }
        return n - ans;
    }
};
int main(){
    
    return 0;
}