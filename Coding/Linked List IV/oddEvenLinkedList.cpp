// Leetcode 328
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
ListNode* oddEvenList(ListNode* head){
    if(head == NULL || head->next == NULL) return head;
    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* evenHead = even;
    while(even != NULL && even->next != NULL){
        odd->next = odd->next->next;
        odd = odd->next;
        even->next = even->next->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}
int main(){
    
    return 0;
}