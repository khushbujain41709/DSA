// Leetcode 126
#include <bits/stdc++.h>
using namespace std;
// Method 1 - MLE on Leetcode but accepted on GFG
// Dry Run on beginWord = bat, endWord = coz
// WordList = [pat, bot, cot, poz, coz]
// ans = [["bat", "bot", "pot", "poz", "coz"], ["bat", "pat", "pot", "poz", "coz"]]
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        unordered_set<string> s(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        q.push({beginWord}); // first step of sequence is beginWord
        unordered_set<string> usedOnLevel;
        int level = 0;
        // TC = wordList.size()*26*beginWord.size()* log(wordList.size()) and wordList.size() is the number of words in the queue and log(wordList.size()) for set operations.
        while(!q.empty()){
            vector<string> vec = q.front();
            q.pop();
            if(vec.size() > level){
                level++;
                // why for loop here
                // what usedOn Level is storing - It stores all the words that were used/generated in the current BFS level.
                // Process Level 1
                //     ↓
                // Remember all generated words in usedOnLevel
                //     ↓
                // Move to Level 2
                //     ↓
                // Erase all Level 1 generated words from set
                //     ↓
                // Process Level 2
                for(auto x: usedOnLevel){
                    s.erase(x);
                }
                usedOnLevel.clear();
            }
            // store the answers
            if(!ans.empty() && vec.size() > ans[0].size()){
                return ans;
            }
            if(vec.back() == endWord){
                if(ans.size() == 0){
                    ans.push_back(vec);
                }
                else{
                    if(vec.size() == ans[0].size()){
                        ans.push_back(vec);
                    }
                }
                continue;
            }
            string word = vec.back();
            for(int i = 0; i<word.size(); i++){
                for(int j = 0; j<26; j++){
                    string neww = word;
                    neww[i] = 'a'+j;
                    if(s.count(neww)){
                        vec.push_back(neww);
                        q.push(vec);
                        usedOnLevel.insert(neww);
                        vec.pop_back();
                    }
                }
            }
        }
        return ans;
    }
};

// Method 2
class Solution {
public:
    void dfs(vector<vector<string>>& ans, vector<string> v, unordered_map<string, int>& m, string beginWord, string word){
        v.push_back(word);
        if(word == beginWord){
            reverse(v.begin(), v.end());
            ans.push_back(v);
            reverse(v.begin(), v.end()); // This is done to maintain the original order of the vector v for further processing in the DFS. After adding the current path to ans, we reverse v back to its original order so that it can be used correctly in subsequent recursive calls. If we didn't reverse it back, the next recursive call would have an incorrect order of words, leading to incorrect paths being generated.
            return;
        }
        for(int i = 0; i<word.size(); i++){
            for(int j = 0; j<26; j++){
                string neww = word;
                neww[i] = 'a'+j;
                if(m.count(neww) && m[neww] == m[word] - 1){
                    dfs(ans, v, m, beginWord, neww);
                }
            }
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        unordered_set<string> s(wordList.begin(), wordList.end());
        unordered_map<string, int> m;
        m[beginWord] = 1;
        queue<string> q;
        q.push(beginWord);
        if(s.count(beginWord)) s.erase(beginWord);
        while(!q.empty()){
            string word = q.front();
            int steps = m[word];
            q.pop();
            if(word == endWord){
                break;
            }
            for(int i = 0; i<word.size(); i++){
                for(int j = 0; j<26; j++){
                    string neww = word;
                    neww[i] = 'a'+j;
                    if(s.count(neww)){
                        m[neww] = steps+1;
                        q.push(neww);
                        s.erase(neww); // This is important to avoid cycles and unnecessary processing of the same word again
                        // Same as visited array in normal BFS
                    }
                }
            }
        }
        // queue is created
        // Now we are backtracking in a map from end to start for optimization.
        // This is because we are storing the steps in the map and we can easily find the path from endWord to beginWord by checking the steps.
        unordered_set<string> st(wordList.begin(), wordList.end());
        dfs(ans, {}, m, beginWord, endWord);
        return ans;
    }
};
int main(){

}