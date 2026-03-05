// https://www.geeksforgeeks.org/problems/minimum-cost-to-cut-a-board-into-squares/1
#include<bits/stdc++.h>
using namespace std;
// If we have divided a grid into rectangles and a cut later will be done on multiple rectangles then cost of the cut should be considered on each rectangle.
// Vertical cuts increases horizontal blocks
// Horizontal cuts increases vertical blocks
// TC = O(nlogn + mlogm)
// SC = O(1)
int minCost(int n, int m, vector<int>& x, vector<int>& y) {
    // n is width - horizontal
    // m is length - vertical
    int horizontalBlocks = 1;
    int verticalBlocks = 1;
    sort(x.rbegin(), x.rend());// x is vertical edge which increases horizontal blocks
    sort(y.rbegin(), y.rend());
    int i = 0;
    int j = 0;
    long long cost = 0;
    while(i<m-1 && j<n-1){
        // or i<x.size() && j<y.size()
        if(x[i] >= y[j]){
            cost += 1LL*x[i]*verticalBlocks;
            i++;
            horizontalBlocks++;
        }
        else if(x[i] <= y[j]){
            cost += 1LL*y[j]*horizontalBlocks;
            j++;
            verticalBlocks++;
        }
    }
    while(j < n-1){
        cost += 1LL*y[j]*horizontalBlocks;
        j++;
        verticalBlocks++;
    }
    while(i < m-1){
        cost += 1LL*x[i]*verticalBlocks;
        i++;
        horizontalBlocks++;
    }
    return cost;
}
int main(){
    
    return 0;
}