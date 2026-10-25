class Solution:
    vis=list[list[bool]]
    n=0
    m=0
    flg=False

    def solve(self , grid: list[list[int]] , i : int ,j:int) :
        
        if i<0 or j<0 or i>=self.n or j>=self.m or self.vis[i][j] or grid[i][j]==1:
            return
        if i==0 or j==0 or i==self.n-1 or j==self.m-1:
            self.flg=False
        self.vis[i][j]=True
        self.solve(grid,i+1,j)
        self.solve(grid,i-1,j)
        self.solve(grid,i,j+1)
        self.solve(grid,i,j-1)


    def closedIsland(self, grid: list[list[int]]) -> int:
        self.n=len(grid)
        self.m=len(grid[0])
        ans=0
        self.vis=[[False]*self.m for _ in range (self.n)]
        for i in range (self.n):
            for j in range(self.m):
                if self.vis[i][j]==False and grid[i][j]==0:
                    self.flg=True
                    self.solve(grid,i,j)
                    if self.flg==True:
                        ans+=1
        return ans

        