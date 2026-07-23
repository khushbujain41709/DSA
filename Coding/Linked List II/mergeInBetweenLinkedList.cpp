// Leetcode 1669
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
ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    if(list1 == NULL) return list1;
    ListNode* temp1 = list1;
    for(int i = 0; i<a-1; i++){
        temp1 = temp1->next;
    }
    ListNode* temp2 = list1;
    for(int i = 0; i<b; i++){
        temp2 = temp2->next;
    }
    int m = 0;
    ListNode* temp = list2;
    while(temp -> next!= NULL){
        m++;
        temp = temp->next;
    }
    // temp is at last node
    temp1->next = list2;
    temp->next = temp2->next;
    return list1;
}
int main(){

}