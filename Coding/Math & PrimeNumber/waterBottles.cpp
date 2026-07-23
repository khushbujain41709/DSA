// Leetcode 1518
#include<iostream>
using namespace std;
int numWaterBottles(int numBottles, int numExchange) {
    int sum = numBottles;
    while(numBottles >= numExchange){
        int full = numBottles/numExchange;
        int empty = numBottles % numExchange;
        sum += full;
        numBottles = full + empty;
    }
    return sum;
}
int main(){
    
    return 0;
}