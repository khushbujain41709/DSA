// Leetcode 1707
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    node* left;
    node* right;
    node(){
        left = NULL;
        right = NULL;
    }
};
int calculateXOR(node* head, int val){ // calculate xor when traversing
    node* curr = head;
    int ans = 0;
    for(int i = 31; i>=0; i--){ // because of 32 bits
        int bit = (val >> i) & 1; // for each digit in val - xor with 1
        if(bit == 0){
            if(curr->right != NULL){ 
                // if bit is 0 and we got 1 in trie - 1 & 0 is 1 so add it in answer
                // For example, if 5th bit is 1 then 2^5 is 32 add it
                ans += (1 << i);
                curr = curr->right;
            }
            else{
                curr = curr->left; 
                // if bit is 0 and we got 0 in trie - 0 & 0 is 0 so simply traverse below
            }
        }
        else{ // bit is 1
            if(curr->left != NULL){ 
                // if bit is 0 and we got 1 in trie - 1 & 0 is 1 so add it in answer
                // For example, if 5th bit is 1 then 2^5 is 32 add it
                ans += (1 << i);
                curr = curr->left;
            }
            else{
                curr = curr->right; 
                // if bit is 0 and we got 0 in trie - 0 & 0 is 0 so simply traverse below
            }
        }
    }
    return ans;
}
void insert(node* head, int val){
    node* curr = head;
    for(int i = 31; i>=0; i--){ // because of 32 bits
        int bit = (val >> i) & 1; // for each digit in val - xor with 1
        if(bit == 0){
            if(curr->left != NULL){ // 0 already exists
                curr = curr->left;
            }
            else{
                curr->left = new node();
                curr = curr->left; 
            }
        }
        else{ // bit is 1
            if(curr->right != NULL){ // 1 already exists
                curr = curr->right;
            }
            else{
                curr->right = new node();
                curr = curr->right; 
            }
        }
    }
}
vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size();
    vector<int> result(queries.size());
    sort(nums.begin(), nums.end());
    vector<array<int, 3>> q; // stores{m,x,index} maintains index even after sorting
    for(int i = 0; i < queries.size(); i++){
        q.push_back({queries[i][1], queries[i][0], i});
    }
    sort(q.begin(), q.end());
    // automatically sort by m as queries[i][1] is entered before queries[i][0]
    node* head = new node();
    int k = 0;
    for(int i = 0; i<q.size(); i++){
        int ans = 0;
        int m = q[i][0];
        int x = q[i][1];
        int idx = q[i][2];
        // Insert all nums[k] <= m
        while(k < n && nums[k] <= m){
            insert(head, nums[k]);
            k++;
        }
        // If trie is empty → no valid number
        if(k == 0){
            result[idx] = -1;
            continue;
        }
        result[idx] = calculateXOR(head, x);
    }
    return result;
}
int main(){
    
    return 0;
}