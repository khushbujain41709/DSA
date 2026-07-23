// Leetcode 2600
#include<iostream>
using namespace std;
int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
    if(numOnes >= k){
        return k;
    }
    else if(numOnes + numZeros >= k){
        return numOnes;
    }
    else{
        int rem = k - (numOnes+numZeros);
        int sum = rem*-1 + numOnes;
        return sum;
    }
}
int main(){
    
    return 0;
}