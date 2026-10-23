from typing import List


class Solution:
    dp = []
    maxi = float("-inf")

    def solve(self, i: int, j: int, grid: list[list[int]]) -> int:
        x = len(grid)
        y = len(grid[0])
        if j == y - 1:
            return 0
        if self.dp[i][j] != -1:
            return self.dp[i][j]
        ans = 0
        prev = grid[i][j]

        if j + 1 < y and grid[i][j + 1] > prev:
            ans = max(ans, 1 + self.solve(i, j + 1, grid))
        if j+1<y and i + 1 < x and grid[i + 1][j + 1] > prev:
                ans = max(ans, 1 + self.solve(i + 1, j + 1, grid))
        if j+1<y and i - 1 >= 0 and  grid[i - 1][j + 1] > prev:
                ans = max(ans, 1 + self.solve(i - 1, j + 1, grid))
        self.dp[i][j] = ans
        return ans

    def maxMoves(self, grid: List[List[int]]) -> int:
        x = len(grid)
        y = len(grid[0])
        self.dp = [[-1] * y for _ in range(x)]
        fans = 0
        for i in range(x):
            fans = max(fans, self.solve(i, 0, grid))
        return fans
