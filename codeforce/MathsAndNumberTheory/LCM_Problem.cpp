#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// Minimum possible value: The LCM is always at least as large as the greater of the two numbers, (max (x,y). For example, the LCM of 6 and 12 is 12.
// Maximum possible value: The LCM is at most the product of the two numbers, (x times y). This maximum occurs when (x) and (y) are coprime (have no common factors other than 1), such as the LCM of 3 and 4 which is 12 (3 times 4). 
int main(){
    int t;
    cin>>t;
    vector<int> khubu;
    unordered_map<int, int> mp;
    unordered_set<int> khushbu;
    while(t--){
        int l,r;
        cin>>l>>r;
        int x = 0;
        int y = 0;
        if(r < 2*l){
            cout<<-1<<" "<<-1<<endl;
        }
        else{
            x = l;
            y = 2*l;
            cout<<x<<" "<<y<<endl;
        }
    }
}