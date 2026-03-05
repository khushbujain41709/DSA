// Leetcode 148
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
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
    ListNode* temp1 = list1;
    ListNode* temp2 = list2;
    ListNode* c = new ListNode(100); // extra node
    ListNode* temp3 = c; 
    while(temp1 != NULL && temp2 != NULL){
        if(temp1->val > temp2->val){
            temp3->next = temp2;
            temp3 = temp3->next;
            temp2 = temp2->next;
        }
        else{
            ListNode* neww = new ListNode(temp1->val);
            temp3->next = temp1;
            temp3 = temp3->next;
            temp1 = temp1->next;
        }
    }
    if(temp1 == NULL){
        temp3 -> next = temp2;
    }
    if(temp2 == NULL){
        temp3 -> next = temp1;
    }
    return c->next; // as c is extra node
}
ListNode* sortList(ListNode* head){
    // base case for recursion
    if(head == NULL || head->next == NULL) return head;
    // Finding left middle node to break linked list into two parts
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != NULL && fast->next != NULL && fast->next->next != NULL){
        // fast->next->next != NULL for left middle
        slow = slow->next;
        fast = fast->next->next;
    }
    // slow points to left middle now
    ListNode* start = head;
    ListNode* right = slow->next;
    slow->next = NULL;
    // use recursion
    start = sortList(start);
    right = sortList(right);
    // merge two sorted lists
    ListNode* result = mergeTwoLists(start, right);
    return result;
}
int main(){
    
}