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
        int neg = 0, pos = 0;
        for(int i = 0; i<n; i++){
            cin>>a[i];
            if(a[i] == -1) neg ++;
            else pos++;
        }
        int op = 0;
        while(neg > pos || neg % 2 == 1){ // jab tak dono false nhi ho jate
            neg --;
            pos++;
            op++;
        }
        cout<<op<<endl;
    }
}