// Leetcode 3093
#include<bits/stdc++.h>
using namespace std;
// Solution 1 - MLE due to unordered_map
class Solution {
public:
    class Node{
        public:
        char data;
        int idx;
        unordered_map<char, Node*> children;
        Node(char data){
            // We need to know which container word is the best candidate among all words passing through this node.
            // Therefore, every Trie node needs to store the best index.
            // And the root needs the best index too, because when there is no common suffix, the common suffix is "".
            idx = -1;
            this->data = data;
        }
    };
    class Trie{
        public:
        Node* root;
        Trie(){
            root = new Node('\0');
        }
        void insert(string word, int index, vector<string>& wordsContainer){
            int n = word.size();
            Node* curr = root;
            // Best candidate for empty suffix - for root
            if(curr->idx == -1 || wordsContainer[index].size() < wordsContainer[curr->idx].size() || (wordsContainer[index].size() == wordsContainer[curr->idx].size() && index < curr->idx)){
                curr->idx = index;
            }
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
                if(curr->idx == -1 || wordsContainer[index].size() < wordsContainer[curr->idx].size() || (wordsContainer[index].size() == wordsContainer[curr->idx].size() && index < curr->idx)){
                    curr->idx = index;
                }
            }
        }
    };
    void helper(Node* curr, string word, vector<int>& ans, int pos){
        int best = curr->idx;
        while(pos < word.size()){
            char ch = word[pos];
            if(!curr->children.count(ch)){
                break;
            }
            if(curr->children.count(ch)){
                curr = curr->children[ch];
                best = curr->idx;
            }
            pos++;
        }
        ans.push_back(best);
    }
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        vector<int> ans;
        Trie trie;
        int n = wordsQuery.size();
        // If we reverse the strings, the problem changes to finding the longest common prefix.
        vector<string> rev = wordsContainer;
        vector<string> revSearch = wordsQuery;
        for(int i = 0; i<rev.size(); i++){
            reverse(rev[i].begin(), rev[i].end());
        }
        for(int i = 0; i<revSearch.size(); i++){
            reverse(revSearch[i].begin(), revSearch[i].end());
        }
        for(int i = 0; i<rev.size(); i++){
            trie.insert(rev[i], i, wordsContainer);
        }
        for(int i = 0; i<n; i++){
            helper(trie.root, revSearch[i], ans, 0);
        }
        return ans;
    }
};

// Solution 2 - Again MLE
// Every Trie node contains 26 pointers.
class Solution {
public:
    class Node{
        public:
        char data;
        int idx;
        Node* children[26];
        Node(char data){
            // We need to know which container word is the best candidate among all words passing through this node.
            // Therefore, every Trie node needs to store the best index.
            // And the root needs the best index too, because when there is no common suffix, the common suffix is "".
            idx = -1;
            this->data = data;
            for(int i = 0; i<26; i++){
                children[i] = NULL;
            }
        }
    };
    class Trie{
        public:
        Node* root;
        Trie(){
            root = new Node('\0');
        }
        void insert(string word, int index, vector<string>& wordsContainer){
            int n = word.size();
            Node* curr = root;
            // Best candidate for empty suffix - for root
            if(curr->idx == -1 || wordsContainer[index].size() < wordsContainer[curr->idx].size() || (wordsContainer[index].size() == wordsContainer[curr->idx].size() && index < curr->idx)){
                curr->idx = index;
            }
            for(int i = 0; i<n; i++){
                // wordsContainer[i] consists only of lowercase English letters.
                char ch = word[i]-'a';
                if(curr->children[ch] != NULL){
                    curr = curr->children[ch];
                }
                else{
                    Node* child = new Node(ch);
                    curr->children[ch] = child;
                    curr = child;
                }
                if(curr->idx == -1 || wordsContainer[index].size() < wordsContainer[curr->idx].size() || (wordsContainer[index].size() == wordsContainer[curr->idx].size() && index < curr->idx)){
                    curr->idx = index;
                }
            }
        }
    };
    void helper(Node* curr, string word, vector<int>& ans, int pos){
        int best = curr->idx;
        while(pos < word.size()){
            char ch = word[pos]-'a';
            if(curr->children[ch] == NULL){
                break;
            }
            if(curr->children[ch] != NULL){
                curr = curr->children[ch];
                best = curr->idx;
            }
            pos++;
        }
        ans.push_back(best);
    }
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        vector<int> ans;
        Trie trie;
        int n = wordsQuery.size();
        // If we reverse the strings, the problem changes to finding the longest common prefix.
        vector<string> rev = wordsContainer;
        vector<string> revSearch = wordsQuery;
        for(int i = 0; i<rev.size(); i++){
            reverse(rev[i].begin(), rev[i].end());
        }
        for(int i = 0; i<revSearch.size(); i++){
            reverse(revSearch[i].begin(), revSearch[i].end());
        }
        for(int i = 0; i<rev.size(); i++){
            trie.insert(rev[i], i, wordsContainer);
        }
        for(int i = 0; i<n; i++){
            helper(trie.root, revSearch[i], ans, 0);
        }
        return ans;
    }
};

