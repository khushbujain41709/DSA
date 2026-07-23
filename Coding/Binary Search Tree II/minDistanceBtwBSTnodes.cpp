// Leetcode 783 same as leetcode 530(no change)
#include<iostream>
#include<climits>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data){
        val = data;
        left = NULL;
        right = NULL;
    }
};
class Solution {
public:
    int ans = INT_MAX;
    int prev = -1;
    // inorder travsersal is important to sort the BST in ascending order
    void inorder(TreeNode* root){
        if(root == NULL){
            return;
        }
        inorder(root->left);
        if(prev != -1){
            ans = min(ans, root->val-prev);
        }
        prev = root->val;
        inorder(root->right);
    }
    int minDiffInBST(TreeNode* root){
        inorder(root);
        return ans;
    }
};
int main(){
    
    return 0;
}