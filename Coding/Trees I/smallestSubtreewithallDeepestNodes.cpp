// Leetcode 865 same as Leetcode 1123 - Lowest Common Ancestor of Deepest Leaves
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
int depth(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    return 1 + max(depth(root->left), depth(root->right));
}
void traverse(TreeNode* root, int idx, int& maxx, vector<TreeNode*>& v){
    if(root == NULL){
        return;
    }
    if(idx == maxx){
        v.push_back(root);
    }
    traverse(root->left, idx+1, maxx, v);
    traverse(root->right, idx+1, maxx, v);
}
TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    int maxHeight = depth(root);
    vector<TreeNode* > v;
    int maxDepth = maxHeight - 1;
    traverse(root, 0, maxDepth, v);
    TreeNode* ans = v[0];
    for(int i = 1; i<v.size(); i++){
        ans = lowestCommonAncestor(root, v[i], ans);
    }
    return ans;
}
int main(){
    
    return 0;
}