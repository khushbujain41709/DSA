// Leetcode 67
#include<iostream>
#include<algorithm>
using namespace std;
// Method 1 - Giving TLE
int binary_to_decimal(string& binary){
    int n = binary.size();
    int result = 0;
    for(int i = n-1;i>=0;i--){
        char ch = binary[i]; // last character
        int num = ch - '0'; // string to number conversion, substracting ascii of ch with ascii of 0 and ascii of 1 with ascii of 1.
        result += num*(1<<(n-i-1)); // first index like 1<<0 is 1 ans 1<<1 is 10 that is 2 so on.
    }
    return result;
}
string dec_to_bin(int& decimal){
    string result = "";
    while(decimal > 0){
        if(decimal % 2 == 0){
            result += "0";
        }
        else{
            result += "1";
        }
        decimal = decimal/2;
    }
    reverse(result.begin() , result.end());
    return result;
}
string addBinary(string a, string b) {
    int decimal_x = binary_to_decimal(a);
    int decimal_y = binary_to_decimal(b);
    int sum = decimal_x + decimal_y;
    if(sum == 0) return "0";
    return dec_to_bin(sum);
}

// Method 2
string addBinary(string a, string b) {
    int i = a.size()-1;
    int j = b.size()-1;
    int carry = 0;
    int sum = 0;
    string ans = "";
    while(i >= 0 || j >= 0 || carry){
        sum = carry;
        if(i >= 0){
            sum += a[i] - '0';
            i--;
        }
        if(j >=0 ){
            sum += b[j] - '0';
            j--;
        }
        ans += to_string(sum % 2);
        carry = sum/2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main(){
    
    return 0;
}