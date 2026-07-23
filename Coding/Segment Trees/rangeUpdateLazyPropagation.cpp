// Range Update via Lazy Propagation
// Suppose we have a range [l,r] and if we update each index of range seperately then 
// TC = O((r-l)logn) ~ O(nlogn)
// har node pe jaa kr sabse pehle check krna hai ki kuch lazy updates pending toh nhi hai
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
vector<int> segTree;
vector<int> lazy; // for lazy propagation
void buildTree(vector<int>&v, int idx, int lo, int hi){
    if(lo == hi){
        segTree[idx] = v[lo]; // or v[hi] as both are same
        return;
    }
    int mid = lo + (hi-lo)/2;
    buildTree(v, 2*idx+1, lo, mid);
    buildTree(v, 2*idx+2, mid+1, hi);
    segTree[idx] = segTree[2*idx+1] + segTree[2*idx+2];
}
int getSum(int& l, int& r, int idx, int lo, int hi){
    // check for pending lazy updates
    if(lazy[idx] != 0){
        int range = hi-lo+1;
        segTree[idx] += range*lazy[idx];
        // send lazy to left and right child if node is not leaf node
        if(lo != hi){
            lazy[2*idx+1] += lazy[idx];
            lazy[2*idx+2] += lazy[idx];
        }
        lazy[idx] = 0;
    }
    if((r < lo) || (hi < l)){ // outside case
        return 0;
    }
    else if((l <= lo) && (hi <= r)){ // fully overlapping
        return segTree[idx];
    }
    else{
        int mid = lo + (hi-lo)/2;
        int leftSum = getSum(l,r,2*idx+1,lo,mid);
        int rightSum = getSum(l,r,2*idx+2,mid+1,hi);
        return leftSum + rightSum;
    }
}
void updateRange(int idx, int& l, int& r, int lo, int hi, int val){
    if(lazy[idx] != 0){
        int range = hi-lo+1;
        segTree[idx] += range*lazy[idx];
        // send lazy to left and right child if node is not leaf node
        if(lo != hi){
            lazy[2*idx+1] += lazy[idx];
            lazy[2*idx+2] += lazy[idx];
        }
        lazy[idx] = 0;
    }
    if((r < lo) || (hi < l)){ // outside case
        return;
    }
    else if((l <= lo) && (hi <= r)){ // fully overlapping
        int range = hi-lo+1;
        segTree[idx] += range*val;
        if(lo != hi){
            lazy[2*idx+1] += val;
            lazy[2*idx+2] += val;
        }
        return;
    }
    int mid = lo + (hi-lo)/2;
    updateRange(2*idx+1, l, r, lo, mid, val);
    updateRange(2*idx+2, l, r, mid+1, hi, val);
    segTree[idx] = segTree[2*idx+1] + segTree[2*idx+2];
}
int main(){
    vector<int> v = {1,4,2,8,6,4,9,3};
    int n = v.size();
    segTree.clear();
    lazy.clear();
    segTree.resize(4*n);
    lazy.resize(4*n,0);
    buildTree(v, 0, 0, n-1);
    int l,r; // user range query
    cout<<"Enter the range: ";
    cin>>l>>r;
    cout<<getSum(l, r, 0, 0, n-1)<<endl;
    updateRange(0, l, r, 0, n-1, 2);
    cout<<getSum(l, r, 0, 0, n-1)<<endl;
    return 0;
}