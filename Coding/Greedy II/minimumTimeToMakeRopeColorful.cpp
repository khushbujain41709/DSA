// Leetcode 1578
#include<bits/stdc++.h>
using namespace std;
int minCost(string colors, vector<int>& neededTime) {
    int sum = 0;
    int n = colors.size();
    int prev = neededTime[0];
    for(int i = 1; i<n; i++){
        if(colors[i] == colors[i-1]){
            sum += min(prev , neededTime[i]);
            prev = max(prev , neededTime[i]);
        }
        else{
            prev = neededTime[i];
        }
    }
    return sum;
}
int main(){
    
    return 0;
}