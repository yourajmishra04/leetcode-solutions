class Solution:
    def calPoints(self, operations: list[str]) -> int:
        v=[]
        for x in operations:
          if x=="C":
             v.pop()
          elif x=="+":
             a=v[-1]
             v.pop()
             b=a+v[-1]
             v.append(a)
             v.append(b)
          elif x=="D":
             v.append(2*v[-1])
          else:
             v.append(int(x))
        ans=0
        while len(v)>0:
            ans+=v[-1]
            v.pop()
        return ans
        