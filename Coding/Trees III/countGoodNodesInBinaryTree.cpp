// Leetcode 1448
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
    void dfs(TreeNode* root, int& count, int maxx){
        // Dry Run - [2,null,4,10,8,null,null,4]
        // pass maxx by value
        // The call to the right child later will also receive maxx = 4.
        // This is because maxx is passed by value.
        if(root == NULL) return;
        if(root->val >= maxx){
            maxx = root->val;
            count++;
        }
        dfs(root->left, count, maxx);
        dfs(root->right, count, maxx); // same maxx is passed in RHS
    }
    int goodNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int count = 0;
        dfs(root, count, root->val);
        return count;
    }
};
int main(){
    
    return 0;
}