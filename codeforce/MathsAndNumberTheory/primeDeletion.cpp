#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int i3 = 0;
        int i1 = 0;
        for(int i = 0; i<9; i++){
            if(s[i] == '3'){
                i3 = i;
            }
            if(s[i] == '1'){
                i1 = i;
            }
        }
        if(i3 > i1){
            cout<<"13"<<endl;
        }
        else{
            cout<<"31"<<endl;
        }
    }
    return 0;
}