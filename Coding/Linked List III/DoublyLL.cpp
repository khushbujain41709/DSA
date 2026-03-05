// Time Complexity at insert at start is O(1).
// Time Complexity at insert at end is O(1) due to tail ponter no traversing is required.
// Time Complexity of insertion at kth position is O(k) and in worst case it is O(n).
// Time Complexity of deletion at head = O(1)
// Time Complexity of deletion at end = O(1)
// Time Complexity of deletion at kth position is O(k) and in worst case it is O(n).
// In circular singly linked list, tail->next = head;
// In circular doubly linked list, tail->next = head; and head->prev = tail;
#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* prev;
    Node* next;
    Node(int data){
        val = data;
        prev = NULL;
        next = NULL;
    }
};
class DoublyLinkedList{
    public: 
    Node* head;
    Node* tail;
    int size;
    DoublyLinkedList(){
        head = NULL;
        tail = NULL;
        size = 0;
    }
    void insertAtHead(int val){
        Node* new_node = new Node(val);
        if(size == 0){
            head = new_node;
            tail = new_node;
        }
        else{
            new_node ->next = head;
            head->prev = new_node;
            head = new_node;
        }
        size++;
        return;
    }
    void insertAtTail(int val){
        Node* new_node = new Node(val);
        // we are using traversing method but we can also use tail pointer.
        // Node * temp = head;
        // while(temp->next != NULL){
        //     temp = temp->next;
        // }
        // temp->next = new_node;
        // new_node->prev=temp;
        // new_node->next=NULL;
        if(size == 0){
            tail = new_node;
            head = new_node;
        }
        else{
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
        size++;
        return;
    }
    void insertAtIndex(int val ,int index){
        if(index < 0 || index  > size){
            cout<<"Invalid Index"<<endl;
        }
        else if(index == 0){
            insertAtHead(val);
        }
        else if(index == size){
            insertAtTail(val);
        }
        else{
            Node* new_node = new Node(val);
            Node* temp = head;
            for(int i = 0; i<index-1; i++){
                temp = temp->next;
            }
            new_node->next = temp->next;
            temp->next = new_node;
            new_node->prev = temp;
            new_node->next->prev = new_node; // as we have already set temp->next = new_node
            size++;
        }
        return;
    }
    void deleteAtHead(){
        Node* temp = head;
        if(size == 0){
            cout<<"List is Empty"<<endl;
            return;
        }
        head = head->next; 
        // in case of single node if we have set head = head ->next this means head is set to NULL now head ->prev is not defined.
        // we should also check---
        if(head == NULL){ 
            // head points to null as only single node was present in the linked list.
            tail = NULL;
        }
        else{
            head->prev = NULL;
        }
        free(temp);
        size--;
        return ;
    }
    void deleteAtTail(){
        Node* temp =  tail;
        if(size == 0){
            cout<<"List is Empty"<<endl;
            return;
        }
        tail = tail -> prev;
        if(tail == NULL){ 
            // tail points to null as only single node was present in the linked list.
            head == NULL;
        }
        else{
            tail->next = NULL;
        }
        free(temp);
        size--;
        return;
    }
    void deleteAtIndex(int index){
        if(size == 0){
            cout<<"List is Empty"<<endl;
            return;
        }
        else if(index < 0 || index  > size){
            cout<<"Invalid Index"<<endl;
        }
        else if(index == 0){
            deleteAtHead();
        }
        else if(index == size-1){
            deleteAtTail();
        }
        else{
            Node* temp = head;
            for(int i = 0; i<index-1; i++){
                temp = temp->next;
            }
            temp->next = temp->next->next;
            temp->next->prev = temp;
            size--;
        }
        return;
    }
    int getIndex(int index){
        if(index < 0 || index  > size){
            cout<<"Invalid Index"<<endl;
            return -1;
        }
        else if(index == 0){
            return head->val;
        }
        else if(index == size-1){
            return tail->val;
        }
        else{
            if(index < size/2){
                Node* temp = head;
                for(int i = 0; i<index; i++){
                    temp = temp->next;
                }
                return temp->val;
            }
            else{ // index >= size/2
                Node* temp = tail;
                for(int i = 0; i< size - index - 1; i++){
                    temp = temp->prev;
                }
                return temp->val;
            }
        }
    }
    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->val<<" <-> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};
int main(){
    Node* new_node = new Node(4);
    DoublyLinkedList dll;
    dll.head = new_node;
    dll.tail = new_node;
    cout<<dll.head->val;
    cout<<endl;
    dll.display();

    dll.deleteAtHead();// since only one is present.This function will make linked list empty.
    dll.display();

    dll.insertAtHead(11);
    dll.display();
    
    dll.insertAtHead(7);
    dll.insertAtHead(15);
    dll.display();

    dll.insertAtTail(20);
    dll.insertAtTail(16);
    dll.display();

    dll.insertAtIndex(23 , 2);
    dll.insertAtIndex(18,3);
    dll.display();

    cout<<dll.getIndex(2)<<endl;
    cout<<dll.getIndex(4)<<endl;

    dll.deleteAtHead();
    dll.display();

    dll.deleteAtTail();
    dll.display();

    dll.deleteAtIndex(3);
    dll.display();
    return 0;
}