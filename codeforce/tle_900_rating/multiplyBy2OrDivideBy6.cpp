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
        int count = 0;
        if(n == 1){
            count = 0;
        }
        else if(n % 3 == 0 || n % 2 == 0){
            // power of 2
            int x = n;
            int two = 0;
            while(x>0 && x % 2 == 0){
                x /= 2;
                two++;
            }
            // power of 3
            int three = 0;
            while(x>0 && x % 3 == 0){
                x /= 3;
                three++;
            }
            if(x != 1){
                cout<<-1<<endl;
                continue;
            }
            if(two > three) count = -1;
            else{
                int diff = three - two;
                count += diff + three;
            }
        }
        else count = -1;
        cout<<count<<endl;
    }
}