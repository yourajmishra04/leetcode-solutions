class Solution:
    def maxCoins(self, piles: list[int]) -> int:
        n=len(piles)
        l=0
        r=len(piles)-1
        ans=0
        piles.sort()
        while l<r:
            ans+=piles[r-1]
            l+=1
            r-=2
        return ans
        