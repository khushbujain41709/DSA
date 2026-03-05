// https://www.geeksforgeeks.org/problems/minimum-sum-of-two-elements-from-two-arrays0253/1
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int minSum(vector<int>& arr1, vector<int>& arr2) {
    int n = arr1.size();
    // case ->
    // arr1 = 3 4 5 3 8
    // arr2 = 1 3 4 2 9
    int min1 = INT_MAX; // min element from array 1
    int idx1 = 0; // min element idx of array 1
    int s_min1 = INT_MAX; // second min element from array 1
    int min2 = INT_MAX; // min element from array 2
    int s_min2 = INT_MAX; // second min element from array 2
    int idx2 = 0;// min element idx of array 2
    // Finding first min and second min of array 1
    for(int i = 0; i<n; i++){
        if(min1 > arr1[i]){
            s_min1 = min1;
            min1 = arr1[i];
            idx1 = i;
        }
        else if(s_min1 > arr1[i]){ // min se bda but s_min se chota element mila toh
            s_min1 = arr1[i];
        }
    }
    // Finding first min and secon min of array 2
    for(int i = 0; i<n; i++){
        if(min2 > arr2[i]){
            s_min2 = min2;
            min2 = arr2[i];
            idx2 = i;
        }
        else if(s_min2 > arr2[i]){ // min se bda but s_min se chota element mila toh
            s_min2 = arr2[i];
        }
    }
    if(idx1 != idx2){
        return min1 + min2;
    }
    else{
        return min(min1 + s_min2 , min2 + s_min1);
    }
}
int main(){
    
    return 0;
}