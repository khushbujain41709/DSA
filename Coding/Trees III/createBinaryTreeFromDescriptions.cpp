// Leetcode 2196
#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public :
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
class Solution {
public:
    // IMP : For this problem, duplicate values cannot occur.
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n = descriptions.size();
        unordered_set<int> sp, sc;
        for(int i = 0; i<n; i++){
            sp.insert(descriptions[i][0]);
            sc.insert(descriptions[i][1]);
        }
        int rootVal = 0;
        for(auto x: sp){
            if(!sc.count(x)){
                rootVal = x;
                break;
            }
        }
        unordered_map<int, TreeNode*> mp;
        for(int i = 0; i<n; i++){
            int parent = descriptions[i][0];
            int child = descriptions[i][1];
            if(!mp.count(parent)){
                mp[parent] = new TreeNode(parent);
            }
            if(!mp.count(child)){
                mp[child] = new TreeNode(child);
            }
        }
        for(int i = 0; i<n; i++){
            int parent = descriptions[i][0];
            int child = descriptions[i][1];
            int leftSide = descriptions[i][2];
            if(leftSide){
                mp[parent]->left = mp[child];
            }
            else{
                mp[parent]->right = mp[child];
            }
        }
        return mp[rootVal];
    }
};
int main(){
    
    return 0;
}