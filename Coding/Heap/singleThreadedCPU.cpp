// Leetcode 1834
#include<bits/stdc++.h>
using namespace std;
// Method 1 : Greedy - Giving TLE
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> order;
        int n = tasks.size();
        vector<tuple<int,int,int>> p;
        for(int i = 0; i<n; i++){
            p.push_back({tasks[i][0], tasks[i][1], i});
        }
        sort(p.begin(), p.end());
        int completed = 0;
        vector<int> done(n, false);
        long long curr_time = 0;
        while(completed < n){
            int minBurst = INT_MAX;
            int idx = -1;
            for(int i = 0; i<n; i++){
                if(!done[i] && get<0>(p[i]) <= curr_time){
                    if(minBurst > get<1>(p[i]) || (minBurst == get<1>(p[i]) && get<2>(p[i]) < get<2>(p[idx])) ){ 
                        minBurst = get<1>(p[i]);
                        idx = i;
                    }
                }
            }
            if(idx == -1){
                curr_time++; // no process available
                continue;
            }
            curr_time += get<1>(p[idx]);
            done[idx] = true;
            order.push_back(get<2>(p[idx]));
            completed++;
        }
        return order;
    }
};

// Method 2 : Priority_queue
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> order;
        int n = tasks.size();
        vector<tuple<int,int,int>> p;
        for(int i = 0; i<n; i++){
            p.push_back({tasks[i][0], tasks[i][1], i});
        }
        sort(p.begin(), p.end()); // sort p on the basis of arrival time
        long long curr_time = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int i = 0;
        while(i < n || !pq.empty()){
            // jump time if CPU idle
            if(pq.empty() && curr_time < get<0>(p[i])){
                curr_time = get<0>(p[i]);
            }
            // push all available tasks
            while(i<n && curr_time >= get<0>(p[i])){
                pq.push({get<1>(p[i]) , get<2>(p[i])});
                i++;
            }
            pair<int, int> k = pq.top();
            pq.pop();
            order.push_back(k.second);
            curr_time += k.first;
        }
        return order;
    }
};
int main(){
    
    return 0;
}