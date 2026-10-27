class Solution:
    def createGrid(self, m: int, n: int) -> list[str]:
        ans=[]
        for i in range (m):
            ss=""
            for j in range (n):
                if i==m-1 or j==0:
                    ss+='.'
                else :
                    ss+='#'
            ans.append(ss)
        return ans