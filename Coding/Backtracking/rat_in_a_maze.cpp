// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
// Method 1
vector<string> ans;
string s = "";
class Solution {
  public:
    void f(int row, int col, vector<vector<int>>& maze, int n){
        if(row == n-1 && col == n-1){
            ans.push_back(s);
            return;
        }
        if(row < 0 || row >= n || col < 0 || col >= n){
            return;
        }
        // left - left cell must not be visited and it must be a free cell
        if(col - 1 >= 0 && maze[row][col-1] != 2 && maze[row][col-1] == 1){
            maze[row][col-1] = 2; // marked visited
            s += 'L';
            f(row, col-1, maze, n);
            s.pop_back();
            maze[row][col-1] = 1; // unmarked it
        }
        // right - right cell must not be visited and it must be a free cell
        if(col + 1 < n && maze[row][col+1] != 2 && maze[row][col+1] == 1){
            maze[row][col+1] = 2; // marked visited
            s += 'R';
            f(row, col+1, maze, n);
            s.pop_back();
            maze[row][col+1] = 1; // unmarked it
        }
        // up - upward cell must not be visited and it must be a free cell
        if(row - 1 >= 0 && maze[row-1][col] != 2 && maze[row-1][col] == 1){
            maze[row-1][col] = 2; // marked visited
            s += 'U';
            f(row-1, col, maze, n);
            s.pop_back();
            maze[row-1][col] = 1; // unmarked it
        }
        // down - downward cell must not be visited and it must be a free cell
        if(row + 1 < n && maze[row+1][col] != 2 && maze[row+1][col] == 1){
            maze[row+1][col] = 2; // marked visited
            s += 'D';
            f(row+1, col, maze, n);
            s.pop_back();
            maze[row+1][col] = 1; // unmarked it
        }
        
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        ans.clear();
        int n = maze.size();
        maze[0][0] = 2; // marked visited
        f(0, 0, maze, n);
        maze[0][0] = 1; // unmarked it
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// Method 2 using unordered_set<pair<int,int>>
struct pair_hash { // beacuse GFG was not able to understand what is pair<int,int>>
    size_t operator()(const pair<int, int>& p) const noexcept {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};
vector<string> ans;
string s = "";
unordered_set<pair<int, int>, pair_hash> visited;
class Solution {
  public:
    void f(int row, int col, vector<vector<int>>& maze, int n){
        if(row == n-1 && col == n-1){
            ans.push_back(s);
            return;
        }
        if(row < 0 || row >= n || col < 0 || col >= n){
            return;
        }
        // left - left cell must not be visited and it must be a free cell
        if(col - 1 >= 0 && !visited.count({row,col-1}) && maze[row][col-1] == 1){
            visited.insert({row,col-1});
            s += 'L';
            f(row, col-1, maze, n);
            s.pop_back();
            visited.erase({row,col-1});
        }
        // right - right cell must not be visited and it must be a free cell
        if(col + 1 < n && !visited.count({row,col+1}) && maze[row][col+1] == 1){
            visited.insert({row,col+1});
            s += 'R';
            f(row, col+1, maze, n);
            s.pop_back();
            visited.erase({row,col+1});
        }
        // up - upward cell must not be visited and it must be a free cell
        if(row - 1 >= 0 && !visited.count({row-1,col}) && maze[row-1][col] == 1){
            visited.insert({row-1,col});
            s += 'U';
            f(row-1, col, maze, n);
            s.pop_back();
            visited.erase({row-1,col});
        }
        // down - downward cell must not be visited and it must be a free cell
        if(row + 1 < n && !visited.count({row+1,col}) && maze[row+1][col] == 1){
            visited.insert({row+1,col});
            s += 'D';
            f(row+1, col, maze, n);
            s.pop_back();
            visited.erase({row+1,col});
        }
        
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        ans.clear();
        int n = maze.size();
        visited.insert({0, 0}); // imp
        f(0, 0, maze, n);
        visited.erase({0, 0});
        sort(ans.begin(), ans.end());
        return ans;
    }
};
int main(){
    
    return 0;
}