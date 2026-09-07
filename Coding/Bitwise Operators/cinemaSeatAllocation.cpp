// Leetcode 1386
#include<bits/stdc++.h>
using namespace std;
// Solution 1 - TLE
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int m = reservedSeats.size();
        unordered_map<int, unordered_set<int>> adjList;
        for(int i = 0;i<m; i++){
            int u = reservedSeats[i][0];
            int v = reservedSeats[i][1];
            adjList[u].insert(v);
        }
        int cnt = 0;
        for(int i = 1; i<=n; i++){
            if(!adjList.count(i)){
                // We can allocate at most two four-person groups in one row.
                // Process only rows that appear in the input, for other rows you can always allocate seats for two groups.
                cnt += 2;
            }
            else{
                // Check the three possible blocks
                bool left = true;    // 2 3 4 5
                bool middle = true;  // 4 5 6 7
                bool right = true;   // 6 7 8 9
                for(int seat = 2; seat <= 5; seat++){
                    if(adjList[i].count(seat)){
                        left = false;
                    }
                }
                for(int seat = 4; seat <= 7; seat++){
                    if(adjList[i].count(seat)){
                        middle = false;
                    }
                }
                for(int seat = 6; seat <= 9; seat++){
                    if (adjList[i].count(seat)) {
                        right = false;
                    }
                }
                // Left + Right can be used together
                if(left && right){
                    cnt += 2;
                }

                // At least one block is available
                else if(left || middle || right){
                    cnt += 1;
                }

                // No block available
                else{
                    cnt += 0;
                }
            }
        }
        return cnt;
    }
};

// Solution 2 - Much Better Solution
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int m = reservedSeats.size();
        unordered_map<int, unordered_set<int>> adjList;
        for(int i = 0;i<m; i++){
            int u = reservedSeats[i][0];
            int v = reservedSeats[i][1];
            adjList[u].insert(v);
        }
        int cnt = 2*n; // max seats
        for(auto x: adjList){
            int row = x.first;
            // Check the three possible blocks
            bool left = true;    // 2 3 4 5
            bool middle = true;  // 4 5 6 7
            bool right = true;   // 6 7 8 9
            for(int seat = 2; seat <= 5; seat++){
                if(x.second.count(seat)){
                    left = false;
                }
            }
            for(int seat = 4; seat <= 7; seat++){
                if(x.second.count(seat)){
                    middle = false;
                }
            }
            for(int seat = 6; seat <= 9; seat++){
                if(x.second.count(seat)) {
                    right = false;
                }
            }
            // Left + Right can be used together
            if(left && right){
                cnt -= 0;
            }

            // At least one block is available
            else if(left || middle || right){
                cnt -= 1;
            }

            // No block available
            else{
                cnt -= 2;
            }
        }
        return cnt;
    }
};

// Solution - 3 - Bitmask Manipulation
// mp[1] = mask of reserved seats in row 1
// Suppose row 1 has reserved seats: 2, 5, 8
// Then:
// 1 << 2  → bit 2 = 1
// 1 << 5  → bit 5 = 1
// 1 << 8  → bit 8 = 1
// So the mask remembers exactly which seats are reserved.
// |= means turn that bit ON.
class Solution { 
public: 
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats){ 
        unordered_map<int, int> mp; 
        // Store reserved seats as a bitmask 
        for(auto &seat : reservedSeats){ 
            int row = seat[0];
            int col = seat[1];
            // Only seats 2 to 9 matter
            if(col >= 2 && col <= 9){
                mp[row] |= (1 << col);
            }
        }
        int ans = 2 * n;
        for(auto &[row, mask] : mp){ 
            // Initially assumed this row gives 2 groups. 
            // Check whether each block is blocked. 
            bool left = (mask & (1 << 2)) || 
                        (mask & (1 << 3)) || 
                        (mask & (1 << 4)) || 
                        (mask & (1 << 5)); 
 
            bool middle = (mask & (1 << 4)) || 
                          (mask & (1 << 5)) || 
                          (mask & (1 << 6)) || 
                          (mask & (1 << 7)); 
 
            bool right = (mask & (1 << 6)) || 
                         (mask & (1 << 7)) || 
                         (mask & (1 << 8)) || 
                         (mask & (1 << 9)); 
 
            if(!left && !right){
                // Left + Right can both be used 
                continue; 
            } 
            else if(!left || !middle || !right){ 
                // At least one block is available 
                ans -= 1; 
            } 
            else{ 
                // No block available 
                ans -= 2; 
            } 
        } 
        return ans;
    } 
};
int main(){
    
    return 0;
}