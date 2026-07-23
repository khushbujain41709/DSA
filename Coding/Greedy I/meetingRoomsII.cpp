// Leetcode 253 Premium and GFG
// https://leetcode.com/problems/meeting-rooms-ii/description/
#include<bits/stdc++.h>
using namespace std;
int minMeetingRooms(vector<int> &start, vector<int> &end) {
    // TC = O(nlogn), SC = O(1)
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    int i = 0;
    int j = 0;
    int n = start.size();
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
    return ans;
}
int main(){
    
    return 0;
}