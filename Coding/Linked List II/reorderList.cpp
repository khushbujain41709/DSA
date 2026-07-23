// Leetcode 143
#include<bits/stdc++.h>
using namespace std;
class ListNode{ // User defined data type
public:
    int val;
    ListNode* next;
    ListNode(int data ){
        val = data;
        next = NULL;
    }
};
class LinkedList{ // User defined data structure
public:
    ListNode* head;
    ListNode* tail;
    LinkedList(){
        head = NULL;
        tail = NULL;
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
void reorderList(ListNode* head) {
    if(head == NULL || head->next == NULL) return;
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = NULL;
    // I want node which is right middle/ middle 
    while(fast != NULL && fast->next != NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    // slow is pointing to node right middle/ middle
    ListNode* rev = reverse(slow);
    // We have to break a linked list into two linked list
    prev->next = NULL;
    slow->next = NULL;
    ListNode* tempR = rev;
    ListNode* temp = head;
    // Farzi Node
    ListNode* c = new ListNode(100);
    ListNode* tempC = c;
    while(temp != NULL && tempR != NULL){
        tempC->next = temp;
        temp = temp->next;
        tempC = tempC->next;
        tempC->next = tempR;
        tempR = tempR->next;
        tempC = tempC->next;
    }
    tempC->next = tempR; // In case of odd length linked list one node will be left
    head = c->next; // because of farzi node
    return;
}
int main(){
    
}