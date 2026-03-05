#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    vector<int> khubu;
    unordered_map<int, int> m;
    unordered_set<int> khushbu;
    while(t --){
        long long a, b, c;
        cin>>a>>b>>c;
        if(c % 2 != 0){ // Katie will play after pressing all c buttons when c is odd
            if(b > a){
                cout<<"Second"<<endl; // Katie will win
            }
            else{ // when b <= a
                cout<<"First"<<endl; // Anna will win
            }
        }
        else{ // Anna will play after pressing all c buttons when c is even
            if(b >= a){
                cout<<"Second"<<endl; // Katie will win
            }
            else{ // when b < a
                cout<<"First"<<endl; // Anna will win
            }
        }
    }
}