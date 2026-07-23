// Leetcode 725
// Length of parts is always equal to n/k, (n/k)+1, 0
// n % k parts has (n/k)+1 nodes 
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
vector<ListNode*> splitListToParts(ListNode* head, int k) {
    vector<ListNode*> ans;
    // Find the length of original linked list
    int n = 0;
    ListNode* temp = head;
    while(temp != NULL){
        n++;
        temp = temp->next;
    }
    // Breaking the linked list into k lists
    int extraNodesParts = n % k; // parts having one extra node that is (n/k)+1 nodes
    int nodesInParts = n/k;
    temp = head;
    while(temp != NULL){
        ListNode* c = new ListNode(100); // farzi node
        ListNode* tempC = c;
        int s = nodesInParts;
        if(extraNodesParts > 0){
            s++; // size increased by one
        }
        extraNodesParts--;
        for(int i = 0; i<s; i++){
            tempC->next = temp;
            temp = temp->next;
            tempC = tempC->next;
        }
        tempC->next = NULL;
        ans.push_back(c->next);
    }
    if(ans.size() < k){ // If k > n, see testcase 1
        int diff = k - ans.size();
        while(diff--){
            ans.push_back(NULL);
        }
    }
    return ans;
}
int main(){
    return 0;
}