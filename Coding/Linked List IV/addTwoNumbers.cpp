// Leetcode 2
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
// Method 1
// Giving TLE
void display(ListNode* head, string& s){
    ListNode* temp = head;
    if(head == NULL) return ;
    display(head->next, s);
    s += to_string(head->val);
    return;
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    string s1 = "";
    display(l1, s1);
    string s2 = "";
    display(l2, s2);
    long long num1 = stoll(s1);
    long long num2 = stoll(s2);
    long long sum = num1+num2;
    string s = to_string(sum);
    ListNode* c = new ListNode(100); // farzi node
    ListNode* temp = c;
    for(int i = s.size()-1; i>= 0; i--){
        int value = s[i] - '0';
        ListNode* neww = new ListNode(value);
        temp->next = neww;
        temp = temp->next;
    }
    return c->next;
}
// Method 2
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    int carry = 0;
    ListNode* dummy = new ListNode(0);
    ListNode* temp = dummy;
    while(l1 != NULL || l2 != NULL || carry){
        int sum = carry;
        if(l1 != NULL){
            sum += l1->val;
            l1 = l1->next;
        }
        if(l2 != NULL){
            sum += l2->val;
            l2 = l2->next;
        }
        carry = sum/10;
        temp->next = new ListNode(sum % 10);
        temp = temp->next;
    }
    return dummy->next;
}
int main(){
    return 0;
}