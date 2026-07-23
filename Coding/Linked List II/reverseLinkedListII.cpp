// Leetcode 92
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
ListNode* reverseBetween(ListNode* head, int left, int right){
    if(left == right) return head;
    // Break the linked list into three parts
    // 0 to left-1, left to right, right+1 to n-1 
    ListNode* a = NULL;
    ListNode* b = NULL;
    ListNode* c = NULL;
    ListNode* d = NULL;
    int n = 1;
    ListNode* temp = head;
    while(temp != NULL){
        if(n == left-1) a = temp;
        if(n == left) b = temp;
        if(n == right) c = temp;
        if(n == right+1) d = temp;
        n++;
        temp = temp->next;
    }
    if(a != NULL) a->next = NULL;
    c->next = NULL;
    c = reverseList(b);
    // b will be in it's place only
    if(a != NULL) a-> next = c;
    b->next = d;
    if(a != NULL) return head;
    else return c;
}
int main(){
    
}