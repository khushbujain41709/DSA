// Leetcode 1727
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        // Step 1: Building heights
        for(int i = 1; i<m; i++){
            for(int j = 0; j<n; j++){
                if(matrix[i][j] == 1){
                    matrix[i][j] += matrix[i-1][j];
                }
            }
        }
        // Step 2: Process each row
        int ans = INT_MIN;
        for(int i = 0; i<m; i++){
            vector<int> cummulative = matrix[i];
            sort(cummulative.rbegin(), cummulative.rend());
            for(int j = 0; j<n; j++){
                ans = max(ans, cummulative[j] * (j+1));
            }
        }
        return ans;
    }
};
int main(){
    
    return 0;
}