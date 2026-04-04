// Leetcode 904
#include<bits/stdc++.h>
using namespace std;
// Method 1
// TC = O(2*N)
// TC = O(3) - storing atmost 3 fruits
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l = 0;
        int r = 0;
        int len = 0;
        int maxx = INT_MIN;
        unordered_map<int, int> mp;
        while(r<n){
            mp[fruits[r]]++; // add fruit first
            while(mp.size() > 2){
                mp[fruits[l]]--;
                if(mp[fruits[l]] == 0){
                    mp.erase(fruits[l]);
                }
                l++;
            }
            if(mp.size() <= 2){
                len = r-l+1;
                maxx = max(maxx, len);
            }
            r++;
        }
        return maxx;
    }
};
// Method 2
// TC = O(N)
// TC = O(3) - storing atmost 3 fruits
// Just replaced while loop with if condition to maintain max length without shrinking the window.
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l = 0;
        int r = 0;
        int len = 0;
        int maxx = INT_MIN;
        unordered_map<int, int> mp;
        while(r<n){
            mp[fruits[r]]++; // add fruit first
            if(mp.size() > 2){
                mp[fruits[l]]--;
                if(mp[fruits[l]] == 0){
                    mp.erase(fruits[l]);
                }
                l++;
            }
            if(mp.size() <= 2){
                len = r-l+1;
                maxx = max(maxx, len);
            }
            r++;
        }
        return maxx;
    }
};
int main(){
    
    return 0;
}