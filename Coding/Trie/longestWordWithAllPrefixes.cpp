// Leetcode 1858 - Premium
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    char data;
    bool terminal;
    unordered_map<char, node*> children;
    node(char data){
        this->data = data;
        this->terminal = false;
    }
    void makeTerminal(){
        this->terminal = true;
    }
    bool isTerminal(){
        return this->terminal == true;
    }
};
class Trie{
    public:
    node* head;
    Trie() {
        head = new node('\0');
    }
};
void insert(node* head, string word){
    node* curr = head;
    for(int i = 0; i<word.size(); i++){
        if(curr->children.count(word[i])){
            curr = curr->children[word[i]];
        }
        else{
            node* child = new node(word[i]);
            curr->children[word[i]] = child;
            curr = child;
        }
    }
    curr->makeTerminal();
}
bool search(node* head, string word, string& maxx){
    node* curr = head;
    string s = "";
    for(int i = 0; i<word.size(); i++){
        curr = curr->children[word[i]];
        if(curr->isTerminal()){
            s += word[i];
            maxx = s;
        }
        else{
            return false;
        }
    }
    return true;
}
string completeString(vector<string>& nums){
    node* head = new node('\0');
    int n = nums.size();
    for(int i = 0; i<n; i++){
        insert(head, nums[i]);
    }
    string maxLen = "";
    for(int i = 0; i<n; i++){
        string maxx = "";
        if(search(head, nums[i], maxx)){
            if(maxx.size() == maxLen.size()){
                maxLen = min(maxx, maxLen); // lexographically small
            }
            else maxLen = max(maxx, maxLen);
        }
    }
    return maxLen;
}
int main(){
    return 0;
}