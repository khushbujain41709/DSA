// Leetcode 3228
#include<iostream>
using namespace std;
// Method 1 - gives TLE
int countOnesBefore(int index, string& s){
    int n = s.size();
    int count = 0;
    for(int i = index-1; i>=0 ; i--){
        if(s[i] == '1'){
            count++;
        }
    }
    return count;
}
int maxOperations(string s) {
    int n = s.size();
    int count = 0;
    for(int i = 0; i<n; i++){
        if(s[i] == '0' && i == n-1){
            count += countOnesBefore(i, s);
        }
        else if((s[i] == '0' && s[i+1] == '0') || s[i] == '1'){
            continue;
        }
        else{
            count += countOnesBefore(i, s);
        }
    }
    return count;
}
// Method 2
int maxOperations(string s) {
    int n = s.size();
    int count = 0;
    int ones = 0;
    for(int i = 0; i<n-1; i++){
        if(s[i] == '1'){
            // keeping track of ones
            ones++;
        }
        else if(s[i] == '0' && s[i+1] == '1'){
            count += ones;
        }
    }
    if(s[n-1] == '0'){ // case - 110
        count += ones;
    }
    return count;
}
int main(){
    
    return 0;
}