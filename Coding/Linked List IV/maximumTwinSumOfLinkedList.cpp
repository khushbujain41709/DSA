// Leetcode 2130
#include<iostream>
using namespace std;
class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int data ){
        val = data;
        next = NULL;
    }
};
ListNode* reverse(ListNode* head){
    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* temp = NULL;
    while(curr != NULL){
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}
int pairSum(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    // Now points to left middle node
    ListNode* rev = reverse(slow->next);
    slow->next = NULL; // making two seperate linked lists
    int ans = 0;
    ListNode* temp = head;
    while(temp != NULL && rev){
        ans = max(ans , (temp->val + rev->val));
        temp = temp->next;
        rev = rev->next;
    }
    return ans;
}
int main(){
    
    return 0;
}