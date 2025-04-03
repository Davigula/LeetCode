//remove Duplicates from Sorted Linked List
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0, head);
        ListNode *prev = &dummy, *curr = head;
        
        while(curr) {
            ListNode *next_node = curr->next;
            while(next_node && curr->val == next_node->val) {
                ListNode *temp = next_node->next;
                delete next_node;
                next_node = temp;
            }
            
            if(curr->next == next_node) {
                prev = curr;
            } else {
                prev->next = next_node;
                delete curr;
            }
            curr =  next_node;
        }
        
        return dummy.next;
    }
};

int main(){
    Solution sol;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    // head->next->next = new ListNode(2);
    // head->next->next->next = new ListNode(4);
    // head->next->next->next->next = new ListNode(5);
    // head = swapPairs(head, 2, 6);
    head = sol.deleteDuplicates(head);
    while(head != NULL){
        cout << head->val << "->" ;
        head = head->next;
    }
    cout << "nullptr" << '\n';  
}