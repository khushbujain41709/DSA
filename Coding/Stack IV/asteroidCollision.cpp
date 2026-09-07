// Leetcode 735
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        vector<int> ans;
        for(int i = 0; i<n; i++){
            if(!st.empty() && ((asteroids[i] > 0 && st.top() < 0) || asteroids[i] < 0 && st.top() > 0)){
                if(st.top() > 0){ // collision will happen
                    while(!st.empty() && !((st.top() > 0 && asteroids[i] > 0) || (st.top() < 0 && asteroids[i] < 0))){
                        if(-asteroids[i] > st.top()){
                            st.pop();
                        }
                        else if(-asteroids[i] < st.top()){
                            asteroids[i] = 0; // asteroid is destroyed
                            break;
                        }
                        else if(-asteroids[i] == st.top()){
                            st.pop();
                            asteroids[i] = 0; // asteroid is destroyed
                            break;
                        }
                    }
                    // If asteroid is destroyed, don't push it
                    // else push it in the stack
                    if(asteroids[i] != 0) st.push(asteroids[i]);
                }
                else st.push(asteroids[i]);
            }
            else st.push(asteroids[i]);
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main(){
    
    return 0;
}