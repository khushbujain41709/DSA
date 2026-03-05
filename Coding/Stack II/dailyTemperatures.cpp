// Leetcode 739
#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
#include<climits>
using namespace std;
// Method 1 - Correct but gives TLE
vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    unordered_map<int, vector<int>> m;
    vector<int> nge(n, -1);
    vector<int> days(n, -1);
    days[n-1] = 0;
    stack<int> st;
    st.push(temperatures[n-1]);
    for(int i = n-2; i>=0 ; i--){
        int count = 0;
        while(!st.empty() && temperatures[i] >= st.top()){
            st.pop();
        }
        if(st.size() == 0){
            nge[i] = -1;
        }
        else{
            nge[i] = st.top();
        }
        st.push(temperatures[i]);
    }
    for(int i = 0; i<n; i++){
        m[temperatures[i]].push_back(i);
    }
    for(int i = 0; i<n; i++){
        if(nge[i] == -1){
            days[i]  = 0;
        }
        else{
            int minIdx = INT_MAX;
            // bad complexity
            for(auto x: m){ // searching all temps unnecessarily
                if(x.first == nge[i]){
                    for(int j = 0; j<x.second.size(); j++){
                        if(x.second[j] > i){
                            minIdx = min(minIdx, x.second[j]);
                        }
                    }
                }
            }
            days[i] = minIdx;
        }
    }
    for(int i = 0; i<n; i++){
        if(days[i] != 0){
            days[i] -= i;
        }
    }
    return days;
}
// Method 2 - More optimized map part
vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    unordered_map<int, vector<int>> m;
    vector<int> nge(n, -1);
    vector<int> days(n, -1);
    days[n-1] = 0;
    stack<int> st;
    st.push(temperatures[n-1]);
    for(int i = n-2; i>=0 ; i--){
        int count = 0;
        while(!st.empty() && temperatures[i] >= st.top()){
            st.pop();
        }
        if(st.size() == 0){
            nge[i] = -1;
        }
        else{
            nge[i] = st.top();
        }
        st.push(temperatures[i]);
    }
    for(int i = 0; i<n; i++){
        m[temperatures[i]].push_back(i);
    }
    for(int i = 0; i<n; i++){
        if(nge[i] == -1){
            days[i]  = 0;
        }
        else{
            int minIdx = INT_MAX;
            auto &v = m[nge[i]]; // O(1) average
            for(int j = 0; j < v.size(); j++){
                if(v[j] > i){
                    minIdx = min(minIdx, v[j]);
                }
            }
            days[i] = minIdx;
        }
    }
    for(int i = 0; i<n; i++){
        if(days[i] != 0){
            days[i] -= i;
        }
    }
    return days;
}
int main(){
    
    return 0;
}