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
        int sum = a+b;
        if(n == a == b){
            cout<<"Yes"<<endl;
        }
        else if(sum >= n){
            cout<<"No"<<endl;
        }
        else cout<<"Yes"<<endl;
    }
}