// Upper bound of n is : smallest index such that arr[i] > n
// https://www.geeksforgeeks.org/problems/implement-upper-bound/1
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        int n = arr.size();
        int l = 0;
        int h = n-1;
        int ans = n;
        while(l <= h){
            int mid = l + (h-l)/2;
            if(arr[mid] > target){
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
// Use -> int idx = upper_bound(arr.begin(), arr.end(), target) - arr.begin();
// or int idx = upper_bound(arr, arr + n, target) - arr;
// To search only in range - [2,7) = [2,6], we use upper_bound(arr+2, arr + 7, target) - arr;
// upper_bound(arr.begin(), arr.end(), target) - This will give iterator of the required index so for index we subtract begin iterator.
class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        int n = arr.size();
        int idx = upper_bound(arr.begin(), arr.end(), target) - arr.begin();
        return idx;
    }
};

int main(){
    
    return 0;
}