// 1) Go left once
// 2) Keep going right until we find a NULL node
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
Node* inorderPredecessor(Node* root){
    if(root->left == NULL){
        return NULL;
    }
    else{
        Node* pred = root->left;
        while(pred->right != NULL){
            pred = pred->right;
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

    Node* pred = inorderPredecessor(a);
    cout<<pred->val<<endl;
    return 0;
}