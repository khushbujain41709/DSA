// Leetcode 24
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
ListNode* swapPairs(ListNode* head) {
    if(head == NULL || head->next == NULL) return head;
    ListNode* temp = head;
    ListNode* dummy = new ListNode(0);
    ListNode* tempD = dummy;
    while(temp != NULL  && temp->next != NULL){
        ListNode* first = temp;
        ListNode* second = temp->next;

        tempD->next = second;
        first->next = second->next; // imp
        second->next = first;

        tempD = first;
        temp = first->next;
    }
    return dummy->next;
}
int main(){
    
    return 0;
}