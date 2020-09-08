class TrieNode:
    def __init__(self):
        self.word = False
        self.children = dict()

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self,word : str) -> None:
        node = self.root

        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]

        node.word= True

    def search(self,word : str)-> bool:
        node = self.root

        for char in word:
            if char not in node.children:
                return False

            node = node.children[char]

        return node.word

trie = Trie()

trie.insert('apple')

if trie.search('appe'):
    print("YES")
else:
    print("NO")

import collections

class TrieNode:
    def __init__(self):
        self.word = False
        self.children = collections.defaultdict(TrieNode)

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self,word : str) -> None:
        node = self.root

        for char in word:
            node = node.children[char]

        node.word= True

    def search(self,word : str)-> bool:
        node = self.root

        for char in word:
            if char not in node.children:
                return False

            node = node.children[char]

        return node.word


trie = Trie()

trie.insert('apple')

if trie.search('apple'):
    print("YES")
else:
    print("NO")