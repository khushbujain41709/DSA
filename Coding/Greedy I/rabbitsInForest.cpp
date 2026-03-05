// Leetcode 781
// Example - [5,5,5,5,5,5,5] = 12 as 5,5,5,5,5,5 these six rabbits have same color so 6 are in total but next 5 will be of different color
#include<bits/stdc++.h>
using namespace std;
int numRabbits(vector<int>& answers) {
    int n = answers.size();
    unordered_map<int, int> m;
    int ans = 0;
    for(int i = 0; i<n; i++){
        if(!m[answers[i] + 1]){
            ans += answers[i] + 1; // we started a new color group
            if(answers[i] == 0){ 
                // 1:1 in case 0 in array, rabbit says only I exist of my color so no need to do entry in map
                continue;
            }
            m[answers[i] + 1] = 1;
        }
        else{
            m[answers[i] + 1]++;
            int key = answers[i] + 1;
            int val = m[key];
            if(key == val){
                // we found all rabbits of the group
                // so eliminate the group
                m.erase(key);
            }
        }
    }
    return ans;
}
int main(){
    
    return 0;
}