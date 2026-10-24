from collections import Counter
import heapq


class Solution:
    def isNStraightHand(self, hand: list[int], groupSize: int) -> bool:
        n = len(hand)
        if n % groupSize != 0:
            return False
        fre = Counter(hand)
        heapq.heapify(hand)
        while hand:
            num = heapq.heappop(hand)
            if fre[num] < 1:
                continue
            for i in range(groupSize):
                if fre[num] < 1:
                    return False
                fre[num] = fre.get(num, 0) - 1
                num += 1
        for val, f in fre.items():
            if f > 0:
                return False
        return True
