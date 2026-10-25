class Solution:
    def constructArray(self, n: int, k: int) -> list[int]:
        v=[]
        l=1
        r=n
        flg=True
        while k>0:
            if flg:
                flg=False
                v.append(l)
                l+=1
            else:
                flg=True
                v.append(r)
                r-=1
            k-=1
        if flg:
            while r>=l:
                v.append(r)
                r-=1
        else:
            while l<=r:
                v.append(l)
                l+=1
        return v
