// Leetcode 2075
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int column = -1;
        int n = encodedText.size();
        column = n/rows;
        int k = 0;
        vector<vector<char>> mat(rows, vector<char> (column, ' '));
        for(int i = 0; i<rows; i++){
            for(int j = 0; j<column; j++){
                mat[i][j] = encodedText[k];
                k++;
            }
        }
        string originalText = "";
        for(int i = 0; i<column; i++){
            int r = 0, c = i;
            while(r<rows && c<column){
                originalText += mat[r][c];
                r++;
                c++;
            }
        }
        int i = originalText.size() - 1;
        while(i >= 0){
            if(originalText[i] == ' '){
                originalText.pop_back();
            }
            else break;
            i--;
        }
        return originalText;
    }
};
int main(){
    
    return 0;
}