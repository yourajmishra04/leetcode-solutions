class Solution:
    def thirdMax(self, nums: list[int]) -> int:
        nums.sort()
        st=[]
        st.append(nums[0])
        n=len(nums)
        for i in range(n):
           if nums[i] == st[-1] :
             continue
           else : st.append(nums[i])

        if len(st)<3 : 
          return nums[n-1]

        return st[-3]