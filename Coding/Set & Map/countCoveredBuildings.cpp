// Leetcode 3531
#include<bits/stdc++.h>
using namespace std;
// Method 1 - Gives TLE
int countCoveredBuildings(int n, vector<vector<int>>& buildings){
    unordered_map<int,vector<int>> mx, my;
    for(int i = 0; i<buildings.size(); i++){
        mx[buildings[i][0]].push_back(buildings[i][1]);
        my[buildings[i][1]].push_back(buildings[i][0]);
    }
    int count = 0;
    // A building at (x, y) is covered if there is:
    // A building above → same y, smaller x
    // A building below → same y, larger x
    // A building left → same x, smaller y
    // A building right → same x, larger y
    // for(int i = 0; i<n; i++){
    //     if(mx[buildings[i][0]] >= 3 && my[buildings[i][1]] >= 3){
    //         count++;
    //     }
    // }
    for(int i = 0; i<buildings.size(); i++){
        bool up = false, down = false, left = false, right = false;
        for(int j = 0; j<mx[buildings[i][0]].size(); j++){
            if(mx[buildings[i][0]][j] > buildings[i][1]){
                up = true;
            }
            if(mx[buildings[i][0]][j] < buildings[i][1]){
                down = true;
            }
        }
        for(int j = 0; j<my[buildings[i][1]].size(); j++){
            if(my[buildings[i][1]][j] > buildings[i][0]){
                right = true;
            }
            if(my[buildings[i][1]][j] < buildings[i][0]){
                left = true;
            }
        }
        if(up == true && down == true && left == true && right == true){
            count++;
        }
    }
    return count;
}

// Method 2
int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
    unordered_map<int,vector<int>> mx, my;
    for(int i = 0; i<buildings.size(); i++){
        mx[buildings[i][0]].push_back(buildings[i][1]);
        my[buildings[i][1]].push_back(buildings[i][0]);
    }
    // sorting vector so that we can use binary search
    // ampercent is important. If not used then we're sorting the copy, not the original map values.
    for(auto &x : mx){
        sort(x.second.begin(), x.second.end());
    }
    for(auto &y : my){
        sort(y.second.begin(), y.second.end());
    }
    int count = 0;
    for(auto b : buildings){
        int x = b[0], y = b[1];
        auto &col = mx[x]; // all y's where x same
        auto &row = my[y]; // all x's where y same
        // binary search on column(y's)
        auto it = lower_bound(col.begin(), col.end(), y);
        // after above line - it points to the first element >= y.
        bool down = (it != col.begin()); // exists < y
        bool up   = (it != col.end() && next(it) != col.end()); // exists > y
        // binary search on row(x's)
        auto it2 = lower_bound(row.begin(), row.end(), x);
        bool left  = (it2 != row.begin()); // exists < x
        bool right = (it2 != row.end() && next(it2) != row.end()); // exists > x
        if(up && down && left && right){
            count++;
        }
    }
    return count;
}
int main(){
    
    return 0;
}