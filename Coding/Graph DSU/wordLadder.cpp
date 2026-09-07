// Leetcode 127
// See image attached in the same folder for better understanding of the problem
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1}); // first step of sequence is beginWord
        if(s.count(beginWord)){ // This is important to avoid cycles and unnecessary processing of the same word again
            s.erase(beginWord);
        }
        // TC = wordList.size()*26*beginWord.size()* log(wordList.size()) and wordList.size() is the number of words in the queue and log(wordList.size()) for set operations.
        while(!q.empty()){
            string word = q.front().first;
            int step = q.front().second;
            q.pop();
            if(word == endWord){
                return step;
            }
            for(int i = 0; i<word.size(); i++){
                for(int j = 0; j<26; j++){
                    string neww = word;
                    neww[i] = 'a'+j;
                    if(s.count(neww)){
                        q.push({neww, step+1});
                        s.erase(neww); // This is important to avoid cycles and unnecessary processing of the same word again
                        // Same as visited array in normal BFS
                    }
                }
            }
        }
        return 0;
    }
};
int main(){
    
}