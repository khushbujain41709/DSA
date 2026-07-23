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
        for(int i = 0; i<n; i++){
            cin>>a[i];
        }
        int count = 0;
        int lastPriority = a[0] % 2;
        for(int i = 1; i<n; i++){
            if(a[i] % 2 == lastPriority){
                count ++;
            }
            lastPriority = a[i] % 2;
        }
        cout<<count<<endl;
    }
}