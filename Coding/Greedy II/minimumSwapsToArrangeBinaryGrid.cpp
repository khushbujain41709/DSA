// Leetcode 1536
#include<bits/stdc++.h>
using namespace std;
int minSwaps(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<int> ones;
    for(int i = 0; i<n; i++){
        int count = 0;
        for(int j = grid[i].size() - 1; j>=0; j--){
            if(grid[i][j] == 0){
                count++;
            }
            else{
                break;
            }
        }
        ones.push_back(count);
    }
    int swaps = 0;
    // using bubble sort
    for(int i = 0; i<n; i++){
        int needed = n-i-1;
        int j = i;
        while(j<n && ones[j] < needed){
            j++;
        }
        if(j == n) return -1; // index nhi mila swap krne k liye
        while(i<j){
            swap(ones[j], ones[j-1]);
            swaps ++;
            j--;
        }
    }
    return swaps;
}
int main(){
    
    return 0;
}