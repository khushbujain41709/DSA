// Leetcode 394
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        stack<char> st;
        stack<char> digit;
        for(int i = 0; i<n; i++){
            if(s[i] >= '0' && s[i] <= '9') digit.push(s[i]);
            if(s[i] == ']'){
                string str = "";
                while(!st.empty() && st.top() != '['){
                    str += st.top();
                    st.pop();
                }
                st.pop(); // pop '['
                reverse(str.begin(), str.end());
                int digi = 0;
                string num = "";
                while(!st.empty() && !digit.empty() && st.top() == digit.top()){
                    num += st.top();
                    st.pop();
                    digit.pop();
                }
                reverse(num.begin(), num.end());
                digi = stoi(num);
                for(int k = 0; k<digi; k++){
                    for(int j = 0; j<str.size(); j++){
                        st.push(str[j]);
                    }
                }
            }
            else st.push(s[i]);
        }
        string result = "";
        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
int main(){
    
    return 0;
}