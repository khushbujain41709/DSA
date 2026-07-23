#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    vector<int> khubu;
    unordered_map<int, int> m;
    unordered_set<int> khushbu;
    while(t --){
        int n,a,b;
        cin>>n>>a>>b;
        if(n == a && n == b){
            cout<<"Yes"<<endl;
            continue;
        }
        int rem = n - (a+b);
        if(rem >= 2){
            cout<<"Yes"<<endl;
        }
        else cout<<"No"<<endl;
    }
}