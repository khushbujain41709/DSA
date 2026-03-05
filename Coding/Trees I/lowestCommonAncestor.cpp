// Leetcode - 236
// if p lies in LST and q lies in RST then LCA is root.
// if q lies in LST and p lies in RST then LCA is root.
#include<iostream>
#include<vector>
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
bool isExists(TreeNode* root ,TreeNode* target){
    if(root == NULL) return false;
    if(root == target) return true;
    return (isExists(root->left , target) || isExists(root->right , target));
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == p || root == q) return root;
    else if(isExists(root -> left, p) && isExists(root -> right,q)) return root;
    else if(isExists(root -> left, q) && isExists(root -> right,p)) return root;
    else if(isExists(root -> left, p) && isExists(root -> left,q)) return lowestCommonAncestor(root->left,p,q);
    else return lowestCommonAncestor(root->right,p,q);
}
int main(){
    return 0;
}
/*
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

isExists(root->left, p) = isExists(5,5) → true
isExists(root->left, q) = isExists(5,4) → true
Both in left subtree → recurse left:
lowestCommonAncestor(root=5, p=5, q=4)

Step 2: Call lowestCommonAncestor(root=5, p=5, q=4)
Check left subtree of 5:
isExists(root->left, p) = isExists(6,5) → false
isExists(root->left, q) = isExists(6,4) → false

Check right subtree of 5:
isExists(root->right, p) = isExists(2,5) → false
isExists(root->right, q) = isExists(2,4) → true

Neither left nor right have both nodes, so we go to:
else return root;
Return root=5


*/