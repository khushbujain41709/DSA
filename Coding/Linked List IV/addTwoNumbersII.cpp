// Leetcode 445
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
ListNode* reverseList(ListNode* head){
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* temp = NULL;
    while(curr != NULL){
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    int carry = 0;
    l1 = reverseList(l1);
    l2 = reverseList(l2);
    ListNode* dummy = new ListNode(0);
    ListNode* temp = dummy;
    while(l1 != NULL || l2 != NULL || carry){
        int sum = carry;
        if(l1 != NULL){
            sum += l1->val;
            l1 = l1->next;
        }
        if(l2 != NULL){
            sum += l2->val;
            l2 = l2->next;
        }
        carry = sum/10;
        temp->next = new ListNode(sum % 10);
        temp = temp->next;
    }
    dummy = reverseList(dummy->next);
    return dummy;
}
int main(){
    
    return 0;
}