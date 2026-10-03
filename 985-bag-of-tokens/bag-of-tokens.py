class Solution:
    def bagOfTokensScore(self, tok: list[int], power: int) -> int:
        tok.sort()
        n=len(tok)
        i=0
        j=n-1
        ans=0
        while i <= j:
            if tok[i]<=power:
                ans+=1
                power-=tok[i]
                i+=1
            else :
                if j==i:
                    break
                elif ans==0:
                    break
                else :
                    ans-=1
                    power+=tok[j]
                    j-=1
        return ans
        