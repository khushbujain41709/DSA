// Leetcode 768
#include<iostream>
#include<stack>
using namespace std;
bool checkValidString(string s) {
    stack<int> star, open;
    // open stores indices of '('
    // star stores indices of '*'
    int n = s.size();
    for(int i = 0; i<n; i++){
        if(s[i] == '('){
            open.push(i);
        }
        else if(s[i] == '*'){
            star.push(i);
        }
        else{ // s[i] == ')'
        // empty open first then star as rem '*' can be considered as empty string
            if(!open.empty()){
                open.pop();
            }
            // else if is emp as open char at a time can cancel out ')'
            else if(!star.empty()){
                star.pop();
            }
            else{
                return false;
            }
        }
    }
    // here we use remaining * as ')'
    while(!open.empty() && ! star.empty()){ 
        // && bcoz what if star is empty but open is not empty
        if(open.top() > star.top()) return false; // ')' comes before '(' so false
        open.pop();
        star.pop();
    }
    return open.empty(); 
    // we need to empty open as no '(' should remain as rem '*' can be considered as empty string
}
int main(){
    
    return 0;
}