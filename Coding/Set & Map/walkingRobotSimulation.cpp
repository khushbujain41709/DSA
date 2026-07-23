// Leetcode 874
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int n = commands.size();
        int m = obstacles.size();
        set<pair<int, int>> s; // This is valid
        // but unordered_set<pair<int, int>> s; is invalid
        for(int i = 0; i<m; i++){
            s.insert({obstacles[i][0] , obstacles[i][1]});
        }
        int x = 0;
        int y = 0;
        int maxx = 0;
        char dir = 'N';
        for(int i = 0; i<n; i++){
            if(commands[i] == -1){
                if(dir == 'N'){
                    dir = 'E';
                }
                else if(dir == 'E'){
                    dir = 'S';
                }
                else if(dir == 'S'){
                    dir = 'W';
                }
                else if(dir == 'W'){
                    dir = 'N';
                }
            }
            else if(commands[i] == -2){
                if(dir == 'N'){
                    dir = 'W';
                }
                else if(dir == 'W'){
                    dir = 'S';
                }
                else if(dir == 'S'){
                    dir = 'E';
                }
                else if(dir == 'E'){
                    dir = 'N';
                }
            }
            else{
                int dx = 0;
                int dy = 0;
                if(dir == 'N') dy = 1;
                else if(dir == 'S') dy = -1;
                else if(dir == 'E') dx = 1;
                else if(dir == 'W') dx = -1;
                for(int j = 0; j<commands[i]; j++){
                    int newx = x + dx;
                    int newy = y + dy;
                    if(s.count({newx, newy})){
                        break; // obstacle hit
                    }
                    x = newx;
                    y = newy;
                    maxx = max(maxx, x*x + y*y);
                }
            }
        }
        return maxx;
    }
};
int main(){
    
    return 0;
}