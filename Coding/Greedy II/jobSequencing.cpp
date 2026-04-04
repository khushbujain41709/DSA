// https://www.naukri.com/code360/problems/job-sequencing-problem_1169460
#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
vector<int> jobScheduling(vector<vector<int>> &jobs){
    int n = jobs.size();
    vector<tuple<int, int, int>> v;
    int maxx = INT_MIN;
    for(int i = 0; i<n; i++){
        v.push_back({jobs[i][2], jobs[i][1], jobs[i][0]});
        maxx = max(maxx, jobs[i][1]);
    }
    sort(v.rbegin(), v.rend());
    vector<int> ans(maxx+1,-1); // maxx+1 as index start from 0
    int count = 0;
    int maxProfit = 0;
    for(int i = 0; i<n; i++){
        if(ans[get<1>(v[i])] == -1){
            ans[get<1>(v[i])] = get<2>(v[i]);
            count++;
            maxProfit += get<0>(v[i]);
        }
        else{ // already we performed work on that day
            int j = get<1>(v[i])-1;
            while(j>0){ // we can't complete job at j = 0
                if(ans[j] == -1){
                    ans[j] = get<2>(v[i]);
                    count++;
                    maxProfit += get<0>(v[i]);
                    break;
                }
                j--;
            }
        }
    }
    return {count, maxProfit};
}
int main(){
    
    return 0;
}