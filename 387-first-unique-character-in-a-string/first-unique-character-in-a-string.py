class Solution:
    def firstUniqChar(self, s: str) -> int:
        n=len(s)
        mp={}
        for i in range (n):
            mp[s[i]]= mp.get(s[i] , 0) + 1
        for i in range (n):
            if mp[s[i]]==1 :
                return i   
        return -1        