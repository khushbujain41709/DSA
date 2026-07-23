// Leetcode 538 and Leetcode 1038
#include<iostream>
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
void inorderRev(TreeNode* root, int& sum){
    if(root == NULL) return;
    inorderRev(root->right, sum);
    root->val += sum;
    sum = root->val;
    inorderRev(root->left, sum);
}
TreeNode* convertBST(TreeNode* root){
    if(root == NULL) return root;
    int sum = 0;
    inorderRev(root, sum);
    return root;
}
int main(){
    
    return 0;
}