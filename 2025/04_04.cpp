//swap Node pairs in Linked List
#include<iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // ListNode* dummy;
        // dummy->next = head;
        if(head==NULL || head->next == nullptr){
            return head;
        }
        ListNode*temp=head->next;
        head->next=swapPairs(head->next->next);
        temp->next=head;
        return temp;

    }

};




int main(){
    Solution sol;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    // head = swapPairs(head, 2, 6);
    head = sol.swapPairs(head);
    while(head != NULL){
        cout << head->val << "->" ;
        head = head->next;
    }
    cout << "nullptr" << '\n';  
}