// Leetcode 2074
#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
Node* copyRandomList(Node* head) {
    // Step 1 - Create the deep copy without random pointer
    Node* dummy = new Node(0);
    Node* tempd = dummy;
    Node* temp = head;
    while(temp != NULL){
        Node* neww = new Node(temp->val);
        tempd->next = neww;
        tempd = tempd->next;
        temp = temp->next;
    }
    // Step 2 - Create alternate connections(merge) - connect original to dummy in zigzag pattern
    Node* duplicate = dummy->next;
    Node* c = new Node(0);
    Node* tempc = c;
    Node* a = head;
    Node* b = duplicate;
    while(b != NULL){
        tempc->next = a;
        a = a->next;
        tempc = tempc->next;
        tempc->next = b;
        b = b->next;
        tempc = tempc->next;
    }
    c = c->next;
    // Step 3 - Assigning random pointer of duplicate
    Node* t1 = c;
    while(t1 != NULL){
        Node* t2 = t1->next;
        if(t1->random != NULL) t2->random = t1->random->next;  // IMP
        // if(t1->random == NULL) then t2->random == NULL but it is by default NULL
        t1 = t1->next->next;
    }
    // Step 4 - Removing connections
    Node* original = new Node(0);
    t1 = original;
    Node* ans = new Node(0);
    Node* t2 = ans;
    Node* t = c;
    while(t != NULL){
        t1->next = t;
        t = t->next;
        t1 = t1->next;
        t2->next = t;
        t = t->next;
        t2 = t2->next;
    }
    t1->next = NULL;
    t2->next = NULL;
    return ans->next;
}
int main(){
    return 0;
}