// Leetcode 56
#include<bits/stdc++.h>
using namespace std;
// Approach 1 - Sorted by ending points and traversing in reverse order(right to left)
bool comparator(vector<int>& a, vector<int>& b){
    return a[1] < b[1];
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> results;
        sort(intervals.begin(), intervals.end(), comparator);
        results.push_back(intervals[n-1]);
        for(int i = n-2; i>=0; i--){
            vector<int> curr = intervals[i];
            if(curr[1] >= results[results.size()-1][0]){ // equal to, see testcase 2
                int minn = min(curr[0], results[results.size()-1][0]);
                int maxx = max(curr[1], results[results.size()-1][1]);
                results[results.size()-1][0] = minn;
                results[results.size()-1][1] = maxx;
            }
            else{
                results.push_back(intervals[i]);
            }
        }
        return results;
    }
};
// Approach 2 - Sorted by starting points and traversing left to right
bool comparator(vector<int>& a, vector<int>& b){
    return a[0] < b[0];
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> results;
        sort(intervals.begin(), intervals.end(), comparator);
        results.push_back(intervals[0]);
        for(int i = 1; i<n; i++){
            vector<int> curr = intervals[i];
            if(curr[0] <= results[results.size()-1][1]){ // equal to, see testcase 2
                int minn = min(curr[0], results[results.size()-1][0]);
                int maxx = max(curr[1], results[results.size()-1][1]);
                results[results.size()-1][0] = minn;
                results[results.size()-1][1] = maxx;
            }
            else{
                results.push_back(intervals[i]);
            }
        }
        return results;
    }
};
int main(){
    
    return 0;
}