#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// if we use (1<<n) instead of myPow(2,n) - Question will give error
int myPow(double x, int n){
    if(n == 0 && x == 0){
        cout<<"INDETERMINANT"<<endl;
        return INT_MIN;;
    }
    if(n==0){
        return 1;
    }
    if(n == 1){
        return x;
    }
    if(n == -1){
        return 1/x;
    }
    if(n % 2 == 0){
        double ans = myPow(x,n/2);
            return ans*ans;
    }
    else{
        double ans = myPow(x,n/2);
            if(n<0){
                return 1/x*ans*ans;
            }
        return ans*ans*x;
    }
}
int main(){
    vector<int> khubu;
    unordered_map<int, int> mp;
    unordered_set<int> khushbu;
    long long n, m;
    cin>>n>>m;
    if(myPow(2,n) > m){
        cout<<m<<endl;
    }
    else cout<<m % myPow(2,n)<<endl;
}