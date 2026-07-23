// Leetcode 2946 
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        k = k%n; // for k > n
        if(k % n == 0){
            return true;
        }
        else{
            for(int i = 0; i<m; i++){
                for(int j = 0; j<n; j++){
                    if(mat[i][j] != mat[i][(j+k) % n]) return false;
                }
            }
            return true;
        }
        return true;
    }
};
int main(){
    
    return 0;
}