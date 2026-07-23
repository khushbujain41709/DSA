// Expected TC = O(logn) or O(1)
#include<bits/stdc++.h>
using namespace std;
// Giving TLE
// bool checkOneNonZero(int n){
//     vector<int>v;
//     unordered_set<int> s;
//     unordered_map<int, int> m;
//     int x = n;
//     while(x > 0){
//         int digit = x % 10;
//         v.push_back(digit);
//         s.insert(digit);
//         x = x/10;
//     } 
//     for(int i = 0; i<v.size(); i++){
//         m[v[i]]++;
//     }
//     if(s.size() == 1 && n <= 9) return true;
//     else if(m.size() == 2){
//         bool flag = false;
//         for(auto x : m){
//             if(x.first == 0){ // 110 ?
//                 flag = true;
//             }
//             else{
//                 if(x.second > 1) return false;
//             }
//         }
//         if(flag) return true;
//         else return false;
//     }
//     else return false;
// }
bool check(int n){
    int number_of_zeroes = 0;
    int number_of_digits = 0; // all digits
    int x = n;
    while(x > 0){
        int digit = x % 10;
        if(digit == 0) number_of_zeroes ++;
        number_of_digits++;
        x = x/10;
    } 
    return number_of_zeroes == number_of_digits - 1;
}
int main(){
    int t;
    cin>>t;
    // precomputation
    vector<long long> round_numbers;
    for(int i = 1; i<= 999999; i++){ // O(999999*6) as 999999 has 6 digits
        if(check(i)) round_numbers.push_back(i);
    }
    while(t --){
        long long n;
        cin>>n;
        long long ans = 0;
        for(int i = 0; i<round_numbers.size(); i++){ 
            // round_numbers.size() = 54 so 1 to 999999 has only 54 round numbers
            // traverse in round/_number array
            if(round_numbers[i] <= n){
                ans ++;
            }
            else break; // optimized
        }
        cout<<ans<<endl;
        // TLE
        // int count = 0;
        // for(int i = 1; i<=n ; i++){
        //     if(checkOneNonZero(i)){
        //         count ++;
        //     }
        // }
        // cout<<count<<endl;
    }
}