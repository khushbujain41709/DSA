// https://www.naukri.com/code360/problems/sjf_1172165
#include<bits/stdc++.h>
using namespace std;
float sjf(int n, vector<int> &arrivalTime, vector<int> &burstTime) {
    vector<pair<int, int>> p;
    for(int i = 0; i<n; i++){
        p.push_back({arrivalTime[i], burstTime[i]});
    }
    sort(p.begin(), p.end());
    int completed = 0;
    vector<int> done(n, false);
    float waitingTime = 0;
    int curr_time = 0;
    while(completed < n){
        int minBurst = INT_MAX;
        int idx = -1;
        for(int i = 0; i<n; i++){
            if(!done[i] && p[i].first <= curr_time){
                if(minBurst > p[i].second){
                    minBurst = p[i].second;
                    idx = i;
                }
            }
        }
        if(idx == -1){
            curr_time++; // no process available
            continue;
        }
        waitingTime += (float)(curr_time - p[idx].first); // start_time - arrival_time
        curr_time += p[idx].second;
        done[idx] = true;
        completed++;
    }
    return waitingTime/n;
}
int main(){
    
    return 0;
}
/*
Process   Arrival   Burst
P1          0         7
P2          2         4
P3          4         1
P4          5         4

After storing in vector p and sorting by arrival:

p = [(0,7), (2,4), (4,1), (5,4)]
       P1     P2     P3     P4
Initial State: time = 0, completed = 0, done = [F, F, F, F], total_waiting = 0

Iteration 1: Find process with: arrival <= time (0) and minimum burst
Available: P1 only so select P1
Waiting = time - arrival = 0 - 0 = 0, total_waiting = 0
Run P1: time = 0 + 7 = 7, done = [T, F, F, F], completed = 1

Iteration 2: time = 7
Available now: P2 (burst 4), P3 (burst 1), P4 (burst 4)
Pick P3 (smallest burst = 1)
Waiting = 7 - 4 = 3, total_waiting = 0 + 3 = 3
Run P3: time = 7 + 1 = 8, done = [T, F, T, F], completed = 2

Iteration 3: time = 8
Available: P2 (4), P4 (4)
Pick P2 (comes first, both equal)
Waiting = 8 - 2 = 6, total_waiting = 3 + 6 = 9
Run P2: time = 8 + 4 = 12, done = [T, T, T, F], completed = 3

Iteration 4: time = 12
Available: P4
Pick P4
Waiting = 12 - 5 = 7, total_waiting = 9 + 7 = 16
Run P4: time = 12 + 4 = 16, done = [T, T, T, T], completed = 4

Final Calculation
Average Waiting Time = total_waiting/n = (16 / 4) = 4
*/