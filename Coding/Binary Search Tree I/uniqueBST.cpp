// Leetcode 96
#include<iostream>
using namespace std;
// Method 1 - Giving TLE
long long factorial(long long n){
    long long fact = 1;
    for(int i = 1; i<=n; i++){
        fact *= i;
    }
    return fact;
}
long long combinationNew(long long n){
    // we need to calculated 2nCn
    long long numerator = factorial(2*n);
    long long denominator = factorial(n) * factorial(2*n - n);
    return numerator/denominator;
}
int numTrees(int n) {
    // formula = 2nCn / (n+1)
    n = (long long)n;
    long long numerator = combinationNew(n);
    long long denominator = n+1;
    return (int)(numerator/denominator);
}

// Method 2
// f(i) denotes in how many ways we can get BST with i as the root and [1, i-1] as Left Subtree and [i+1, N] as Right Subtree.
// f(i) = f(i-1) * f(N-i) where f(i-1) is number of nodes in LST and f(N-i) is number of nodes in RST.
// If N - 4 and i is 3 then i-1 is 2 so 2 nodes in LST and N-i is 1 so 1 node in RST.
// G(N) = f(k-1) * f(N-k) where for all k belongs to [1 to N]
// base cases -> N == 0: f(N) = 1
// base cases -> N == 1: f(N) = 1
// base cases -> N == 2: f(N) = 2
int f(int n){
    if(n == 0 || n == 1) return 1;
    if(n == 2) return 2;
    int sum = 0;
    for(int i = 1; i<=n; i++){
        sum += f(i-1) * f(n-i);
    }
    return sum;
}
int numTrees(int n) {
    return f(n);
}
int main(){
    
    return 0;
}