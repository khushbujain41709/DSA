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
        string s;
        cin>>s;
        int n = s.size();
        int count = 0;
        stack<char> st;
        st.push(s[0]);
        for(int i = 1; i<n; i++){
            if(!st.empty() && st.top() != s[i]){
                // Suppose the stack becomes empty after pop() 
                // hence !st.empty()
                st.pop();
                count++;
            }
            else{
                st.push(s[i]);
            }
        }
        if(count % 2 == 0){
            cout<<"NET"<<endl;
        }
        else cout<<"DA"<<endl;
    }
}