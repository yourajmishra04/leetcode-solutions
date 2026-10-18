class Solution:
    def minSetSize(self, arr: list[int]) -> int:
        n=len(arr)
        fre={}
        for i in range (n):
            fre[arr[i]]=fre.get(arr[i],0)+1
        v=[]
        for k , f in fre.items():
            v.append(f)
        v.sort(reverse=True)
        tot=0
        idx=0
        ans=0
        while tot < n/2 :
            tot+=v[idx]
            idx+=1
            ans+=1
        return ans
