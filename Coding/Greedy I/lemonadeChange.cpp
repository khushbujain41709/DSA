// Leetcode 860
#include<iostream>
#include<vector>
using namespace std;
bool lemonadeChange(vector<int>& bills) {
    int n = bills.size();
    int fives = 0;
    int tens = 0;
    for(int i = 0; i<n; i++){
        if(bills[i] == 5){
            fives++;
        }
        else if(bills[i] == 10){
            if(fives == 0){
                return false;
            }
            fives --;
            tens++;
        }
        else{ // if bills[i] == 20
            if(tens >= 1 && fives >= 1){
                tens --;
                fives--;
            }
            else if(tens == 0 && fives >= 3){
                fives -= 3;
            }
            else{
                return false;
            }
        }
    }
    return true;
}
int main(){
    
    return 0;
}