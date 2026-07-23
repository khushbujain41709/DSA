// Leetcode 111
#include<iostream>
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
int helper(TreeNode* root){
    if(root == NULL) return 0;
    int l = helper(root->left);
    int r = helper(root->right);
    if(l == 0 || r == 0){
        return 1 + max(l,r); // imp - no call
    }
    /*
    // avoiding extra calls using max function
    if(l == NULL){
        return 1 + minDepth(root->right);
    }
    int r = minDepth(root->right);
    if(r == NULL){
        return 1 + minDepth(root->left);
    }
    */
    return 1 + min(l,r);
}
int minDepth(TreeNode* root) {
    return helper(root);
}
int main(){
    
    return 0;
}