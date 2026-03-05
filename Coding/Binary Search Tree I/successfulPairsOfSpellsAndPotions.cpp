// Leetcode 2300
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
/*
firstPotion = (7 + 1 - 1) / 1 = 7 / 1 = 7
lower_bound(potions, 7) → not found → index = 5 (end)
Count = 5 - 5 = 0
*/
vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    int n = spells.size();
    int m = potions.size();
    sort(potions.begin(),  potions.end());
    vector<int> ans;
    for(int i = 0; i<n; i++){
        int count = 0;
        long long firstPotion = ceil(success*1.0/spells[i]);
        // long long firstPotion = (success + spells[i] - 1) / spells[i]; can also be written
        int idx = lower_bound(potions.begin(), potions.end(), firstPotion) - potions.begin();
        ans.push_back(m-idx);
    }
    return ans;
}
int main(){
    
    return 0;
}