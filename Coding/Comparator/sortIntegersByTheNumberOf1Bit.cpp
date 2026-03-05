// Leetcode 1356
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool comparator(int a, int b, unordered_map<int, int>& m){
        if(m[a] == m[b]){
            return a < b;
        }
        else return m[a] < m[b];
    }
    int countSetBits(int n){
        return __builtin_popcount(n);
    }
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> m;
        for(int i = 0; i<n; i++){
            int setB = countSetBits(arr[i]);
            m[arr[i]] = setB;
        }
        sort(arr.begin(), arr.end(), [&](int a, int b){ 
            return comparator(a, b, m);
        });
        // This is a lambda function
        // Without [&], the lambda cannot access m.
        return arr;
    }
};
int main(){
    
    return 0;
}