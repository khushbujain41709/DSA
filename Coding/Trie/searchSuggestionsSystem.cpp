// Leetcode 1268
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    class Node{
        public:
        char data;
        unordered_map<char, Node*> children;
        vector<string> suggestions;
        Node(char data){
            this->data = data;
        }
    };
    class Trie {
    public:
        Node* root;
        Trie() {
            root = new Node('\0');
        }
        void insert(string word) {
            Node* curr = root;
            for(int i = 0; i<word.size(); i++){
                char ch = word[i];
                if(curr->children.count(ch)){
                    curr = curr->children[ch]; // move to next character
                }
                else{
                    Node* child = new Node(ch);
                    curr->children[ch] = child; // make a new character
                    curr = child; // move to next character
                }
                // We add it after moving to the character node.
                // Because our search starts after the first character.
                // We don't need suggestions for the empty prefix "".
                // So root doesn't need the vector.
                // Ex: word is mouse for for m we have mouse in suggestion for mo that is o character we have mouse in suggestion, for mou that is charcter u we have mouse in suggestion character. 
                if(curr->suggestions.size() < 3){
                    curr->suggestions.push_back(word);
                }
            }
        }
    };
    void search(vector<string>& v, string s, Node* root) {
        Node* curr = root;
        int n = s.size();
        for(int i = 0; i<n; i++){
            char ch = s[i];
            if(!curr->children.count(ch)){ // no matching prefix
                return;
            }
            if(curr->children.count(ch)){
                curr = curr->children[ch];
            }
        }
        v = curr->suggestions;
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        Trie trie;
        // sort for getting lexicographically sorted product
        sort(products.begin(), products.end());
        for(int i = 0; i<products.size(); i++){
            trie.insert(products[i]);
        }
        string s = "";
        for(int i = 0; i<searchWord.size(); i++){
            s += searchWord[i];
            vector<string> v;
            search(v, s, trie.root);
            ans.push_back(v);
        }
        return ans;
    }
};
int main(){
    
    return 0;
}