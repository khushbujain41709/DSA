// Leetcode 1339
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
    long long total = 0;
    long long ans = INT_MIN;
    int MOD = 1000000000+7;
    long long sum(TreeNode* root){
        if(root == NULL) return 0;
        return root->val + sum(root->left) + sum(root->right);
    }
    long long f(TreeNode* root){
        if(root == NULL) return 0;
        long long l = f(root->left); // left = sum of left subtree
        long long r = f(root->right); // right = sum of right subtree
        long long curr = root->val + l + r; // sum of node and its subtree
        ans = max(ans, curr*(total-curr));
        return curr; // Return subtree sum to parent
        //Parent needs it to compute its own curr
    }
    int maxProduct(TreeNode* root) {
        total = sum(root);
        f(root); // no need to store it anywhere
        return ans % MOD;
    }
};
int main(){
    
    return 0;
}