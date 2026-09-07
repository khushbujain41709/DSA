// Leetcode 3876
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        // odd - odd = even
        // even - even = even
        // even - odd = odd
        // odd - even = odd
        // nums1[i] > nums1[j]
        int even = 0;
        int odd = 0;
        for(int i = 0; i<n; i++){
            if(nums1[i] % 2 == 0) even++;
            else odd++;
        }
        if(even == n || odd == n) return true;
        sort(nums1.begin(), nums1.end());
        // nums1[0] is the smallest element.
        // The smallest element cannot subtract anything because there is no smaller element.
        // Therefore: The smallest element's parity can never change.

        // If smallest is even, every element must become even.
        // But any odd element cannot become even because
        // there is no smaller odd element and odd - even = odd
        if(nums1[0] % 2 == 0) return false;
        else return true;
    }
};
int main(){
    
    return 0;
}