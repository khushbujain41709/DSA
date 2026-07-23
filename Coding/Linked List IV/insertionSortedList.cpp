// Leetcode 147
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
ListNode* insertionSortList(ListNode* head) {
    if(head == NULL || head->next == NULL){
        return head;
    }
    ListNode* temp = head->next;

    ListNode* sorted = head; 
    ListNode* find = sorted;
    sorted->next = NULL;

    ListNode* prev = NULL;
    ListNode* curr = NULL;
    while(temp != NULL){
        curr = temp;
        temp = temp->next;
        while(find != NULL && find->val < curr->val){
            prev = find;
            find = find->next;
        }
        // insert at beginning
        if(prev == NULL){
            curr->next = sorted;
            sorted = curr;
        }
        else{
            prev->next = curr;
            curr->next = find;
        }
        find = sorted;
        prev = NULL;
    }
    return sorted;
}
int main(){
    
    return 0;
}