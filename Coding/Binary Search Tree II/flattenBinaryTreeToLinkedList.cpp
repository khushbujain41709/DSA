// Leetcode 114
#include<iostream>
#include<vector>
#include<stack>
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
// Method 1 - Preorder : TC = O(n) and SC = O(n)
vector<TreeNode*> preorder(TreeNode* root){
    vector<TreeNode*> ans;
    stack<TreeNode*> st;
    if(root != NULL) st.push(root);
    while(st.size() > 0){
        TreeNode* temp = st.top();
        st.pop();
        ans.push_back(temp);
        if(temp->right != NULL){
            st.push(temp->right);
        }
        if(temp->left != NULL){
            st.push(temp->left);
        }
    }
    return ans;
}
void flatten(TreeNode* root){
    vector<TreeNode*> ans = preorder(root);
    int n = ans.size();
    for(int i = 0; i<n-1; i++){
        ans[i]->right = ans[i+1];
        ans[i]->left = NULL;
    }
    return;
}

// Method 2 - Recursion : TC = O(n)  and SC = O(n)
void flatten(TreeNode* root){
    if(root == NULL) return;
    TreeNode* r = root->right;
    TreeNode* l = root->left;
    root->left = NULL;
    root->right = NULL;
    flatten(l);
    flatten(r);
    root->right = l;
    TreeNode* temp = root; 
    // do not initialize with l as If l == NULL(i.e. root has no left child)
    while(temp->right != NULL){
        temp = temp->right;
    }
    temp->right = r;
}

// Method 3 - Using Morris Traversal
void flatten(TreeNode* root){
    TreeNode* curr = root;
    while(curr != NULL){
        if(curr->left != NULL){
            TreeNode* r = curr->right; // save this as we will break right pointer
            curr->right = curr->left; // imp 
            // find predecessor
            TreeNode* pred = curr->left;
            while(pred->right != NULL){
                pred = pred->right;
            }
            pred->right = r;
            curr = curr->left; // imp
        }
        else{
            curr = curr->right;
        }
    }
    // just to point all left pointers to NULL
    TreeNode* temp = root;
    while(temp != NULL){
        if(temp->left){
            temp->left = NULL;
        }
        temp = temp->right;
    }
    return;
}
int main(){
    
    return 0;
}