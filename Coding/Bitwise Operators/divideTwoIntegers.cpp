// Leetcode 29
#include<iostream>
#include<climits>
using namespace std;
// Illegal Way but accepted
int divide(int dividend, int divisor) {
    long long x = (long long)dividend/(long long)divisor;
    if(x >= INT_MAX){
        return INT_MAX;
    }
    if(x <= INT_MIN){
        return INT_MIN;
    }
    return (int)x;
}
// Half correct Method
// dividend = (quotient) * divisor + remainder
// For 58/5, 58 = (11) * 5 + 3
// 58 = (2^3 + 2^1 + 2^0) * 5 + 3                // --- (I)
// 58 = [(2^3 * 5) + (2^1 * 5) + (2^0 * 5)] + 3  // --- (II)
// INT_MIN = -2147483648,
// INT_MAX = 2147483647
long long divi(long long dividend, long long divisor){
    long long i = 0;
    while(true){
        if((1LL << i)*divisor > dividend){
            return i-1;
        }
        i++;
    }
}
int divide(int dividend, int divisor) {
    long long sum = 0;
    if(dividend == INT_MIN && divisor == -1) return INT_MAX; // imp case
    // abs(INT_MIN) causes overflow because INT_MIN = -2^31, and its absolute value 2^31 cannot fit in an int.
    if(dividend == INT_MIN && divisor == 1) return INT_MIN;
    long long x = dividend;
    long long y = divisor;
    x = abs(x);
    y = abs(y);
    while(x >= y){
        long long power = divi(x, y);
        sum += (1LL<<power);
        x -= (1LL<<power)*y;
    }
    if(dividend > 0 && divisor < 0){
        sum = -sum;
    }
    else if(dividend < 0 && divisor > 0){
        sum = -sum;
    }
    if(sum >= INT_MAX){
        return INT_MAX;
    }
    if(sum <= INT_MIN){
        return INT_MIN;
    }
    return (int)sum;
}
/*
int divide(int dividend, int divisor) {
    if(dividend == divisor)
        return 1;
    bool isPositive = (dividend<0 == divisor<0);    // if both are of same sign, answer is positive
    unsigned int a = abs(dividend);
    unsigned int b = abs(divisor);
    unsigned int ans = 0;
    while(a >= b){  // while dividend is greater than or equal to divisor
        short q = 0;
        while(a > (b<<(q+1)))
            q++;
        ans += (1<<q);  // add the power of 2 found to the answer
        a = a - (b<<q);  // reduce the dividend by divisor * power of 2 found
    }
    if(ans == (1<<31) and isPositive)   // if ans cannot be stored in signed int
        return INT_MAX;
    return isPositive ? ans : -ans;
}
*/
int main(){
    
    return 0;
}