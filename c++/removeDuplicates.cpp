    //remove Duplicates from an Unsorted Linked List
    //LeetCodePremium
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
        ListNode* removeDuplicates(ListNode* head) {
            if (!head) return nullptr;  // If the list is empty, return nullptr
            unordered_map <int,int> Mymap;
            ListNode* current = head;

            // Traverse the list
            while (current && current->next) {
                Mymap[current->val] += 1;
                if (Mymap.find(current->next->val) != Mymap.end() || current->val == current->next->val) {
                    // Duplicate found, remove it by skipping the next node
                    ListNode* temp = current->next;
                    current->next = current->next->next;
                    delete temp;  // Free memory of removed node
                }else {
                    // Move to the next node if no duplicate
                    current = current->next;
                }
                
            }

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
        head = sol.removeDuplicates(head);
        while(head != NULL){
            cout << head->val << "->" ;
            head = head->next;
        }
        cout << "nullptr" << '\n';  
    }
