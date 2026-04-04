// Leetcode 605
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sizzi = flowerbed.size();
        int count = 0;
        for(int i = 0; i<sizzi; i++){
            if(flowerbed[i] == 0){
                if((i == 0 || flowerbed[i-1] == 0) && (i == sizzi-1 || flowerbed[i+1] == 0)){
                    flowerbed[i] = 1;
                    // We should also update the array. 
                    // Otherwise the next position may incorrectly think the previous spot is empty.
                    count++;
                }
            }
        }
        if(n <= count) return true;
        else return false;
    }
};
int main(){
    
    return 0;
}