class Solution:
    def isValid(self, s: str) -> bool:
        l = []
        for c in s:
            if l == []:
                l += c
            elif c == '(' or c == '[' or c == '{':
                l += c
            elif l[-1] == '(' and c == ')' or l[-1] == '[' and c == ']' or l[-1] == '{' and c == '}':
                l.pop()
            else:
                l += c
        return l == []