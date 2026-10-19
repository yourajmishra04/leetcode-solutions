from collections import Counter

class Solution:
    def isPossible(self, nums: list[int]) -> bool:
        mp = Counter(nums)
        need = Counter()

        for x in nums:
            if mp[x] == 0:
                continue

            if need[x] > 0:
                need[x] -= 1
                need[x + 1] += 1

            elif mp[x + 1] > 0 and mp[x + 2] > 0:
                mp[x + 1] -= 1
                mp[x + 2] -= 1
                need[x + 3] += 1

            else:
                return False

            mp[x] -= 1

        return True