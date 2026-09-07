// Leetcode 447
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Why m[x.first]*(m[x.first]-1) ?
    // If freq points are at the same distance from center i, choose j in freq ways and k in freq-1 ways (because k ≠ j).
    // So, since order matters: freq × (freq - 1).
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        int cnt = 0;
        int dist = 0;
        for(int i = 0; i<n; i++){
            unordered_map<int, int> m;
            for(int j = 0; j<n; j++){
                if(i == j) continue;
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                dist = ((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
                m[dist]++;
            }
            for(auto x: m){
                cnt += m[x.first]*(m[x.first]-1);
            }
        }
        return cnt;
    }
};
int main(){
    
    return 0;
}