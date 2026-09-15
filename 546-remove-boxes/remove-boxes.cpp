class Solution {
public:
    int dp[100][100][100];

    int solve(vector<int>& boxes, int l, int r, int k) {
        if (l > r)
            return 0;
        while (l < r && boxes[r] == boxes[r - 1]) {
            r--;
            k++;
        }

        if (dp[l][r][k] != -1)
            return dp[l][r][k];
        int ans = solve(boxes, l, r - 1, 0)
                + (k + 1) * (k + 1);
        for (int i = l; i < r; i++) {
            if (boxes[i] == boxes[r]) {
                ans = max(
                    ans,
                    solve(boxes, l, i, k + 1)
                    + solve(boxes, i + 1, r - 1, 0)
                );
            }
        }

        return dp[l][r][k] = ans;
    }

    int removeBoxes(vector<int>& boxes) {
        memset(dp, -1, sizeof(dp));

        return solve(boxes, 0, boxes.size() - 1, 0);
    }
};