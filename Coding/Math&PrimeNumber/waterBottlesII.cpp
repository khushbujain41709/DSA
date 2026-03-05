// Leetcode 3100
#include<iostream>
using namespace std;
int maxBottlesDrunk(int numBottles, int numExchange) {
    int sum = numBottles;
    int empty = numBottles;
    while(empty >= numExchange){
        empty = empty - numExchange;
        numExchange++;
        sum += 1;
        empty += 1; // at every exchange we are getting one full bottle which will be emptied
    }
    return sum;
}
int main(){
    
    return 0;
}