// Leetcode 787
#include<bits/stdc++.h>
using namespace std;
// Storing shortest distance and using normal priority queue will not work because sometimes shortest distance path takes more stops so we won't be able to reach our destination.
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        int m = flights.size();
        for(int i = 0; i<m; i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];
            graph[u].push_back({v, w});
        }
        queue<pair<int, pair<int, int>>> q;
        // Insert stops -> node -> price
        q.push({0, {src, 0}});
        vector<int> paisa(n, INT_MAX);
        paisa[src] = 0;
        while(! q.empty()){
            int stop = q.front().first;
            int node = q.front().second.first;
            int price = q.front().second.second;
            q.pop();
            for(auto x: graph[node]){
                // x.first - node
                // x.second - price
                int newPrice = price + x.second;
                if(newPrice < paisa[x.first] && stop != k+1){
                    // k + 1 because we are counting destination node also here.
                    paisa[x.first] = newPrice;
                    q.push({stop+1, {x.first, newPrice}});
                }
            }
        }
        if(paisa[dst] != INT_MAX) return paisa[dst];
        return -1;
    }
};
int main(){
    
    return 0;
}