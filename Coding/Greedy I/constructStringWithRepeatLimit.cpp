// Leetcode 2182
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
string repeatLimitedString(string s, int repeatLimit) {
    int n = s.size();
    unordered_map<char, int> m;
    priority_queue<pair<char, int>> pq;
    for(int i = 0; i<n; i++){
        m[s[i]]++;
    }
    for(auto x: m){
        pq.push({x.first, x.second});
    }
    string ans = "";
    while(!pq.empty()){
        auto largest = pq.top();
        pq.pop();
        int len = min(largest.second, repeatLimit);
        for(int i = 0; i<len; i++){
            ans += largest.first;
        }
        pair<char, int> secondLargest; // initialize krne k pehle check kro ki pq empty toh nhi
        if(largest.second - len > 0){
            if(!pq.empty()){
                secondLargest = pq.top();
                pq.pop();
                ans += secondLargest.first; // ek hee character insert krna hai
            }
            else{
                return ans;
            }
            if(secondLargest.second - 1 > 0){
                pq.push({secondLargest.first, secondLargest.second - 1});
            }
            pq.push({largest.first, largest.second - len});
        }
    }
    return ans;
}
int main(){
    
    return 0;
}