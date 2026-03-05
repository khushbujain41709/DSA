// Leetcode 82
#include<bits/stdc++.h>
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
class LinkedList{
public:
    ListNode* head;
    ListNode* tail;
    LinkedList(){
        head = NULL;
        tail = NULL;
    }
};
ListNode* deleteDuplicates(ListNode* head){
    if(head == NULL || head->next == NULL) return head;
    ListNode* prev = head;
    ListNode* curr = head->next;
    // farzi node
    ListNode* c = new ListNode(100);
    // tempC stays at last unique node
    ListNode* tempC = c;
    tempC->next = head;
    while(curr != NULL){
        if(curr != NULL && prev->val == curr->val){
            while(curr != NULL && prev->val == curr->val){
                curr = curr->next;
            }
            tempC->next = curr;
            if(curr != NULL){
                prev = curr;
                curr = curr->next;
            }
        }
        else{
            tempC = prev;
            if(curr != NULL){
                prev = curr;
                curr = curr->next;
            }
        }
    }
    return c->next;
}
int main(){
    return 0;
}