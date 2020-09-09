# import collections
# import heapq
# import functools
# import itertools
# import re
# import sys
# import math
# from typing import *
#
# n = int(sys.stdin.readline().rstrip())
#
# words = []
#
# for _ in range(n):
#     word = str(sys.stdin.readline().rstrip())
#     words.append(word)
#
# class TrieNode:
#     def __init__(self):
#         self.word = False
#         self.children = collections.defaultdict(TrieNode)
#
# class Trie:
#     def __init__(self):
#         self.root = TrieNode()
#
#     def insert(self, word: str) -> None:
#         node = self.root
#
#         for char in word:
#             node = node.children[char]
#
#         node.word = True
#
#     def search(self, word: str) -> bool:
#         node = self.root
#
#         for char in word:
#             node = node.children[char]
#
#         if len(node.children) == 0 and node.word is True:
#             return True
#
#         else:
#             return False
#
#
# trie = Trie()
#
# res = 0
#
# for w in words:
#     trie.insert(w)
#
# for w in words:
#     if trie.search(w):
#         res += 1
#
# print(res)


import collections
import heapq
import functools
import itertools
import re
import sys
import math
from typing import *

n = int(sys.stdin.readline().rstrip())

words = [str(sys.stdin.readline().rstrip()) for _ in range(n)]
words.sort(key=len, reverse=True)

words_count = collections.defaultdict(int)

res = 0

for i in range(len(words)):
    if words_count[words[i]] != 0:
        continue

    for j in range(i+1, len(words)):
        if words[i][:len(words[j])] == words[j] and words_count[words[j]] == 0:
            words_count[words[j]] += 1

    res += 1

print(res)