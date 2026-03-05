#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    vector<int> khubu;
    unordered_map<int, int> m;
    unordered_set<int> khushbu;
    while(t --){
        int n;
        cin>>n;
        vector<int> a(n);
        int sum = 0;
        for(int i = 0; i<n; i++){
            cin>>a[i];
            sum += a[i];
        }
        if(sum % 2 == 0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}