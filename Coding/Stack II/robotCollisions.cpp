// Leetcode 2751
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<pair<int, int>> v;
        int n = positions.size();
        for(int i = 0; i<n; i++){
            pair<int, int> p = {positions[i], i};
            v.push_back(p);
        }
        sort(v.begin(), v.end());
        stack<int> st; // to store indices
        for(auto x: v){
            int i = x.second;
            if(directions[i] == 'R'){
                st.push(i);
            }
            else{ // going left -> robot can collide
                while(!st.empty() && healths[i] > 0 && directions[st.top()] == 'R'){
                    int j = st.top();
                    if(healths[i] == healths[j]){
                        st.pop();
                        healths[i] = 0;
                        healths[j] = 0;
                        break; 
                        // while loop se nikal jana hai - baki stack k elements se check nhi krna hai kyuki dono robots destroy ho gye hai
                    }
                    else if(healths[i] > healths[j]){
                        // new robot ki health jyada hai - jo robot left mei ja rha hai uski health jyada hai
                        // vo right robot ko destroy krke baki right robots ko bhi destroy kr skta hai
                        // so no break here
                        st.pop();
                        healths[i]--;
                        healths[j] = 0;
                    }
                    else{ // healths[i] < healths[j]
                        // new robot ki health kam hai - jo robot left mei ja rha hai uski health kam hai
                        // left robot right robot se destroy ho jayega aur right robot survive krega
                        // so no break here
                        healths[j]--;
                        healths[i] = 0;
                    }
                }
                if(healths[i] > 0){
                    st.push(i);
                }
            }
        }
        vector<int> ans;
        for(int i = 0; i<n; i++){
            if(healths[i] > 0){
                ans.push_back(healths[i]);
            }
        }
        return ans;
    }
};
int main(){
    
    return 0;
}