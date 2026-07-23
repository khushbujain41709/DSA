// Leetcode 530 same as leetcode 783(no change)
#include<iostream>
#include<climits>
int ans = INT_MAX;
int prevv = -1; // Don't use prev keyword as it is a standard library function
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
// inorder travsersal is important to sort the BST in ascending order
void inorder(TreeNode* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    if(prevv != -1){
        ans = min(ans, root->val-prevv);
    }
    prevv = root->val;
    inorder(root->right);
}
int minDiffInBST(TreeNode* root){
    inorder(root);
    return ans;
}
int main(){
    
    return 0;
}