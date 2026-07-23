// Leetcode 11
#include<bits/stdc++.h>
using namespace std;
// Gives TLE - Brute Force
int maxArea(vector<int>& height) {
    int n = height.size();
    int maxx = INT_MIN;
    for(int i = 0; i<n-1; i++){
        for(int j = i+1; j<n; j++){
            int len = j-i;
            int area = min(height[i], height[j]) * len;
            maxx = max(maxx, area);
        }
    }
    return maxx;
}
int maxArea(vector<int>& height) {
    int n = height.size();
    int i = 0; // left pointer
    int j = n-1; // right pointer
    int maxx =  INT_MIN;
    while(i < j){
        int len = j-i;
        int area = min(height[i], height[j])*len;
        maxx = max(maxx, area);
        // Move the pointer pointing to the smaller height inward because moving the larger one cannot increase area, only a taller line might help.
        if(height[i] > height[j]){
            j--;
        }
        else{
            i++;
        }
    }
    return maxx;
}
int main(){
    
    return 0;
}