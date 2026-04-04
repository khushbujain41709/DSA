// Leetcode 337
// The problem is a classic "Maximum Weight Independent Set" on a tree.
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
    unordered_map<TreeNode*, vector<int>> dp;
    int helper(TreeNode* root, int isRob){
        if(root == NULL){
            return 0;
        }
        if(!dp.count(root)){
            // dp[root] = vector<int>(2, -1);
            dp[root].resize(2,-1);
        }
        if(dp[root][isRob] != -1){
            return dp[root][isRob];
        }
        // skip
        int skip = helper(root->left, 1) + helper(root->right, 1);

        // take
        int take = 0;
        if(isRob == 1){
            take = root->val + helper(root->left, 0) + helper(root->right, 0);
        }
        return dp[root][isRob] = max(skip, take);
    }
    int rob(TreeNode* root){
        return helper(root, 1); 
        // 1 means we can rob and 0 means we can't rob
    }
};
int main(){
    
    return 0;
}