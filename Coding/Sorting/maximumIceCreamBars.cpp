// Leetcode 1833
// You must solve the problem by counting sort.
#include<bits/stdc++.h>
using namespace std;
// Method 1 - Without counting sort
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        sort(costs.begin(), costs.end());
        int count = 0;
        int sum = 0;
        for(int i = 0; i<n; i++){
            if(sum + costs[i] <= coins){
                sum += costs[i];
                count ++;
            }
            else break;
        }
        return count;
    }
};

// Method 2 - Uisng counting sort
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int> freq(100001);
        for(int cost : costs) freq[cost]++;
        int ans = 0;
        for (int price = 1; price <= 100000; price++) {
            if(freq[price] == 0) continue;
            int canBuy = min(freq[price], coins / price);
            ans += canBuy;
            coins -= canBuy * price;
            if(coins < price) break;
        }
        return ans;
    }
};
int main(){
    
    return 0;
}