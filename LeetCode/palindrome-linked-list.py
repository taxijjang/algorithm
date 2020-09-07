import collections
import heapq
import functools
import itertools
import re
import sys
import math
from typing import *


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        q = collections.deque()

        if not head:
            return True

        node = head

        while node is not None:
            q.append(node.val)
            print(type(node.val))
            node = node.next

        if len(q) == 1:
            return True

        while len(q) > 1:
            if q.popleft() != q.pop():
                return False

        return True

