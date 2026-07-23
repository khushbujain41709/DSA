#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll t;
    cin>>t;
    vector<int> khubu;
    unordered_map<int, int> mp;
    unordered_set<int> khushbu;
    while(t--){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        if(b == d){
            if(a >= c){
                cout<<(a-c)<<endl;
            }
            else{
                cout<<-1<<endl;
            }
        }
        else if(b > d){
            cout<<-1<<endl;
        }
        else{
            ll count = 0;
            count += (d-b);
            // Example: a=0, b=0, c=4, d=5, move5 diagonals - reach (5,5), Need 1 left move so answer 6.
            if(a+(d-b) >= c){
                count += (a+(d-b)-c);
            }
            else{
                cout<<-1<<endl;
                continue;
            }
            cout<<count<<endl;
        }
    }
}