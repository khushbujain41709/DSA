// Leetcode 234
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
// Method 1 - Two pointer and get node at index i and j and check palindrome or not
// Method 2 - Reverse the linked list and check reverse is equal to original or not. Make a deep copy of original list and reverse it. TC = O(3n) and SC= O(n)
ListNode* createDeepCopy(ListNode* head){
    // Create a deep copy
    ListNode* c = new ListNode(100);
    ListNode* tempC = c;
    ListNode* temp = head;
    while(temp != NULL){
        ListNode* neww = new ListNode(temp -> val);
        tempC->next = neww;
        temp = temp->next;
        tempC = tempC->next;
    }
    // c->next gives head of deep copy linked list
    return c->next;
}
ListNode* reverse(ListNode* head){
    ListNode* prev = NULL;
    ListNode* temp = head;
    ListNode* curr = head;
    while(curr != NULL){
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}
bool isPalindrome(ListNode* head){
    ListNode* copy = createDeepCopy(head);
    // Reverse the deep copy linked list
    ListNode* rev = reverse(copy);
    // Check palindrome or not
    ListNode* temp = head;
    ListNode* tempR = rev;
    while(temp != NULL){
        if(temp->val != tempR->val){
            return false;
        }
        temp = temp->next;
        tempR = tempR->next;
    }
    return true;
}
// Method 3 - If the first half and the second half are the reverse of each other then it is a palindrome. TC = O(n) and SC = O(1)
ListNode* reverse(ListNode* head){
    ListNode* prev = NULL;
    ListNode* temp = head;
    ListNode* curr = head;
    while(curr != NULL){
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}
bool isPalindrome(ListNode* head){
    if(head == NULL or head->next == NULL){
        return true;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next != NULL && fast->next->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    // slow is at left middle or middle
    ListNode* right = slow->next;
    ListNode* rev = reverse(right);
    ListNode* temp = head;
    ListNode* tempR = rev;
    while(temp != NULL && tempR != NULL){
        if(temp->val != tempR->val) return false;
        temp = temp->next;
        tempR = tempR->next;
    }
    return true;
}
int main(){

}