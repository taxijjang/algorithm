class Solution:
    def isValid(self, s: str) -> bool:
        stack = list()

        table = {
            '(': ')',
            '[': ']',
            '{': '}',
        }

        for i in s:
            if i in table:
                stack.append(i)

            elif len(stack) <= 0 or table[stack.pop()] != i:
                return False

        if len(stack) > 0:
            return False
        return True