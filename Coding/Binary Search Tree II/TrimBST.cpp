// Leetcode 669
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
void trim(TreeNode* root, int lo, int hi){
    if(root == NULL) return;
    while(root->left != NULL){
        if(root->left->val < lo){ 
            // root k left ki value lo se kam hai toh uske pure subtree ki value lo se kam hogi
            // to hum root->left mei root->left->right attach kr denge
            // ye bhi shyd kam ho lo se toh while loop use krenge baar baar check krne k liye
            root->left = root->left->right;
        }
        else if(root->left->val > hi){
            // root k left ki value ho se jyada hai toh uske pure subtree ki value hi se jyada hogi
            root->left = root->left->left;
            // again hum check krenge using while loop
        }
        else break;
    }
    while(root->right != NULL){
        if(root->right->val > hi){ 
            // root k right ki value hi se jyada hai toh uske pure subtree ki value hi se jyada hogi
            // to hum root->right mei root->right->left attach kr denge
            // ye bhi shyd jyada ho hi se toh while loop use krenge baar baar check krne k liye
            root->right = root->right->left;
        }
        else if(root->right->val < lo){
            // root k right ki value lo se kam hai toh uske pure subtree ki value lo se kam hogi
            root->right = root->right->right;
            // again hum check krenge using while loop
        }
        else break;
    }
    // check this for all nodes
    trim(root->left, lo, hi);
    trim(root->right, lo, hi);
}
TreeNode* trimBST(TreeNode* root, int low, int high){
    if(root == NULL) return root;
    // since we won't check root so we will create a dummy node and pass it as root 
    // we will check whole tree because we will attach it as dummy's left subtree
    TreeNode* dummy = new TreeNode(INT_MAX);
    dummy->left = root; // dummy->right = NULL by default
    trim(dummy, low, high);
    return dummy->left;
}
int main(){

}