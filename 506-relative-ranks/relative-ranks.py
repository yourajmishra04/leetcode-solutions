class Solution:
    def findRelativeRanks(self, score: list[int]) -> list[str]:
        v=[]
        n=len(score)
        ans=[0]*n
        for i in range (n):
            v.append([score[i],i])
        v.sort(reverse = True)
        for i in range (n):
            if i == 0:
                ans[v[i][1]]="Gold Medal"
            elif i == 1:
                ans[v[i][1]]="Silver Medal"
            elif i == 2:
                ans[v[i][1]]="Bronze Medal"
            else:
                k=i+1
                ans[v[i][1]]= str(i+1)
        return ans
