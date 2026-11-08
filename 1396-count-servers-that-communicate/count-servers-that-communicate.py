class Solution:
    def countServers(self, grid: list[list[int]]) -> int:
        mpr={}
        mpc={}
        n=len(grid)
        m=len(grid[0])
        for i in range(n):
            for j in range(m):
                if grid[i][j]==1:
                    mpr[i]=mpr.get(i,0)+1
                    mpc[j]=mpc.get(j,0)+1
        ans=0
        for i in range(n):
            for j in range (m):
                if grid[i][j]==1:
                    if mpr[i]>1 or mpc[j]>1:
                        ans+=1
        return ans
