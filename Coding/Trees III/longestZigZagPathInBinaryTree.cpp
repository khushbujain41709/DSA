// Leetcode 1372
#include<bits/stdc++.h>
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
// Gives TLE
class Solution {
public:
    int zigZag(TreeNode* root, int dir){
        if(root == NULL) return 0;
        if(dir == 1 && root->right != NULL){
            if(root->right == NULL) return 0;
            return 1+zigZag(root->right, 0);
        }
        if(dir == 0 && root->left != NULL){
            if(root->left == NULL) return 0;
            return 1+zigZag(root->left, 1);
        }
        return 0;
    }
    void dfs(TreeNode* root, int& maxx){
        if(root == NULL) return;
        // TLE bcoz every node is calling ZigZag twice and also
        // because the same tree paths are being traversed again and again.
        // when dfs() reaches node 2, we calculate: 2 → 3 → 4 → 5
        // Then from node 3, you calculate: 3 → 4 → 5
        int r = zigZag(root, 1);
        int l = zigZag(root, 0);
        maxx = max(maxx, max(l,r));
        dfs(root->left, maxx);
        dfs(root->right, maxx);
    }
    int longestZigZag(TreeNode* root) {
        if(root == NULL) return 0;
        int maxx = INT_MIN;
        dfs(root, maxx);
        return maxx;
    }
};
// Correct solution
class Solution {
public:
    int ans = 0;
    void dfs(TreeNode* root, bool dir, int count){
        if(root == NULL) return;
        ans = max(ans, count);
        if(dir == 0){ // dir == 0 means we came from right dir now we need to go to left
            dfs(root->left, 1, count+1);
            dfs(root->right, 0, 1);
        }
        else{ // dir == 1
            // // dir == 1 means we came from left dir now we need to go to right
            dfs(root->right, 0, count+1);
            dfs(root->left, 1, 1);
        }
    }
    int longestZigZag(TreeNode* root) {
        if(root == NULL) return 0;
        dfs(root, 0, 0);
        return ans;
    }
};
int main(){
    
    return 0;
}