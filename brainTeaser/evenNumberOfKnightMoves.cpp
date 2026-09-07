// Leetcode 3996
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        bool first = (start[0]%2 == target[0]%2);
        bool second = (start[1]%2 == target[1]%2);
        if(first == second) return true;
        else return false;
    }
};
int main(){
    
    return 0;
}