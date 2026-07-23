// Leetcode 680
#include<iostream>
using namespace std;
class Solution {
public:
    // Method 1 - Giving MLE
    // bool isPalindrome(string s){
    //     int i = 0; 
    //     int j = s.size() - 1;
    //     while(i<j){
    //         if(s[i] != s[j]){
    //             return false;
    //         }
    //         i++;
    //         j--;
    //     }
    //     return true;
    // }
    // bool validPalindrome(string s){
    //     int n = s.size();
    //     if(isPalindrome(s)) return true;
    //     string left = "";
    //     string right = "";
    //     string newS = "";
    //     for(int i = 0; i<n; i++){
    //         left = s.substr(0, i);
    //         right = s.substr(i+1);
    //         newS = left+right;
    //         if(isPalindrome(newS)){
    //             return true;
    //         }
    //     }
    //     return false;
    // }

    // Method 2
    bool isPalindrome(string s, int i , int j){
        while(i<j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s){
        int n = s.size();
        if(isPalindrome(s, 0, n-1)) return true;
        int i = 0; 
        int j = s.size() - 1;
        while(i<j){
            if(s[i] != s[j]){
                return isPalindrome(s,i, j-1) || isPalindrome(s, i+1, j);
            }
            i++;
            j--;
        }
        return false;
    }
};
int main(){
    
    return 0;
}