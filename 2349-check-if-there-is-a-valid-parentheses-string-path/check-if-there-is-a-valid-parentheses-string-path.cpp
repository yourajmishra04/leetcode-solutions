class Solution {
public:
    int n, m;
    vector<vector<vector<int>>> dp;

    bool solve(vector<vector<char>>& grid, int i, int j, int balance) {

        if (i >= n || j >= m)
            return false;
        if (grid[i][j] == '(')
            balance++;
        else
            balance--;

        if (balance < 0)
            return false;
        int remaining = (n - 1 - i) + (m - 1 - j);

        if (balance > remaining)
            return false;

        if (i == n - 1 && j == m - 1)
            return balance == 0;
        if (dp[i][j][balance] != -1)
            return dp[i][j][balance];

        return dp[i][j][balance] = solve(grid, i + 1, j, balance) ||
                                   solve(grid, i, j + 1, balance);
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        if ((n + m - 1) % 2 != 0)
            return false;

        if (grid[0][0] == ')')
            return false;
        dp.assign(n, vector<vector<int>>(m, vector<int>(n + m + 1, -1)));
        return solve(grid, 0, 0, 0);
    }
};