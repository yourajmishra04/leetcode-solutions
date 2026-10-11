class Solution:
    def checkIfCanBreak(self, s1: str, s2: str) -> bool:
        s1=sorted(s1)
        s2=sorted(s2)
        flg=0
        n=len(s1)
        for i in range (n):
            if s1[i]< s2[i] :
                flg=1
        if flg ==0 :
            return True
        flg=0
        for i in range (n):
            if s2[i]< s1[i] :
                flg=1
        if flg ==0 :
            return True
        return False
