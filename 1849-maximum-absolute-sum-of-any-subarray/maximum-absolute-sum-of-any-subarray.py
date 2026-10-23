class Solution:
    def maxAbsoluteSum(self, nums: list[int]) -> int:
        n=len(nums)
        mxsum=0
        mnsum=0
        currmx=0
        currmn=0
        for i in range (n):
           currmx=max(nums[i],currmx+nums[i])
           currmn=min(nums[i],currmn+nums[i])
           mxsum=max(mxsum,currmx)
           mnsum=min(mnsum,currmn)
        return max(mxsum,abs(mnsum))