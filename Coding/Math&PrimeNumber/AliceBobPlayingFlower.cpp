// Leetcode 3021
#include<iostream>
using namespace std;
long long flowerGame(int n, int m){
    // Approach 1
    // Giving Memory Limit Exceeded
    // vector<pair<long long, long long>> ans;
    // long long size = 0;
    // for(long long i = 1; i<=n; i++){
    //     for(long long j = 1; j<=m ; j++){
    //         if((i+j) % 2 != 0){
    //             ans.push_back({i,j});
    //             size ++;
    //             ans.clear();
    //         }
    //     }
    // }
    // return size;

    // Approach 2
    // We need to find odd sum pairs so even+odd = odd and odd+even = odd
    long long ans = 0;
    long long evenN = 0;
    long long oddN = 0;
    long long nAns = 0;
    long long evenM = 0;
    long long oddM = 0;
    long long mAns = 0;
    if(n % 2 == 0){
        evenN = n/2;
        oddN = n/2;
    }
    else{
        evenN = (n-1)/2;
        oddN = (n+1)/2;
    }
    if(m % 2 == 0){
        evenM = m/2;
        oddM = m/2;
    }
    else{
        evenM = (m-1)/2;
        oddM = (m+1)/2;
    }
    mAns = evenM*oddN;
    nAns = evenN*oddM;
    return mAns + nAns;
}
int main(){
    return 0;
}