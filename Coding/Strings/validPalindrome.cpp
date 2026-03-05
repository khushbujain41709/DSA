// Leetcode 125
#include<iostream>
using namespace std;
bool checkPalindrome(string s){
    int i = 0; 
    int j = s.size() - 1;
    while(i<j){
        if(s[i] != s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
bool isPalindrome(string s) {
    int n = s.size();
    string newS = "";
    for(int i = 0; i<n; i++){
        if(isalnum(s[i])){ // checking alpha numeric
            // tolower() returns an int value there for typecasting
            newS += tolower(s[i]);
        }
    }
    return checkPalindrome(newS);
}
int main(){
    
    return 0;
}