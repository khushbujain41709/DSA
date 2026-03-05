#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n == 2){
            cout<<7<<endl;
        }
        else{ // except 2 all prime numbers are odd
            // odd + odd give non prime always
            cout<<3<<endl;
        }
    }
    return 0;
}