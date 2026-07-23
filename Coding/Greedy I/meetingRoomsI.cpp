// Leetcode 252 Premium and GFG
// https://leetcode.com/problems/meeting-rooms/description/
#include<bits/stdc++.h>
using namespace std;
bool canAttend(vector<vector<int>> &arr) {
    if(arr.size() == 0) return true;
    int n = arr.size();
    vector<int> start, end;
    for(int i = 0; i<n; i++){
        start.push_back(arr[i][0]);
        end.push_back(arr[i][1]);
    }
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    int i = 0;
    int j = 0;
    int ans = 0;
    int rooms = 0;
    while(i<n and j<n){
        if(start[i] < end[j]){
            // we need a new room as meeting has not ended but new meeting has started.
            rooms++;
            i++;
            ans = max(ans, rooms);
        }
        else if(start[i] == end[j]){
            // no change
            i++;
            j++;
        }
        else{ // start[i] > end[j] - meeting has ended so room is empty now
            rooms--;
            j++;
        }
    }
    return ans == 1;
}
int main(){
    
    return 0;
}