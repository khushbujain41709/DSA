// Leetcode 179
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool comparator(string a, string b){
    return a+b < b+a;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> v;
        string s = "";
        for(int i = 0; i<n; i++){
            v.push_back(to_string(nums[i]));
        }
        sort(v.begin(), v.end(), comparator);
        reverse(v.begin(), v.end());
        // If the array contains [0,0,0], the output should be "0", not "000"
        if(v[0] == "0"){
            return "0";
        }
        for(int i = 0; i<n; i++){
            s += v[i];
        }
        return s;
    }
};
int main(){
    
    return 0;
}