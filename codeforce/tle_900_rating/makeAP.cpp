#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int t;
    cin>>t;
    vector<int> khubu;
    unordered_map<int, int> mp;
    unordered_set<int> khushbu;
    while(t--){
        ll a,b,c;
        cin>>a>>b>>c;
        if((2*b - c) % a == 0 && (2*b - c)/a > 0){
            cout<<"YES"<<endl;
        }
        else if(((c+a) % (2*b)) == 0 && ((c+a) / (2*b)) > 0 && (c+a) % 2 == 0){
            cout<<"YES"<<endl;
        }
        else if((2*b - a) % c == 0 && (2*b - a)/c > 0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}