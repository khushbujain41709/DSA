// Leetcode 3446
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    priority_queue<int> pq1; // maxheap
    priority_queue<int, vector<int>, greater<int>> pq2; // minheap
    for(int i = 0; i<m; i++){
        int j = 0;
        int idx = i;
        while(idx<m && j<n){
            pq1.push(grid[idx][j]);
            idx++;
            j++;
        }
        j = 0; 
        idx = i;
        while(idx<m && j<n){
            grid[idx][j] = pq1.top();
            pq1.pop();
            idx++;
            j++;
        }
    }
    for(int j = 1; j<n; j++){
        int i = 0;
        int idx = j;
        while(i<m && idx<n){
            pq2.push(grid[i][idx]);
            i++;
            idx++;
        }
        i = 0;
        idx = j;
        while(i<m && idx<n){
            grid[i][idx] = pq2.top();
            pq2.pop();
            i++;
            idx++;
        }
    }
    return grid;
}
int main(){
    
    return 0;
}