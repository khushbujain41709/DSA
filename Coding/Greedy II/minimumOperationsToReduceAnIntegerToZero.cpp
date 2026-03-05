// Leetcode 2571
#include<iostream>
using namespace std;
class Solution {
public:
    int count = 0; // global variable
    int minOperations(int n){
        // ek bar 2 ki power mei change ho gya toh ek hee step lagega
        // so n ko 2 ki power mei change krna hai
        // Find nearest 2 ki power
        if(n == 0) return count;
        while(n != 0){
            int nearestLeft = 0;
            int nearestRight = 0;
            int i = 0;
            while(true){
                if(n < (1<<i)){
                    nearestRight = (1<<i);
                    break;
                }
                else if(n == (1 << i)){
                    return count + 1;
                }
                else if(n > (1<<i)){
                    nearestLeft = 1<<i;
                }
                i++;
            }
            int diff = min(n - nearestLeft, nearestRight - n);
            count++;
            minOperations(diff);
        }
        return count;
    }
};
int main(){
    
    return 0;
}