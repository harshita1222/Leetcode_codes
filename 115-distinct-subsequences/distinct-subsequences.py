class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        @cache
        def rec(i,j):
            if i == n:
                return 1
            if j == m:
                return 0
            ans = 0
            if t[i] == s[j]:
                ans += rec(i+1,j+1)
            ans += rec(i,j+1)
            return ans
        n,m = len(t),len(s)
        return rec(0,0)      