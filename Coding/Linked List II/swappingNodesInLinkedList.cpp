// Leetcode 1721
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
ListNode* swapNodes(ListNode* head, int k) {
    if(head == NULL || head->next == NULL) return head;
    ListNode* b = NULL;
    ListNode* e = NULL;
    ListNode* temp = head;
    int count = 0;
    while(temp != NULL){
        temp = temp->next;
        count++;
    }
    temp = head;
    int n = 1; // 1 indexed
    while(temp != NULL){
        if(n == k) b = temp;
        if(n == count-k+1) e = temp;
        temp = temp->next;
        n++;
    }
    // same node(no swap needed)
    if(b == e) return head;
    swap(b->val, e->val);
    return head;
}
int main(){
    
}