// Leetcode 2058
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
vector<int> nodesBetweenCriticalPoints(ListNode* head){
    if(head == NULL || head->next == NULL || head->next->next == NULL){
        return {-1,-1};
    }
    vector<int> index;
    ListNode* prev = head;
    ListNode* temp = head->next;
    ListNode* frwd = head->next->next;
    int idx = 1;
    while(frwd != NULL){
        if((temp->val > prev->val) && (temp->val > frwd->val)){ // local maxima
            index.push_back(idx);
        }
        else if((temp->val < prev->val) && (temp->val < frwd->val)){ // local minima
            index.push_back(idx);
        }
        idx++;
        temp = temp->next;
        prev = prev->next;
        frwd = frwd->next;
    }
    if(index.size() < 2){
        return {-1,-1};
    }
    int mini = INT_MAX;
    int maxx = index[index.size() - 1] - index[0];
    vector<int> diff;
    for(int i = 1; i<index.size(); i++){
        diff.push_back(index[i] - index[i-1]);
    }
    for(int i = 0; i<diff.size(); i++){
        mini = min(mini, diff[i]);
    }
    return {mini, maxx};
}
int main(){
    return 0;
}