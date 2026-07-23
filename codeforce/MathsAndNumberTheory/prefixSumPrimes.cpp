#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    vector<int> ans;
    int two = 0;
    int one = 0;
    for(int i = 0; i<n; i++){
        if(a[i] == 2){
            two++;
        }
        else one++;
    }
    if(two != 0){
        ans.push_back(2);
        two--;
    }
    if(one != 0){
        ans.push_back(1);
        one--;
    }
    while(two > 0){
        ans.push_back(2);
        two--;
    }
    while(one > 0){
        ans.push_back(1);
        one--;
    }
    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}