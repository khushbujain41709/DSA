#include<iostream>
#include<vector>
#include<climits>
using namespace std;
vector<int> segTree;
void buildTree(vector<int>&v, int idx, int lo, int hi){
    if(lo == hi){
        segTree[idx] = v[lo]; // or v[hi] as both are same
        return;
    }
    int mid = lo + (hi-lo)/2;
    buildTree(v, 2*idx+1, lo, mid);
    buildTree(v, 2*idx+2, mid+1, hi);
    segTree[idx] = max(segTree[2*idx+1], segTree[2*idx+2]);
}
int getMax(int& l, int& r, int idx, int lo, int hi){
    if((r < lo) || (hi < l)){ // outside case
        return INT_MIN;
    }
    else if((l <= lo) && (hi <= r)){ // fully overlapping
        return segTree[idx];
    }
    else{
        int mid = lo + (hi-lo)/2;
        int leftMax = getMax(l,r,2*idx+1,lo,mid);
        int rightMax = getMax(l,r,2*idx+2,mid+1,hi);
        return max(leftMax, rightMax);
    }
}
int main(){
    vector<int> v = {1,4,2,8,6,4,9,3};
    int n = v.size();
    segTree.resize(4*n);
    buildTree(v, 0, 0, n-1);
    int l,r; // user range query
    cout<<"Enter the range: ";
    cin>>l>>r;
    cout<<getMax(l, r, 0, 0, n-1)<<endl;
    return 0;
}