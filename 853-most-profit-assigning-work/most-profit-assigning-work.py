class Solution:
    def maxProfitAssignment(self, difficulty: list[int], profit: list[int], worker: list[int]) -> int:
        n=len(profit)
        m=len(worker)
        v=[]
        for i in range (n):
            v.append([ difficulty[i], profit[i]])
        v.sort()
        ans=0
        for i in range (1,n):
            v[i][1]=max(v[i][1],v[i-1][1])
        for i in range(m):
            l=0
            r=n-1
            mid=0
            idx=-1
            while l<=r:
                mid=(l+r)//2
                if v[mid][0]<=worker[i]:
                    idx=mid
                    l=mid+1
                else:
                    r=mid-1
            if idx>-1:
                ans+=v[idx][1]
        return ans