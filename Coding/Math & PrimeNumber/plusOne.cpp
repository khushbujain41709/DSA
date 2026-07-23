// Leetcode 66
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    int last = digits[n-1];
    vector<int> ans;
    if(last < 9){
        digits[n-1] = 1+digits[n-1];
        return digits;
    }
    else{
        int sum = 0;
        int carry = 1;
        int i = n-1;
        while(i >= 0 && carry){
            sum = digits[i] + carry;
            carry = sum / 10;
            sum = sum % 10;
            i--;
            ans.push_back(sum);
        }
        while(i >= 0){
            ans.push_back(digits[i]);
            i--;
        }
        if(carry != 0){
            ans.push_back(carry);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    return {};
}
int main(){
    
    return 0;
}