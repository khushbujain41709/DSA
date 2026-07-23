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
        string s;
        cin>>s;
        int empty = 0; 
        int block = 0;
        for(int i = 0; i<n; i++){
            if(s[i] == '.'){
                empty++;
            }
            else block++;
        }
        bool flag = false;
        for(int i = 0; i<n-2; i++){
            if(s[i] == '.' && s[i+1] == '.' && s[i+2] == '.'){
                cout<<2<<endl;
                flag = true;
                break;
            }
        }
        if(flag == false)cout<<empty<<endl;
    }
}