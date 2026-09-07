// Ceil is lower bound of an array
// Ceil is smallest number in the array that is >= x
// Floor is largest number in the array that is <= x
// https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
        int n = arr.size();
        int l = 0;
        int h = n-1;
        int ans = -1;
        while(l <= h){
            int mid = l + (h-l)/2;
            if(arr[mid] <= x){
                ans = mid;
                l = mid+1;
            }
            else{
                h = mid-1;
            }
        }
        return ans;
    }
};
class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        int n = arr.size();
        int l = 0;
        int h = n-1;
        int ans = -1;
        while(l <= h){
            int mid = l + (h-l)/2;
            if(arr[mid] >= x){
                ans = mid;
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};
int main(){
    
    return 0;
}