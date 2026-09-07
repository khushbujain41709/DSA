// Leetcode 269 - Premium
// https://www.geeksforgeeks.org/problems/alien-dictionary/1

// Follow up - when the order is not possible.
// 1) If s2 is a prefix of s1 (e.g., "abcd" and "abc"), this is invalid because a shorter string can't come after a longer one if all characters match
// 2) If there is a cycle in the graph, this is invalid because it means that there is no valid ordering of characters.

// First Way
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    string findOrder(vector<string> &words) {
        int n = words.size();
        unordered_set<char> uniqueChar;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<words[i].size(); j++){
                uniqueChar.insert(words[i][j]);
            }
        }
        int unique = uniqueChar.size();
        vector<vector<int>> adjList(26); // imp
        for(int i = 0; i<n-1; i++){
            string s1 = words[i];
            string s2 = words[i+1];
            for(int j = 0; j<min(s1.size(), s2.size()); j++){
                if(s1[j] != s2[j]){
                    int u = s1[j] - 'a';
                    int v = s2[j] - 'a';
                    adjList[u].push_back(v);
                    break;
                }
            }
        }
        string topo = "";
        vector<int> indegree(26, 0);
        for(int i = 0; i<26; i++){
            for(auto x: adjList[i]){
                indegree[x]++;
            }
        }
        queue<int> q;
        for(int i = 0; i<26; i++){
            if(indegree[i] == 0 && uniqueChar.count(i + 'a')){ // imp i+'a' because we are storing the character in the set and not the index
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo += (char)(node + 'a');
            for(auto x: adjList[node]){
                indegree[x]--;
                if(indegree[x] == 0){
                    q.push(x);
                }
            }
        }
        if(topo.size() == unique){
            return topo;
        }
        else return "";
    }
};

// Second way
class Solution {
  public:
    string findOrder(vector<string> &words) {
        int n = words.size();
        unordered_set<char> uniqueChar;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<words[i].size(); j++){
                uniqueChar.insert(words[i][j]);
            }
        }
        int unique = uniqueChar.size();
        vector<vector<char>> adjList(26);
        for(int i = 0; i<n-1; i++){
            string s1 = words[i];
            string s2 = words[i+1];
            for(int j = 0; j<min(s1.size(), s2.size()); j++){
                if(s1[j] != s2[j]){
                    char u = s1[j];
                    char v = s2[j];
                    adjList[u-'a'].push_back(v);
                    break;
                }
            }
        }
        string topo = "";
        vector<int> indegree(26, 0);
        for(int i = 0; i<26; i++){
            for(auto x: adjList[i]){
                indegree[x-'a']++;
            }
        }
        queue<char> q;
        for(int i = 0; i<26; i++){
            if(indegree[i] == 0 && uniqueChar.count(i + 'a')){
                q.push(i+'a');
            }
        }
        while(!q.empty()){
            char node = q.front();
            q.pop();
            topo += (char)(node);
            for(auto x: adjList[node - 'a']){
                indegree[x-'a']--;
                if(indegree[x-'a'] == 0){
                    q.push(x);
                }
            }
        }
        if(topo.size() == unique){
            return topo;
        }
        else return "";
    }
};
int main(){
    
    return 0;
}