//Leetcode - 875
// low = 1 as minimum she can eat 1 banana from a pile in given hour.
// high = max element as she can eat banana of a single pile at a time.
#include<iostream>
#include<climits>
#include<vector>
#include<math.h>
using namespace std;
bool check(int speed,vector<int>& piles, int h){
    long long count = 0;
    // if(count > h) return false; instead of doing long long in count everywhere we can do this.
    for(int i = 0;i<piles.size();i++){
        if(piles[i] <= speed){
            count ++;
        }
        else if(piles[i] % speed == 0){
            count += (long long)piles[i]/speed;
        }
        else{
            count += (long long)(piles[i]/speed) + 1;
        }
    }
    if(count > (long long)h) return false;// comparison between same data types
    else return true;
}
int minEatingSpeed(vector<int>& piles, int h){
    int n = piles.size();
    int maxx = piles[0];
    for(int i = 0;i<n;i++){
        if(maxx < piles[i]){
            maxx = piles[i];
        }
    }
    int low = 1;
    int high = maxx;
    int ans = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(check(mid,piles,h)){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        } 
    }
    return ans; 
}

// Solution 2
class Solution {
public:
    bool check(int k, vector<int>& piles, int h){
        int n = piles.size();
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += ceil(piles[i] / (double)k);
        }
        if(sum <= h) return true;
        else return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxx = INT_MIN;
        for(int i = 0; i<n; i++){
            maxx = max(maxx, piles[i]);
        }
        int l = 1;
        int hi = maxx;
        while(l<hi){
            int mid = l + (hi-l)/2;
            if(check(mid, piles, h) == true){
                // This mid(k) satisfies the condition maybe there can be smaller k
                hi = mid;
            }
            else l = mid+1;
        }
        return l;
    }
};
int main(){
    vector<int> v = {30,11,23,4,20};
    int hours = 5;
    cout<<minEatingSpeed(v,hours);
    return 0;
}