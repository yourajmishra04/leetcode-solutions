class Solution:
    def minInsertions(self, s: str) -> int:
        n = len(s)
        cnt = 0
        ans = 0
        i = 0
        while i < n:
            if s[i] == "(":
                cnt += 1
            else:
                if i == n - 1:
                    if cnt > 0:
                        cnt -= 1
                        ans += 1
                    else:
                        ans += 2
                else:
                    if s[i + 1] == "(":
                        if cnt > 0:
                            cnt -= 1
                            ans += 1
                        else:
                            ans += 2
                    else:
                        if cnt > 0:
                            cnt -= 1
                        else:
                            ans += 1
                        i += 1
            i+=1
        ans += 2 * cnt
        return ans
