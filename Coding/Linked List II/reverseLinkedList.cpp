// Leetcode 206
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
// Iterative method(Recommended)
ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* temp = head;
    while(curr != NULL){
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}
// Recursive method
// Hum aage ki linked list ko reverse krke le aayenge aur fir first node ko reversed list se attach kr denge
ListNode* reverseList(ListNode* head) {
    ListNode* temp = head;
    if(head == NULL || head->next == NULL) return head;
    head = reverseList(temp->next);
    temp->next->next = temp;
    temp->next = NULL;
    return head;
}
int main(){

}