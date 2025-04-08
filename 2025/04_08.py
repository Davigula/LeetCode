#Merge Two Lists
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
    def __str__(self):
        return str(self.val)

class Solution:
    

    def mergeTwoLists(self, list1, list2):
        dummy = ListNode()
        current = dummy
        
        while list1 is not None and list2 is not None:
            if list1.val <= list2.val:
                current.next = list1
                list1 = list1.next
            else:
                current.next = list2
                list2 = list2.next
            current = current.next
        
        if list1 is not None:
            current.next = list1
        elif list2 is not None:
            current.next = list2

        return dummy.next
    
    def print(self, dummy):
        # itr = dummy.val
        result = []
        while dummy.val:
            result.append(str(dummy))
            dummy = dummy.next
        print(' --> '.join(result))

if __name__ == "__main__":

    list1 = ListNode(1)
    list2 = ListNode(3)
    david = Solution().mergeTwoLists(list1, list2)
    Solution().print(Solution().mergeTwoLists(list1, list2)) 