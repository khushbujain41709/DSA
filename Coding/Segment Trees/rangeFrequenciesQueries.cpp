#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
// Method 1
class RangeFreqQuery {
public:
    vector<unordered_map<int, int>> segTree;
    int n;
    unordered_map<int, int> unite(unordered_map<int, int>& m1, unordered_map<int, int>& m2){
        unordered_map<int, int> ans = m1;
        for(auto x : m2){
            ans[x.first] += x.second; 
            // if common element will be there then their frequencies will be added.
            // Otherwise different element will also be added.
        }
        return ans;
    }
    void buildTree(int idx, int lo, int hi, vector<int>& nums){
        if(lo == hi){
            segTree[idx][nums[lo]] = 1;
            return;
        }
        int mid = lo + (hi-lo)/2;
        buildTree(2*idx+1, lo, mid, nums);
        buildTree(2*idx+2, mid+1, hi, nums);
        segTree[idx] = unite(segTree[2*idx+1] , segTree[2*idx+2]);
    }
    RangeFreqQuery(vector<int>& arr) {
        n = arr.size();
        segTree.resize(4*n);
        buildTree(0, 0, n-1, arr);
    }
    int calculateFreq(int& l, int& r, int lo, int hi, int idx, int& val){
        if(r < lo || hi < l){
            return 0;
        }
        else if(l <= lo && hi <= r){
            if(segTree[idx].count(val)){
                return segTree[idx].at(val);
            }
            else{
                return 0;
            }
        }
        else{
            int mid = lo + (hi-lo)/2;
            int leftSide = calculateFreq(l, r, lo, mid, 2*idx+1, val);
            int rightSide = calculateFreq(l, r, mid+1, hi, 2*idx+2, val);
            return leftSide + rightSide;
        }
        return 0;
    }
    int query(int left, int right, int value){
        return calculateFreq(left, right, 0, n-1, 0, value);
    }
};
int main(){
    
    return 0;
}