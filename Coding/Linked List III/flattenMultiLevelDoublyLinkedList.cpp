// Leetcode 430
#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
Node* flatten(Node* head) {
    if(head == NULL) return head;
    Node* temp = head;
    while(temp != NULL){
        if(temp->child != NULL){
            Node* frwd = temp->next;
            temp->child = flatten(temp->child);
            temp->next = temp->child;
            temp->child->prev = temp;
            Node* c = temp->child;
            while(c->next != NULL){
                c = c->next;
            }
            c->next = frwd;
            if(frwd != NULL) frwd->prev = c;
            temp->child = NULL;
        }
        temp = temp->next;
    }
    return head;
}
int main(){
    return 0;
}