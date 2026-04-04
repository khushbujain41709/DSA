// Leetcode Contest - Weekly Contest 495
#include<bits/stdc++.h>
using namespace std;
class EventManager {
public:
    vector<vector<int>> v;
    priority_queue<pair<int, int>> pq;
    unordered_map<int, int> m;
    EventManager(vector<vector<int>>& events) {
        v = events;
        for(int i = 0; i<events.size(); i++){
            m[events[i][0]] = events[i][1];
            pq.push({events[i][1], -events[i][0]});
            // -eventId bcoz: higher priority first, if tie -> smaller eventId first
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        // v[eventId] = newPriority;
        // for(auto x: pq){
        //     if(x.first == eventId){
        //         x.second = newPriority;
        //     }
        // }
        pq.push({newPriority, -eventId});
        m[eventId] = newPriority;
    }
    
    int pollHighest() {
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            int priority = x.first;
            int id = -x.second;
            if(m.count(id) && m[id] == priority){
                m.erase(id);
                return id;
            }
        }
        return -1;
    }
};
/*
Heap does NOT support:
- random access
- updating elements
- iteration + modification

Even if you somehow modified it: Heap property depends on ordering
If you change: (priority, id)
Heap becomes invalid
No automatic reheapify
*/
/*
Use lazy deletion
Instead of:
update existing element
Do:
insert new value
ignore old later

Why This Works
Heap = history of values
Map  = current truth

So:
Heap may have outdated entries
Map tells which one is valid
 */
int main(){
    
    return 0;
}