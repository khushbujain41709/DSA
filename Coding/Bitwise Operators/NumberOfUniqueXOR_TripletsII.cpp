// Leetcode 3514
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s(nums.begin(), nums.end());
        unordered_set<int> pairs;
        if(n < 2){
            return n;
        }
        else if(n == 2){
            if(nums[0] != nums[1]) return 2;
            else return 1;
        }
        else{
            for(int i = 0; i<n; i++){
                for(int j = i; j<n; j++){
                    pairs.insert(nums[i] ^ nums[j]);
                }
            }
            for(auto x : pairs){
                for(int i = 0; i<n; i++){
                    s.insert(nums[i] ^ x);
                }
            }
        }
        return s.size();
    }
};
int main(){
    
    return 0;
}