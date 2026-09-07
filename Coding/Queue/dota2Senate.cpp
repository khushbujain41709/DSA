// Leetcode 649
// Suppose:
// senate = "RDRD"
// There are 4 senators sitting in this order:
// Index:    0   1   2   3
//           R   D   R   D
// The voting happens from left to right: R → D → R → D
// Then the next round starts again from the beginning, but senators who have been banned are skipped.
// The first active senator has a huge advantage because they get to ban an opponent before that opponent gets a chance to act.
// This naturally leads to maintaining two queues, comparing their front.
// // overall order of senators who still have a turn
#include<iostream>
#include<queue>
using namespace std;
string predictPartyVictory(string senate) {
    queue<int> q, r , d;
    int n = senate.size();
    for(int i = 0;i<n;i++){
        q.push(i);
        if(senate[i] == 'R'){
            r.push(i);
        }
        else if(senate[i] == 'D'){
            d.push(i);
        }
    }
    while(q.size() > 1){
        if(senate[q.front()] == 'R'){
            if(d.size() != 0){
                int x = d.front();
                d.pop();
                senate[x] = 'X'; // banned
                q.push(q.front());
                q.pop();
                r.push(r.front());
                r.pop();
            }
            else{
                return "Radiant";
            }
        }
        else if(senate[q.front()] == 'D'){
            if(r.size() != 0){
                int x = r.front();
                r.pop();
                senate[x] = 'X'; // banned
                q.push(q.front());
                q.pop();
                d.push(d.front());
                d.pop();
            }
            else{
                return "Dire";
            }
        }
        else{ // if char is X -> //senate[q.front()] = 'X' -> banned
            q.pop();
        }
    }
    if(senate[q.front()] == 'R'){
        return "Radiant";
    }
    else if(senate[q.front()] == 'D'){
        return "Dire";
    }
    return ""; // to avoid compiler error
}
int main(){
    
    return 0;
}