// Solution 3
// Instead of dynamically allocating every node with: new Node(). Store all nodes in one: vector<Node>
// This is much more memory efficient.
class Solution {
public:
    class Node{
        public:
        int idx;
        int children[26];
        Node(){
            // We need to know which container word is the best candidate among all words passing through this node.
            // Therefore, every Trie node needs to store the best index.
            // And the root needs the best index too, because when there is no common suffix, the common suffix is "".
            idx = -1;
            for(int i = 0; i<26; i++){
                children[i] = -1;
            }
        }
    };
    vector<Node> trie;
    void insert(string word, int index, vector<string>& wordsContainer){
        int n = word.size();
        int curr = 0; // root
        // Best candidate for empty suffix - for root
        if(trie[curr].idx == -1 || wordsContainer[index].size() < wordsContainer[trie[curr].idx].size() || (wordsContainer[index].size() == wordsContainer[trie[curr].idx].size() && index < trie[curr].idx)){
            trie[curr].idx = index;
        }
        for(int i = 0; i<n; i++){
            // wordsContainer[i] consists only of lowercase English letters.
            char ch = word[i]-'a';
            if(trie[curr].children[ch] != -1){
                curr = trie[curr].children[ch];
            }
            else{ // trie[curr].children[c] == -1
                trie[curr].children[ch] = trie.size();
                // trie.size() is size of vector trie so next index is trie.size()
                // The next node we create will be at next index.
                trie.push_back(Node());
                curr = trie[curr].children[ch];
            }
            if(trie[curr].idx == -1 || wordsContainer[index].size() < wordsContainer[trie[curr].idx].size() || (wordsContainer[index].size() == wordsContainer[trie[curr].idx].size() && index < trie[curr].idx)){
                trie[curr].idx = index;
            }
        }
    }
    void helper(string word, vector<int>& ans, int pos){
        int curr = 0; // root
        // If no common suffix exists root contains the best overall candidate
        int best = trie[curr].idx;
        while(pos < word.size()){
            char ch = word[pos]-'a';
            // // No further common prefix
            if(trie[curr].children[ch] == -1){
                break;
            }
            if(trie[curr].children[ch] != -1){
                curr = trie[curr].children[ch];
                best = trie[curr].idx;
            }
            pos++;
        }
        ans.push_back(best);
    }
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        vector<int> ans;
        // Maximum possible number of nodes
        trie.reserve(500001);
        // Root
        trie.push_back(Node());
        int n = wordsQuery.size();
        // If we reverse the strings, the problem changes to finding the longest common prefix.
        vector<string> rev = wordsContainer;
        vector<string> revSearch = wordsQuery;
        for(int i = 0; i<rev.size(); i++){
            reverse(rev[i].begin(), rev[i].end());
        }
        for(int i = 0; i<revSearch.size(); i++){
            reverse(revSearch[i].begin(), revSearch[i].end());
        }
        for(int i = 0; i<rev.size(); i++){
            insert(rev[i], i, wordsContainer);
        }
        for(int i = 0; i<n; i++){
            helper(revSearch[i], ans, 0);
        }
        return ans;
    }
};
int main(){
    
    return 0;
}