// Leetcode 3691
// Khushbu, Read question before reading solution
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // When you extend a subarray: [l,r] to [l,r+1] then: max can only increase and min can only decrease. Therefore: max-min can only increase. Thus for every fixed l we get a sorted sequence. 
    // Repeat k times: pop largest, add to answer, push previous element.
    // What information must heap store? Not just value. Need: (l,r) because after removing value(l,r) we must push value(l,r-1).
    // Heap node: (value,l,r)
    class node{
        public:
        long long mx;
        long long mn;
    };
    vector<node> segTree;
    vector<int> nums;
    void buildTree(int idx, int lo, int hi){
        if(lo == hi){
            segTree[idx] = {(long long)nums[lo], (long long)nums[lo]};
            return;
        }
        int mid = lo + (hi-lo)/2;
        buildTree(2*idx+1, lo, mid);
        buildTree(2*idx+2, mid+1, hi);
        segTree[idx].mx = (long long)max(segTree[2*idx+1].mx, segTree[2*idx+2].mx);
        segTree[idx].mn = (long long)min(segTree[2*idx+1].mn, segTree[2*idx+2].mn);
    }
    node query(int& l, int& r, int lo, int hi, int idx){
        if(r < lo || hi < l) return {LLONG_MIN, LLONG_MAX};
        else if(l <= lo && hi <= r) return segTree[idx];
        else{
            int mid = lo+(hi-lo)/2;
            node left = query(l, r, lo, mid, 2*idx+1);
            node right = query(l, r, mid+1, hi, 2*idx+2);
            return {
                (long long)max(left.mx, right.mx),
                (long long)min(left.mn, right.mn)
            };
        }
    }
    long long getValue(int l, int r, int n){
        node curr = query(l, r, 0, n-1, 0);
        return curr.mx - curr.mn;
    }
    long long maxTotalValue(vector<int>& arr, int k) {
        int n = arr.size();
        nums = arr;
        segTree.resize(4*n);
        buildTree(0, 0, n-1);
        priority_queue<tuple<long long, long long, long long>> pq;
        // push (l, n-1) for every row
        for(int l = 0; l<n; l++){
            pq.push(
                {getValue(l, n-1, n), (long long)l, (long long)n-1}
            );
        }
        long long ans = 0;
        while(k--){
            auto[val, l, r] = pq.top();
            pq.pop();
            ans += val;
            if(r > l){
                pq.push(
                    {getValue(l, r-1, n), (long long)l, (long long)r-1}
                );
            }
        }
        return ans;
    }
};
int main(){
    
    return 0;
}