// Leetcode 307
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class NumArray {
public:
    vector<int> segTree;
    int n;
    void buildTree(vector<int>& nums, int idx, int lo, int hi){
        if(lo == hi){
            segTree[idx] = nums[lo];
            return;
        }
        int mid = lo + (hi-lo)/2;
        buildTree(nums, 2*idx+1, lo, mid);
        buildTree(nums, 2*idx+2, mid+1, hi);
        segTree[idx] = segTree[2*idx+1] + segTree[2*idx+2];
    }
    NumArray(vector<int>& nums) {
        n = nums.size();
        segTree.resize(4*n);
        buildTree(nums, 0, 0, n-1);
    }
    int getSum(int idx, int lo, int hi, int& l, int& r){
        if(hi < l || r < lo){
            return 0;
        }
        else if((l <= lo) && (hi <= r)){
            return segTree[idx];
        }
        else{
            int mid = lo + (hi-lo)/2;
            int left = getSum(2*idx+1, lo, mid, l, r);
            int right = getSum(2*idx+2, mid+1, hi, l, r);
            return left + right;
        }
    }
    void updateVal(int idx, int lo, int hi, int index, int val){ // function created
        if(lo == hi){ // update at leaf node
            // segTree[index] = val; This is wrong as index is the index in the original array
            // segTree stores values in tree-index positions
            segTree[idx] = val;
            return;
        }
        int mid = lo + (hi-lo)/2;
        if(index <= mid){
            updateVal(2*idx+1, lo, mid, index, val);
        }
        else updateVal(2*idx+2, mid+1, hi, index, val);
        segTree[idx] = segTree[2*idx+1] + segTree[2*idx+2];
    }
    void update(int index, int val) { // function given
        updateVal(0, 0, n-1, index, val);
    }
    int sumRange(int left, int right) {
        return getSum(0, 0, n-1, left, right);
    }
};
int main(){
    
}