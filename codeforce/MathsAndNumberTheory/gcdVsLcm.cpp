#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
My First Approach : This is also correct! YEAH!!!
// Edge case 4, 5, 7
// For odd -> GCD = (2,x) : (2,1) = LCM
// For even -> GCD = (2,x) : (2,2) = LCM
// and x is remaining sum
if(n == 4){
    cout<<1<<" "<<1<<" "<<1<<" "<<1<<" "<<endl;
}
else if(n == 5){
    cout<<2<<" "<<1<<" "<<1<<" "<<1<<" "<<endl;
}
else if(n == 6){
    cout<<3<<" "<<1<<" "<<1<<" "<<1<<" "<<endl;
}
else if(n == 7){
    cout<<2<<" "<<3<<" "<<1<<" "<<1<<" "<<endl;
}
else{
    if(n % 2 != 0){
        int rem = n - (2+2+1);
        cout<<2<<" "<<rem<<" "<<2<<" "<<1<<" "<<endl;
    }
    else{
        int rem = n - (2+2+2);
        cout<<2<<" "<<rem<<" "<<2<<" "<<2<<" "<<endl;
    }
}
*/
int main(){
    int t;
    cin>>t;
    vector<int> khubu;
    unordered_map<int, int> mp;
    unordered_set<int> khushbu;
    while(t--){
        int n;
        cin>>n;
        int a = 0, b = 0, c = 0, d = 0;
        cout<<1<<" "<<n-3<<" "<<1<<" "<<1<<" "<<endl;
    }
}