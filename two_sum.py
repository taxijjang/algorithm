import collections
import heapq
import functools
import itertools
import re
import sys
import math
import bisect
from typing import *


# class Solution:
#     def twoSum(self, nums: List[int], target: int) -> List[int]:
#         nums_dict = dict()
#
#         for i, num in enumerate(nums):
#             nums_dict[num] = i
#
#         print(nums_dict)
#         for i, num in enumerate(nums):
#             if target - num in nums_dict and i != nums_dict[target - num]:
#                 return nums.index(num), nums_dict[target - num]
#
#
# nums: List[int] = list(map(int, sys.stdin.readline().split()))
# target: int = int(input())
#
# solution = Solution()
#
# print(solution.twoSum(nums, target))

class Solution:
    def twoSum(self,num: List[int], target:int )-> List[int]:
        nums_dict = dict()

        for i ,num in enumerate(num):

            if target - num in nums_dict:
                return [nums_dict[target-num],i]

            nums_dict[num] = i
