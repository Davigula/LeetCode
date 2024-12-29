    //remove Nth Node from End of List

    #include<iostream>
    #include<unordered_map>
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
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode *fast = head, *slow = head;
            for (int i = 0; i < n; i++) fast = fast->next;
            if (!fast) return head->next;
            while (fast->next) fast = fast->next, slow = slow->next;
            slow->next = slow->next->next;
            return head;
        }
    };

    int main(){
        Solution sol;
        ListNode *head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(3);
        head->next->next->next = new ListNode(2);
        head->next->next->next->next = new ListNode(5);
        // head = swapPairs(head, 2, 6);
        head = sol.removeNthFromEnd(head, 3);
        while(head != NULL){
            cout << head->val << "->" ;
            head = head->next;
        }
        cout << "nullptr" << '\n';  
    }
