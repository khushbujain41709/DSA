// Leetcode 1344
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // The angle is simply the difference: |(30H + 0.5M) - 6M|
    // Simplifing = |30H - 5.5M|
    double angleClock(int hour, int minutes) {
        double ans = abs(30*hour - 5.5*minutes);
        if(ans > 180) return double(360) - ans;
        else return ans;
    }
};
int main(){
    
    return 0;
}