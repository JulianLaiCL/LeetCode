class Solution:
    def addTwoNumbers(self, l1, l2):
        carry = 0
        idx = 0
        tmp = None
        ans = None
        while l1 or l2 or carry:
            if tmp == None:
                tmp = ListNode(0)
                ans = tmp
            else:
                tmp.next = ListNode(0)
                tmp = tmp.next
            val1 = 0
            val2 = 0
            if l1:
                val1 = l1.val
                l1 = l1.next
            if l2:
                val2 = l2.val
                l2 = l2.next
            tmp.val = val1 + val2 + carry
            if tmp.val >= 10:
                tmp.val -= 10
                carry = 1
            else:
                carry = 0
            ++idx
        return ans

"""
if __name__ == "__main__":
    class ListNode:
        def __init__(self, x):
            self.val = x
            self.next = None    
    node1 = ListNode(2)
    node2 = ListNode(4)
    node3 = ListNode(3)
    node1.next = node2
    node2.next = node3
    node4 = ListNode(5)
    node5 = ListNode(6)
    node6 = ListNode(4)
    node4.next = node5
    node5.next = node6
    sol = Solution()
    result = sol.addTwoNumbers(node1,node4)
    while result:
        print(result.val)
        result = result.next
"""