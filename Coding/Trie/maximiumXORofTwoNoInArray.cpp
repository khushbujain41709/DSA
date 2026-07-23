// Leetcode 421
// Here we use binary trie indicates left child as 0 and right child as 1
// To maximise a XOR, we should make bits different as much as possible giving most significant bits higher priority.
// So we need more ones in most significant side
// Total number of branches in trie is number of elements in an array.
// Time complexity = O(n*32) as 0 <= nums[i] <= 2^31 - 1 so maximium bits is 32.
// 0 & 0 = 0 and 1 & 1 = 0
// 0 & 1 = 1 and 1 & 0 = 1
#include<iostream>
#include<vector>
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
int findMaximumXOR(vector<int>& nums){
    int ans = 0;
    node* head = new node();
    insert(head, nums[0]);
    for(int i = 1; i<nums.size(); i++){
        ans = max(ans, calculateXOR(head, nums[i]));
        insert(head, nums[i]);
    }
    return ans;
}
int main(){
    
    return 0;
}