// Leetcode 646
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool comparator(vector<int>& a, vector<int>& b){
    return a[0] < b[0]; // sort on the basis of starting points
}
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), comparator);
        int start = pairs[0][1];
        int count = 1;
        for(int i = 1; i<n; i++){
            if(pairs[i][0] > start){
                count ++;
                start = pairs[i][1];
            }
            else{
                start = min(pairs[i][1], start);
            }
        }
        return count;
    }
};
int main(){
    
    return 0;
}