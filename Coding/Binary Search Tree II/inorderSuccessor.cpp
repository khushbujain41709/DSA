// 1) Go right once
// 2) Keep going left until we find a NULL node
#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int data){
        val = data;
        left = NULL;
        right = NULL;
    }
};
Node* inorderSuccessor(Node* root){
    if(root->right == NULL){
        return NULL;
    }
    else{
        Node* pred = root->right;
        while(pred->left != NULL){
            pred = pred->left;
        }
        return pred;
    }
}
void display(Node* root){
    if(root == NULL) return ;
    cout<<root->val<<" ";
    display(root->left);
    display(root->right);
}
int main(){
    Node* a = new Node(4);
    Node* b = new Node(2);
    Node* c = new Node(6);
    Node* d = new Node(1);
    Node* e = new Node(3);
    Node* f = new Node(5);
    Node* g = new Node(7);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;

    display(a);
    cout<<endl;

    Node* pred = inorderSuccessor(a);
    cout<<pred->val<<endl;
    return 0;
}