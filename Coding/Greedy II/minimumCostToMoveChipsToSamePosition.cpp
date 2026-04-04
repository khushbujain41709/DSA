// Leetcode 1217
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        unordered_map<int, int> m;
        int n = position.size();
        int parity = 0;
        int even = 0, odd = 0;
        for(int i = 0; i<n; i++){
            parity = position[i] % 2;
            if(parity == 0) even ++;
            else odd++;
        }
        return min(even, odd);
    }
};
int main(){
    
    return 0;
}