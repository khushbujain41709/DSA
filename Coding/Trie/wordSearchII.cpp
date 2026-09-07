// Leetcode 212
#include<bits/stdc++.h>
using namespace std;
// Solution 1 - TLE
class Solution {
public:
    bool helper(int idx, int jdx, vector<vector<char>>& board, string word, set<pair<int, int>>& vis, int k){
        if(k == word.size()){
            return true;
        }
        int m = board.size();
        int n = board[0].size();
        int dx[] = {+1, -1, 0, 0};
        int dy[] = {0, 0, -1, +1};
        for(int i = 0; i<4; i++){
            int nr = idx+dx[i];
            int nc = jdx+dy[i];
            if(nr >= 0 && nr < m && nc >= 0 && nc < n && board[nr][nc] == word[k] && !vis.count({nr,nc})){
                vis.insert({nr, nc});
                k++; // k == n as k++ at the end.
                if(helper(nr, nc, board, word, vis, k)) return true;
                k--;
                vis.erase({nr,nc});
            }
        }
        return false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        int n = board[0].size();
        unordered_set<string> ans;
        for(int x = 0; x<words.size(); x++){
            char start = words[x][0];
            for(int i = 0; i<m; i++){
                for(int j = 0; j<n; j++){
                    if(board[i][j] == start){
                        set<pair<int, int>> vis;
                        vis.insert({i,j});
                        int k = 1; // word index and start is already index 0 so k = 1
                        if(helper(i, j, board, words[x], vis, k) == true){
                            ans.insert(words[x]);
                        }
                    }
                }
            }
        }
        vector<string> v;
        for(auto x: ans){
            v.push_back(x);
        }
        return v;
    }
};

// Solution 2
class Solution {
public:
    class Node{
        public:
        char data;
        unordered_map<char, Node*> children;
        string word;
        Node(char data){
            this->data = data;
            this->word = "";
        }
    };
    class Trie{
        public:
        Node* root;
        Trie(){
            root = new Node('\0');
        }
        void insert(string word){
            int n = word.size();
            Node* curr = root;
            for(int i = 0; i<n; i++){
                char ch = word[i];
                if(curr->children.count(ch)){
                    curr = curr->children[ch];
                }
                else{
                    Node* child = new Node(ch);
                    curr->children[ch] = child;
                    curr = child;
                }
            }
            curr->word = word;
        }
    };
    void helper(int idx, int jdx, vector<vector<char>>& board, Node* curr, vector<string>& ans){
        int m = board.size();
        int n = board[0].size();
        char ch = board[idx][jdx];
        // Current path is not a prefix of any word
        if(!curr->children.count(ch)){
            return;
        }
        // Order must be maintained as initially current is root.
        // 1)
        curr = curr->children[ch]; // move to next character in Trie.
        // 2)
        // Found a complete word
        if(curr->word != ""){
            ans.push_back(curr->word);
            // Prevent duplicate answer
            curr->word = "";
        }
        board[idx][jdx] = '#';
        int dx[] = {+1, -1, 0, 0};
        int dy[] = {0, 0, -1, +1};
        for(int i = 0; i<4; i++){
            int nr = idx+dx[i];
            int nc = jdx+dy[i];
            if(nr >= 0 && nr < m && nc >= 0 && nc < n && board[nr][nc] != '#'){
                helper(nr, nc, board, curr, ans);
            }
        }
        // imp - backtrack
        board[idx][jdx] = ch;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        int n = board[0].size();
        Trie trie;
        for(int i = 0; i<words.size(); i++){
            trie.insert(words[i]);
        }
        vector<string> ans;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                helper(i, j, board, trie.root, ans);
            }
        }
        return ans;
    }
};
int main(){
    
    return 0;
}