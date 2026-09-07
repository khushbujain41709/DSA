// https://www.geeksforgeeks.org/problems/implement-lower-bound/1
// // Lower bound of n is : smallest index such that arr[i] >= n
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        int n = arr.size();
        int l = 0;
        int h = n-1;
        int ans = n;
        while(l <= h){
            int mid = l + (h-l)/2;
            if(arr[mid] >= target){
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
// CP Tip -
// Use -> int idx = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
// or int idx = lower_bound(arr, arr + n, target) - arr.begin();
// To search only in range - [2,7) = [2,6], we use lower_bound(arr+2, arr + 7, target) - arr.begin();
// lower_bound(arr.begin(), arr.end(), target) - This will give iterator of the required index so for index we subtract begin iterator.
class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        int n = arr.size();
        int idx = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
        return idx;
    }
};

int main(){
    
    return 0;
}