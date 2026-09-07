// Leetcode 1927
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // So 2 question marks on the same side can contribute exactly 9 in total, because:
    // Alice chooses x
    // Bob responds with 9 - x
    // -----------------------
    // Total = 9

    // To keep the signs consistent.
    // We define:
    // D=L−R
    // So positive D means:
    // Left side currently has a larger sum.
    // Now, if the right side has more ?, i.e.
    // qR−qL>0
    // then the right side has more ability to catch up.

    // 2 * (L - R) == 9 * (qR - qL)
    // If this is true → Bob wins.
    // Otherwise → Alice wins.
    bool sumGame(string num) {
        int n = num.size();
        int L = 0, R = 0, qL = 0, qR = 0;
        for(int i = 0; i<n/2; i++){
            if(num[i] == '?'){
                qL++;
            }
            else L += num[i] - '0';
        }
        for(int i = n/2; i<n; i++){
            if(num[i] == '?'){
                qR++;
            }
            else R += num[i] - '0';
        }
        if(qR == 0 && qL == 0 && (L == R)){
            return false;
        }
        if(qR == 0 && qL == 0 && (L != R)){
            return true;
        }
        if(abs(qR- qL) % 2 == 1){
            return true;
        }
        else if(abs(qR- qL) % 2 == 0){
            return 2*(L-R) != 9*(qR - qL);
        }
        return true; // dummy return
    }
};
int main(){
    
    return 0;
}