// https://www.geeksforgeeks.org/problems/who-will-win-1587115621/1
#include<BITS/STDC++.H>
using namespace std;
class Solution {
  public:
    bool binary(vector<int>& arr, int l, int h, int k){
        if(l > h) return false;
        int mid = l + (h-l)/2;
        if(arr[mid] == k) return true;
        else if(arr[mid] > k){
            return binary(arr, l, mid-1, k);
        }
        else return binary(arr, mid+1, h, k);
    }
    bool binarySearch(vector<int>& arr, int k) {
        int n = arr.size();
        return binary(arr, 0, n-1, k);
    }
};
int main(){
    
    return 0;
}