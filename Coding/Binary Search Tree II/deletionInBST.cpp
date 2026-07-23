// Leetcode 450
// Inorder predecessor and inorder successor can never have 2 children.
// Inorder predecessor can never have a right child.
// Inorder successor can never have a left child.
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
// Method 1 - using inorder predecessor
TreeNode* inorderPredecessor(TreeNode* root){
    // no need to check base base if(node->left == NULL) return NULL;
    // because since root has 2 children so it always has a predecessor
    TreeNode* pred = root->left;
    while(pred->right != NULL){
        pred = pred->right;
    }
    return pred;
}
TreeNode* deleteNode(TreeNode* root, int key){
    if(root == NULL){
        return NULL;
    }
    if(root->val == key){
        // case 1 : No Child
        if(root->left == NULL && root->right == NULL){
            return NULL;
        }
        // case 2 : 1 Child Node
        else if(root->left == NULL || root->right == NULL){
            if(root->left != NULL){
                return root->left; // directly attach root->left to key's parent
            }
            else return root->right; // directly attach root->right to key's parent
        }
        // case 3 : 2 Children Node
        else if(root->left != NULL && root->right != NULL){
            // replace the root with it's inorder successor or inorder predecessor
            // after replacing root with pred/suc, delete suc/pred
            TreeNode* pred = inorderPredecessor(root);
            root->val = pred->val;
            // predecessor always exists in Left Sub Tree
            // Successor always exists in Right Sub Tree
            // find pred and delete it from left sub tree
            root->left = deleteNode(root->left, pred->val);
        }
    }
    else if(root->val > key){ // go left
        // // find key and delete it from left sub tree
        root->left = deleteNode(root->left, key);
    }
    else if(root->val < key){ // go right
        // // find key and delete it from left sub tree
        root->right = deleteNode(root->right, key);
    }
    return root;
}

// Method 2 - using inorder successor
TreeNode* inorderSuccessor(TreeNode* root){
    // no need to check base base if(node->right == NULL) return NULL;
    // because since root has 2 children so it always has a successor
    TreeNode* suc = root->right;
    while(suc->left != NULL){
        suc = suc->left;
    }
    return suc;
}
TreeNode* deleteNode(TreeNode* root, int key){
    if(root == NULL){
        return NULL;
    }
    if(root->val == key){
        // case 1 : No Child
        if(root->left == NULL && root->right == NULL){
            return NULL;
        }
        // case 2 : 1 Child Node
        else if(root->left == NULL || root->right == NULL){
            if(root->left != NULL){
                return root->left; // directly attach root->left to key's parent
            }
            else return root->right; // directly attach root->right to key's parent
        }
        // case 3 : 2 Children Node
        else if(root->left != NULL && root->right != NULL){
            // replace the root with it's inorder successor or inorder predecessor
            // after replacing root with pred/suc, delete suc/pred
            TreeNode* suc = inorderSuccessor(root);
            root->val = suc->val;
            // predecessor always exists in Left Sub Tree
            // Successor always exists in Right Sub Tree
            // find suc and delete it from right sub tree
            root->right = deleteNode(root->right, suc->val);
        }
    }
    else if(root->val > key){ // go left
        // // find key and delete it from left sub tree
        root->left = deleteNode(root->left, key);
    }
    else if(root->val < key){ // go right
        // // find key and delete it from left sub tree
        root->right = deleteNode(root->right, key);
    }
    return root;
}
int main(){
    
    return 0;
}