class Solution:
    def minMovesToSeat(self, seats: list[int], students: list[int]) -> int:
        seats.sort()
        students.sort()
        n=len(seats)
        ans=0
        for i in range (n):
            ans+=abs(seats[i]-students[i])
        return ans