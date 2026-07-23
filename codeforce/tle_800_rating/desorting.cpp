#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    vector<int> khubu;
    unordered_map<int, int> m;
    unordered_set<int> khushbu;
    while(t --){
        long long n;
        cin>>n;
        vector<long long> a(n);
        for(int i = 0; i<n; i++){
            cin>>a[i];
        }
        long long ans = INT_MAX;
        for(int i = 0; i< n-1; i++){
            if(a[i] <= a[i+1]){ // sorted
                long long operations = ((a[i+1] - a[i]) / 2) + 1; // try and see, +1 is for 9,9 to make it 10, 8
                ans = min(ans, operations);
            }
            else{ // unsorted
                ans = 0;
            }
        }
        cout<<ans<<endl;
    }
}