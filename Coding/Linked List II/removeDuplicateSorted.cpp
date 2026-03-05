// Leetcode - 83
#include<iostream>
using namespace std;
class ListNode{ // User defined data type
    public:
        int value;
        ListNode* next;
        ListNode(int data ){
            value = data;
            next = NULL;
        }
};
class LinkedList{ // User defined data structure
    public:
    ListNode* head;
    LinkedList(){
        head = NULL;
    }
    void insertAtEnd(int val){
        ListNode* new_node = new ListNode(val);
        if (head == NULL){   //Linked list is empty
            head = new_node;
            return;
        }
        ListNode* temp = head;
        while(temp ->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }
};
ListNode* deleteDuplicates(ListNode* head) {
if(head == NULL || head -> next == NULL) return head;
    ListNode* a = head;
    ListNode* b = head->next;
    while(b!= NULL){
        while(b!= NULL && a->value == b->value){
            b = b->next;
        }
        a -> next = b; 
        // next round
        a = b;
        if(b!= NULL) b = b-> next;
    }
    return head;
}
int main(){

} 