// If we find any two number with gcd <= 2 then answer is YES else answer is NO
// gcd(a,b) <= min(a,b)
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
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i = 0; i<n; i++){
            cin>>a[i];
        }
        bool flag = false;
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if(__gcd(a[i], a[j]) <= 2){ 
                    // c++ gcd STL having TC = O(log2(min(a[i], a[j])))
                    flag = true;
                }
            }
        }
        if(flag == false){
            cout<<"No"<<endl;
        }
        else{
            cout<<"Yes"<<endl;
        }
    }
}