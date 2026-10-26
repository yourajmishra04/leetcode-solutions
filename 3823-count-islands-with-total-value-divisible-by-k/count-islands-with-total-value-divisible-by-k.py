class Solution:
    m=0
    n=0
    vis=list[list[bool]]

    def solve(self , grid: List[List[int]], i: int , j :int )->int:
        if i<0 or j<0 or i>=self.n or j>=self.m or self.vis[i][j] or grid[i][j]==0:
            return 0
        self.vis[i][j]=True
        ans=grid[i][j]
        ans+=self.solve(grid,i+1,j)
        ans+=self.solve(grid,i-1,j)
        ans+=self.solve(grid,i,j+1)
        ans+=self.solve(grid,i,j-1)
        return ans


    def countIslands(self, grid: List[List[int]], k: int) -> int:
        self.n=len(grid)
        self.m=len(grid[0])
        self.vis=[[False]*self.m for _ in range (self.n)]
        ans=0
        for i in range (self.n):
            for j in range(self.m):
                if grid[i][j] > 0 and self.vis[i][j]==False:
                    num= self.solve(grid,i,j)
                    if num % k ==0:
                        ans+=1
        return ans