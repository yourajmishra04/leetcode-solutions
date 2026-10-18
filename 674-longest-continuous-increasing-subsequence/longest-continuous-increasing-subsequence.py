class Solution:
    def findLengthOfLCIS(self, nums: list[int]) -> int:
        n=len(nums)
        i=0
        ans=0
        while i<n :
            j=i+1
            while j< n and nums[j]>nums[j-1]:
                j+=1
            ans=max(ans,j-i)
            i=j
        return ans