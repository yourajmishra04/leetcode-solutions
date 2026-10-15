class Solution:
    def dominantIndex(self, nums: list[int]) -> int:
        arr=nums.copy()
        n=len(nums)
        arr.sort(reverse=True)
        if arr[0]< 2*arr[1] :
            return -1
        for i in range (n):
            if nums[i]==arr[0] :
                return i
        return -1
