// Leetcode 23
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
// Method 1 ----------------------------------------------------------------------------------
// Giving MLE
// TC = 2n + 3n + 4n + (k-1)n + kn = O(n*(k^2)) where k is the number of lists
// 2n is for merging two lists of size n and 3n for merging two lists of size n and 2n
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
ListNode* mergeKLists(vector<ListNode*>& lists) { // Giving MLE
    if(lists.size() == 0) return NULL;
    if(lists.size() == 1) return lists[0];
    while(lists.size() > 1){
        ListNode* a = lists[lists.size()-1];
        lists.pop_back();
        ListNode* b = lists[lists.size()-1];
        lists.pop_back();
        ListNode* c = mergeTwoLists(a,b);
        lists.push_back(c);
    }
    return lists[0];
}
// Method 2 ----------------------------------------------------------------------------------
// But if we do like merge every two array so it will take 2n for each pair then 4n for each pair and so on so TC = O(n*k*logk)
// Space - O(k)
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
ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.size() == 0) return NULL;
    if(lists.size() == 1) return lists[0];
    while(lists.size() > 1){
        ListNode* a = lists[0];
        lists.erase(lists.begin());
        ListNode* b = lists[0];
        lists.erase(lists.begin());
        ListNode* c = mergeTwoLists(a,b);
        lists.push_back(c);
    }
    return lists[0];
}
int main(){

}