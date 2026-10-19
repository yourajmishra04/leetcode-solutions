class Solution:
    def minDeletions(self, s: str) -> int:
        mp={}
        for ch in s:
            mp[ch]=mp.get(ch,0)+1
        v=[]
        for vv ,f in mp.items():
            v.append(f)
        v.sort(reverse=True)
        ans=0
        n=len(v)
        for i in range (1,n) :
            if v[i]<v[i-1] :
                continue
            else :
                k=v[i-1]-1
                if k<0:
                    ans+=v[i]
                    v[i]=0
                    continue
                ans+=v[i]-k
                v[i]=k
        return ans