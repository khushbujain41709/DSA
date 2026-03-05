// https://www.spoj.com/problems/CHOCOLA/
#include<bits/stdc++.h>
using namespace std;
int minCost(int n, int m, vector<int>& x, vector<int>& y) {
    // n is width - horizontal
    // m is length - vertical
    int horizontalBlocks = 1;
    int verticalBlocks = 1;
    sort(x.rbegin(), x.rend());// x is vertical edge which increases horizontal blocks
    sort(y.rbegin(), y.rend());
    int i = 0;
    int j = 0;
    long long cost = 0;
    while(i<m-1 && j<n-1){
        // or i<x.size() && j<y.size()
        if(x[i] >= y[j]){
            cost += 1LL*x[i]*verticalBlocks;
            i++;
            horizontalBlocks++;
        }
        else if(x[i] <= y[j]){
            cost += 1LL*y[j]*horizontalBlocks;
            j++;
            verticalBlocks++;
        }
    }
    while(j < n-1){
        cost += 1LL*y[j]*horizontalBlocks;
        j++;
        verticalBlocks++;
    }
    while(i < m-1){
        cost += 1LL*x[i]*verticalBlocks;
        i++;
        horizontalBlocks++;
    }
    return cost;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;
        vector<int> x(m),y(n);
        for(int i = 0; i<m-1; i++){
            cin>>x[i];
        }
        for(int i = 0; i<n-1; i++){
            cin>>y[i];
        }
        cout<<minCost(n,m,x,y)<<endl;
    }
    return 0;
}