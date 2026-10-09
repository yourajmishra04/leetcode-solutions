class Solution:
    def firstMissingPositive(self, nums: list[int]) -> int:
        n=len(nums)
        i=0
        s=set(nums)
        cnt=1
        while cnt in s:
            cnt+=1
        return cnt