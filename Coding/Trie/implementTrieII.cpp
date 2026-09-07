// Leetcode 1804 - Premium
// https://www.naukri.com/code360/problems/implement-trie_1387095?leftPanelTabValue=SUBMISSION
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    char data;
    bool terminal;
    unordered_map<char, Node*> children;
    int countWordsStarting;
    int countWordsEnding;
    Node(char data){
        this->data = data;
        this->terminal = false;
        this->countWordsEnding = 0;
        this->countWordsStarting = 0;
    }
    void makeTerminal(){
        this->terminal = true;
    }
    bool isTerminal(){
        return this->terminal == true;
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
                curr->countWordsStarting++;
            }
            else{
                Node* child = new Node(ch);
                curr->children[ch] = child; // make a new character
                curr = child; // move to next character
                curr->countWordsStarting++;
            }
        }
        curr->makeTerminal();
        curr->countWordsEnding++;
    }
    int countWordsEqualTo(string word) {
        Node* curr = root;
        for(int i = 0; i<word.size(); i++){
            char ch = word[i];
            if(curr->children.count(ch)){
                curr = curr->children[ch]; // move to next character
            }
            else{
                return 0;
            }
        }
        return curr->countWordsEnding;
    }
    int countWordsStartingWith(string word) {
        Node* curr = root;
        for(int i = 0; i<word.size(); i++){
            char ch = word[i];
            if(curr->children.count(ch)){
                curr = curr->children[ch]; // move to next character
            }
            else{
                return 0;
            }
        }
        return curr->countWordsStarting;
    }
    void erase(string word) {
        Node* curr = root;
        for(int i = 0; i<word.size(); i++){
            char ch = word[i];
            if(!curr->children.count(ch)) return; // word doesn't exist
            if(curr->children.count(ch)){
                curr = curr->children[ch]; // move to next character
                curr->countWordsStarting--;
            }
        }
        curr->countWordsEnding--;
    }
};