// Leetcode 437
// every node can be the starting point of a path
// node values can be negative.
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
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
// Solution 1
class Solution {
public:
    void helper(TreeNode* root, long long target, int& count){
        if(root == NULL) return;
        if((long long)(root-> val) == target){
            count ++;
        }
        helper(root->left, target - (long long)(root->val) , count);
        helper(root->right, target - (long long)(root->val) , count);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return 0;
        int count = 0;
        helper(root, (long long)targetSum, count);
        count += (pathSum(root->left , targetSum) + pathSum(root->right , targetSum)); // Just to visit each node.
        return count;
    }
};
// Solution 2
class Solution {
public:
    void findPath(TreeNode* root, int& count, long long targetSum){
        if(root == NULL) return;
        if(targetSum-root->val == 0){
            count++;
        }
        findPath(root->left, count, targetSum- root->val);
        findPath(root->right, count, targetSum- root->val);
    }
    void dfs(TreeNode* root, int& count, long long targetSum){
        if(root == NULL) return;
        findPath(root, count, targetSum);
        dfs(root->left, count, targetSum);
        dfs(root->right, count, targetSum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        dfs(root, count, (long long)targetSum);
        return count;
    }
};
int main(){
    TreeNode* a = new TreeNode(1);
    TreeNode* b = new TreeNode(2);
    TreeNode* c = new TreeNode(3);
    TreeNode* d = new TreeNode(4);
    TreeNode* e = new TreeNode(5);
    TreeNode* f = new TreeNode(6);
    TreeNode* g = new TreeNode(7);
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    return 0;
}