#include<bits/stdc++.h>
using namespace std;
/*
If an array consists of no negative numbers then two cases arise:
1) If array has no zero only positive numbers exists then answer is minimum positive number
2) If array has zero or zeroes with or without positive numbers then answer is 0

If an array has negative numbers then two cases arises:
1) If an array consists of odd number of negative numbers then answer is product of all negative numbers * product of all positive number(non zero)
2) If an array consists of even number of negative numbers then answer is produxt of all negative except the largest negative * product of all positive number(non zero)
*/
int minProduct(vector<int>& nums){
    int n = nums.size();
    int negCount = 0;
    int zero = 0;
    int posiProd = 1;
    int negProd = 1;
    int maxxNeg = INT_MIN;
    int minPos = INT_MAX;
    for(int i = 0; i<n; i++){
        if(nums[i] < 0){
            negCount++;
            negProd *= nums[i];
            maxxNeg = max(maxxNeg, nums[i]);
        }
        else if(nums[i] == 0) zero++;
        else{
            posiProd *= nums[i];
            minPos = min(minPos, nums[i]);
        }
    }
    if(negCount == 0 && zero == 0){
        return minPos;
    }
    else if(negCount == 0 && zero != 0){
        return zero;
    }
    else if(negCount % 2 != 0){
        return posiProd*negProd;
    }
    else{ // negCount % 2 != 0
        return posiProd*(negProd / maxxNeg);
    }
}
int main(){
    
    return 0;
}