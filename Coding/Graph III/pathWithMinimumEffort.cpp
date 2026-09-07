// Leetcode 1631
#include<bits/stdc++.h>
using namespace std;
// Check for destination while taking out of PQ and not while inserting.
// TC = E log(V) = m*n*4 * log(m*n)
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}}); // Insert distance first and then insert {row, column}
        while(! pq.empty()){
            int distance = pq.top().first;
            int row = pq.top().second.first;
            int column = pq.top().second.second;
            if(row == m-1 && column == n-1) return distance;
            // check here because we might find minimum distance 
            pq.pop();
            int dx[] = {0, 0, -1, +1};
            int dy[] = {+1, -1, 0, 0};
            for(int i = 0; i<4; i++){
                int nrow = row + dx[i];
                int ncol = column + dy[i];
                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n){
                    int diff = abs(heights[row][column] - heights[nrow][ncol]);
                    // Use heights not dist
                    int newEffort = max(distance, diff);
                    if(newEffort < dist[nrow][ncol]){
                        dist[nrow][ncol] = newEffort;
                        pq.push({newEffort, {nrow, ncol}});
                    }
                }
            }
        }
        return 0;
    }
};
int main(){
    
    return 0;
}