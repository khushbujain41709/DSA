// https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        vector<tuple<int, int, int>> v;
        for(int i = 0; i<n; i++){
            v.push_back({end[i], start[i], i});
        }
        int count = 1;
        vector<int> order;
        sort(v.begin(), v.end());
        int lastTime = get<0>(v[0]);
        for(int i = 1; i<n; i++){
            if(lastTime < get<1>(v[i])){
                count++;
                lastTime = get<0>(v[i]);
                order.push_back(get<2>(v[i]));
            }
        }
        return count;
    }
};
int main(){
    
    return 0;
}