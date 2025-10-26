class Solution:
    def lexSmallest(self, s: str) -> str:
        ans = s
        for i in range(len(s)):
            x = s[:i]
            y = s[i:]
            ans = min(ans, x[::-1] + y)
        for i in range(len(s)):
            x = s[:i]
            y = s[i:]
            ans = min(ans, x + y[::-1])
        return ans