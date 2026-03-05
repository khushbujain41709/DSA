// Leetcode 94
// It is an iterative inorder traversal which has O(1) space complexity
// Bhul jane vali cheez hai, interview k pehle dekh k jana hai
#include<iostream>
#include<vector>
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
vector<int> inorderTraversal(TreeNode* root) {
    // Morris Inorder Traversal
    vector<int> ans;
    TreeNode* curr = root;
    while(curr != NULL){
        if(curr->left != NULL){
            TreeNode* pred = curr->left;
            while(pred->right != NULL && pred->right != curr){ // imp condition
                pred = pred->right;
            }
            if(pred->right == NULL){ // link
                pred->right = curr;
                curr = curr->left; // imp
            }
            else if(pred->right == curr){ // unlink
                pred->right = NULL;
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
        else{ // curr->left == NULL
            ans.push_back(curr->val);
            curr = curr->right;
        }
    }
    return ans;
}
int main(){
    
    return 0;
}