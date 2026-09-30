class Solution:
    def maxDepthAfterSplit(self, seq: str) -> list[int]:
       n = len(seq)
       ans = [0]*n
       st=[]
       for i in range(n):
        if seq[i] == '(':
             st.append(i)
             continue 
        else :
          k=len(st)
          t=0

          if(k%2==0): t=1
          
          ans[i]=t
          ans[st[-1]]=t
          st.pop()
        

       return ans


        