#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll pow(ll a, ll b){
    ll res = 1;
    while(b > 0){
        if(b & 1) res = res*a;
        b = b>>1;
        a *= a;
    }
    return res;
}
ll gcd(ll a, ll b) {
    if(b > a) return gcd(b, a);
    if(b == 0) return a;
    return gcd(a % b, b);
}
int main(){
    int t;
    cin>>t;
    vector<int> khubu;
    unordered_map<int, int> mp;
    unordered_set<int> khushbu;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i = 0; i<n; i++){
            cin>>a[i];
        }
        unordered_set<int> s;
        for(int i = 0; i<n; i++){
            s.insert(a[i]);
        }
        for(int i = 0; i<=n; i++){
            if(!s.count(i) && i < pow(2,n)){
                cout<<i<<endl;
                break;
            }
        }
    }
}