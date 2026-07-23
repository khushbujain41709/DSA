// Leetcode 21
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
// Space - O(m+n) where m is the length of list1 and n is the length of list2
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* temp1 = list1;
    ListNode* temp2 = list2;
    ListNode* c = new ListNode(100); // extra node
    ListNode* temp3 = c;
    while(temp1 != NULL && temp2 != NULL){
        if(temp1->val > temp2->val){
            ListNode* neww = new ListNode(temp2->val);
            temp3->next = neww;
            temp3 = neww;
            temp2 = temp2->next;
        }
        else{
            ListNode* neww = new ListNode(temp1->val);
            temp3->next = neww;
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
// Space is O(1)
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
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
int main(){
    return 0;
}