// If I have more than one distinct element then the answer exists always.
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
        vector<int> a(n), b, c;
        int maxx = INT_MIN;
        for(int i = 0; i<n; i++){
            cin>>a[i];
            maxx = max(maxx, a[i]);
        }
        for(int i = 0; i<n; i++){
            if(a[i] == maxx){
                c.push_back(a[i]);
            } 
            else b.push_back(a[i]);
        }
        if(b.size() == 0){
            cout<<-1<<endl;
            continue;
        }
        else{
            cout<<b.size()<<" "<<c.size()<<endl;
        }
        for(int i = 0; i<b.size(); i++){
            cout<<b[i]<<" ";
        }
        cout<<endl;
        for(int i = 0; i<c.size(); i++){
            cout<<c[i]<<" ";
        }
        cout<<endl;
    }
}