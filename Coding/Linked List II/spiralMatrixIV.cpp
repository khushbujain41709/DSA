// Leetcode 2326
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
vector<vector<int>> spiralMatrix(int m, int n, ListNode* head){
    vector<vector<int>> ans(m, vector<int>(n, -1)); // fill it with -1 so tht we can return we iur linked list is over
    int minr = 0;
    int minc = 0;
    int maxr = m-1;
    int maxc = n-1;
    ListNode* temp = head;
    while(minr <= maxr || minc <= maxc){
        // right
        for(int i = minc; i<=maxc ; i++){
            ans[minr][i] = temp->val;
            if(temp-> next == NULL) return ans;
            temp = temp->next;
        }
        minr++;
        if(minr > maxr) break;
        // down
        for(int i = minr; i<=maxr ; i++){
            ans[i][maxc] = temp->val;
            if(temp-> next == NULL) return ans;
            temp = temp->next;
        }
        maxc--;
        if(minc > maxc) break;
        // left
        for(int i = maxc; i>=minc; i--){
            ans[maxr][i] = temp->val;
            if(temp-> next == NULL) return ans;
            temp = temp->next;
        }
        maxr --;
        // up
        for(int i = maxr; i>= minr; i--){
            ans[i][minc] = temp->val;
            if(temp-> next == NULL) return ans;
            temp = temp->next;
        }
        minc++;
    }
    return ans;
}
int main(){
    return 0;
}