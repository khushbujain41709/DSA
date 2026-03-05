// Leetcode 2074
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
    if(c!= NULL) c->next = NULL;
    c = reverseList(b);
    // b will be in it's place only
    if(a != NULL) a-> next = c;
    b->next = d;
    if(a != NULL) return head;
    else return c;
}
ListNode* reverseEvenLengthGroups(ListNode* head){
    int gap = 1;
    ListNode* temp = head;
    while(temp != NULL && temp->next != NULL){
        int remLen = 0; // remaining length
        ListNode* t = temp->next;
        for(int i = 0; t!= NULL && i<=gap; i++){
            t = t->next;
            remLen++;
        }
        if(remLen < gap+1) gap = remLen-1;
        if(gap % 2 != 0){
            // temp is at position 1 and reverse from position 2 to position 2+gap
            reverseBetween(temp, 2, 2+gap);
            gap++;
            for(int i = 0; temp != NULL && i<gap; i++){
            // In testcase 2, in last group, gap is 2 but temp is NULL 
            // as remLen is only 1 that's why doing temp!= NULL
                temp = temp->next;
            }
        }
        else{
            gap++;
            for(int i = 0; temp != NULL && i<gap; i++){
            // In testcase 2, in last group, gap is 2 but temp is NULL 
            // as remLen is only 1 that's why doing temp!= NULL
                temp = temp->next;
            }
        }
    }
    return head;
}
int main(){
    return 0;
}