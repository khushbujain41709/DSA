// https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        if(start == end) return 0;
        // Nodes are always between 0 to 999.
        vector<int> num(1000, INT_MAX);
        num[start] = 0;
        queue<pair<int, int>> q;
        // Insert step first and then insert node
        q.push({0, start});
        while(! q.empty()){
            int step = q.front().first;
            int node = q.front().second;
            q.pop();
            for(int i = 0; i<arr.size(); i++){
                int newNum = arr[i] * node;
                newNum %= 1000;
                if(step + 1 < num[newNum]){
                    num[newNum] = step+1;
                    q.push({step+1, newNum});
                }
                if(newNum == end) return step+1;
            }
        }
        return -1;
    }
};
int main(){
    
    return 0;
}