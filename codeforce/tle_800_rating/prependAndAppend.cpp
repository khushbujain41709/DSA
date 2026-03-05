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
        int i = 0; 
        int j = n-1;
        while(i < j){
            if(s[i] != s[j]){
                i++; 
                j--;
            }
            else{
                break;
            }
        }
        cout<<j - i + 1<<endl;
    }
}