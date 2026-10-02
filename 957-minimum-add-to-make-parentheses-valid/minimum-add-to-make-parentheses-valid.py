class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        n=len(s)
        ans=0
        cnt=0
        for i in range (n):
            if s[i] =='(':
                cnt+=1
            else :
                if cnt == 0 :
                    ans+=1
                else:
                    cnt-=1
        return ans+cnt
        