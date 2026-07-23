// Leetcode 86
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
// just dry run - 10 80 40 30 60 70 15
ListNode* partition(ListNode* head, int x) {
    if(head == NULL || head->next == NULL) return head;
    ListNode* temp = head;
    ListNode* low = new ListNode(100); // connect all those nodes with low which are less than x
    ListNode* high = new ListNode(100); // connect all those nodes with low which are greater than x
    ListNode* tl = low;
    ListNode* th = high;
    while(temp != NULL){
        if(temp->val < x){
            tl->next = temp;
            temp = temp->next;
            tl = tl->next;
        }
        else{ // temp->val >= x
            th->next = temp;
            temp = temp->next;
            th = th->next;
        }
    }
    tl->next = NULL; // since we need to seperate both lists
    th->next = NULL; // since we need to seperate both lists
    tl->next = high->next; // high->next because we have one extra node 100 at starting of high
    return low->next; // low->next because we have one extra node 100 at starting of low
}
int main(){

}