// Leetcode 1414
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int sum = 0;
    int findMinFibonacciNumbers(int k){
        if(k == 0) return sum;
        vector<int> v;
        v.push_back(1);
        v.push_back(1);
        while(v.back() < k){
            v.push_back(v.back() + v[v.size()-2]);
        }
        int idx = v.size() - 1;
        sum++;
        return findMinFibonacciNumbers(k-v[idx]);
    }
};
int main(){
    
    return 0;
}