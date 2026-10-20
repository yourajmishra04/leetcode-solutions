class Solution:
    def largestOddNumber(self, num: str) -> str:
        s=""
        n=len(num)
        flg=False
        for i in range(n-1 , -1 ,-1):
            if int(num[i])%2==1:
                flg=True
            if flg==True :
                s+=num[i]
        ss=s[::-1]
        return ss
