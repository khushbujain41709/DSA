// Leetcode 222
#include<iostream>
using namespace std;
class TreeNode{
    public :
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->value = val;
        this->left = NULL;
        this->right = NULL;
    }
};
// Method 1 - TC = O(n)
int count = 0;
void traverse(TreeNode* root){
    if(root == NULL) return;
    traverse(root->left);
    count++;
    traverse(root->right);
    return;
}
int countNodes(TreeNode* root) {
    traverse(root);
    return count;
}

// Method 2
/*
In a complete binary tree, if the leftmost and rightmost heights are equal, the tree is a perfect binary tree and we can directly calculate the count using the formula (2^h - 1). Otherwise, we recursively count nodes in left and right subtrees. This optimization significantly reduces the time complexity compared to traversing all nodes.
*/
// TC = O(log^2n) and SC = O(log n)
// Step 1: Calculate leftmost height
int leftHeight(TreeNode* root){
    if(root == NULL) return 0;
    return 1 + leftHeight(root->left);
}
// Step 2: Calculate rightmost height
int rightHeight(TreeNode* root){
    if(root == NULL) return 0;
    return 1 + rightHeight(root->right);
}
int countNodes(TreeNode* root) {
    if(root == NULL) return 0;
    int left_height = leftHeight(root);
    int right_height = rightHeight(root);
    if(left_height == right_height){
        return (1<<left_height) - 1;
    }
    else{
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}
int main(){
    
    return 0;
}