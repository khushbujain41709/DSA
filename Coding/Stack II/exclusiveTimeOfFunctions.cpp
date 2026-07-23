// Leetcode 636
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    /*
        text = "Hello world, welcome to the world!"
        # Find "world" (returns 6)
        print(text.find("world"))
        # Find "world" starting from index 10 (returns 22)
        print(text.find("world", 10))
        # Find "world" between index 10 and 20 (returns -1, not found in range)
        print(text.find("world", 10, 20))
    */
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n,0);
        stack<int> st;
        int count = 0;
        int prev = 0;
        for(string& log: logs){
            int p1 = log.find(':');
            int p2 = log.find(':', p1+1); // start searching from index p1+1
            int id = stoi(log.substr(0, p1));
            int time = stoi(log.substr(p2+1));
            bool isStart;
            if(log[p1+1] == 's') isStart = true;
            else isStart = false;
            if(isStart){
                if(!st.empty()){
                    ans[st.top()] += time - prev; // It ran from prevTime → time
                    // Add that duration to its exclusive time
                }
                st.push(id);
                prev = time; // Update prevTime to start time of new function
            }
            else{
                if(!st.empty()){
                    ans[st.top()] += time - prev + 1; // Function runs inclusive of end time
                    // So we add +1
                    st.pop();
                    prev = time + 1; // Next function(if any) resumes after this time
                }
            }
        }
        return ans;
    }
};
int main(){
    
    return 0;
}